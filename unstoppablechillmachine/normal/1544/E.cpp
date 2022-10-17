#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int ALPHA = 26;
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    vector<int> cnt(ALPHA, 0);
    for (auto it : s) {
      cnt[it - 'a']++;
    }
    int id = -1, diff = 0, fst = -1;
    vector<int> kek;
    for (int i = 0; i < ALPHA; i++) {
      if (cnt[i] == 1) {
        id = i;
        break;
      }
      if (cnt[i] > 0) {
        kek.pb(i);
        diff++;
        if (fst == -1) {
          fst = i;
        }
      }
    }
    if (id != -1) {
      cout << char('a' + id);
      cnt[id]--;
      for (int i = 0; i < ALPHA; i++) {
        for (int j = 0; j < cnt[i]; j++) {
          cout << char('a' + i);
        }
      }
      cout << '\n';  
      continue;
    }
    if (diff == 1) {
      for (int i = 0; i < ALPHA; i++) {
        for (int j = 0; j < cnt[i]; j++) {
          cout << char('a' + i);
        }
      }
      cout << '\n';  
      continue; 
    }
    //now answer is 1

    //first case
    int n = SZ(s);
    if (2 * (cnt[fst] - 2) <= n - 2) {
      bool prv_fst = true;
      cout << char('a' + fst) << char('a' + fst); 
      cnt[fst] -= 2;
      for (int i = 0; i < n - 2; i++) {
        int mn = -1;
        if (prv_fst) {
          for (int j = fst + 1; j < ALPHA; j++) {
            if (cnt[j] > 0) {
              mn = j;
              break;
            }
          }
        } else {
          for (int j = fst; j < ALPHA; j++) {
            if (cnt[j] > 0) {
              mn = j;
              break;
            }
          }
        }
        assert(mn != -1);
        cnt[mn]--;
        prv_fst = (mn == fst);
        cout << char('a' + mn);
      }
      cout << '\n';
      continue;
    }  

    //second case
    if (diff >= 3) {
      cout << char('a' + kek[0]);
      cnt[kek[0]]--;
      cout << char('a' + kek[1]);
      cnt[kek[1]]--;
      while (cnt[kek[0]]) {
        cout << char('a' + kek[0]);
        cnt[kek[0]]--;
      }
      cout << char('a' + kek[2]);
      cnt[kek[2]]--;
      for (int i = 0; i < ALPHA; i++) {
        for (int j = 0; j < cnt[i]; j++) {
          cout << char('a' + i);
        }
      }
      cout << '\n';  
      continue;  
    }

    //third case
    assert(diff == 2);
    cout << char('a' + kek[0]);
    cnt[kek[0]]--;
    while (cnt[kek[1]]) {
      cout << char('a' + kek[1]);
      cnt[kek[1]]--;
    }
    while (cnt[kek[0]]) {
      cout << char('a' + kek[0]);
      cnt[kek[0]]--;
    }
    cout << '\n';
  }
}