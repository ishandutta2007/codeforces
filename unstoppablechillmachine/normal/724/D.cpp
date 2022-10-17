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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int m;
  cin >> m;
  string s;
  cin >> s;
  vector<int> was(26);
  for (auto it : s) {
    was[it - 'a']++;
  }
  pair<int, int> lol;
  for (int i = 0; i < 26; i++) {
    vector<bool> used(SZ(s));
    vector<int> nxt_can(SZ(s));
    nxt_can[SZ(s) - 1] = 1e9;
    int kek = 1e9;
    for (int j = SZ(s) - 1; j >= 0; j--) {
      if (s[j] - 'a' < i) {
        used[j] = true;
      }
      nxt_can[j] = kek;
      if (s[j] - 'a' <= i) {
        kek = j;
      }
    }
    int cnt = 0, ptr = 0;
    int lst = -1;
    bool ok = true;
    for (int j = 0; j < SZ(s); j++) {
      if (used[j]) {
        lst = j;
        if (SZ(s) - 1 - lst <= m) {
          break;
        }
      }
      else if (s[j] - 'a' == i && nxt_can[j] - lst > m) {
        cnt++;
        lst = j;
        ptr++;
        if (SZ(s) - 1 - lst <= m) {
          break;
        }
      }
      else if (j - lst >= m) {
        ok = false;
      }
    }
    if (ok) {
      lol = {i, cnt};
      break;
    }
  }
  for (int i = 0; i < lol.F; i++) {
    for (int j = 0; j < was[i]; j++) {
      cout << char('a' + i);
    }
  }
  for (int j = 0; j < lol.S; j++) {
    cout << char('a' + lol.F);
  }
  cout << '\n';
}