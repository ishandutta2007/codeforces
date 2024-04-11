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

const int C = 3;

string solve(string &s1, string &s2) {
  int n = SZ(s1) / 2;
  vector<int> cnt1(2 * n + 1), cnt2(2 * n + 1);
  int mx = 0;
  for (int i = 0; i < 2; i++) {
    int lst = -1, was = 0;
    for (int j = 0; j < SZ(s1); j++) {
      if (s1[j] == '1') {
        cnt1[was++] = j - lst - 1;
        lst = j;
      }
    }
    cnt1[was] = SZ(s1) - lst - 1;
    mx = max(mx, was);
    swap(s1, s2);
    swap(cnt1, cnt2);
  }
  string result;
  for (int i = 0; i <= mx; i++) {
    for (int j = 0; j < max(cnt1[i], cnt2[i]); j++) {
      result.pb('0');
    }
    if (i < mx) {
      result.pb('1');
    }
  }
  return result;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> s(C);
    vector<int> cnt(C);
    for (int i = 0; i < C; i++) {
      cin >> s[i];
      for (auto &it : s[i]) {
        cnt[i] += (it == '1');
      }
    }
    bool inv = false;
    if ((cnt[0] >= n) + (cnt[1] >= n) + (cnt[2] >= n) < 2) {
      inv = true;
      for (int i = 0; i < C; i++) {
        cnt[i] = SZ(s[i]) - cnt[i];
        for (auto &it : s[i]) {
          it ^= 1;
        }
      } 
    }
    vector<pair<int, int>> order;
    for (int i = 0; i < C; i++) {
      order.pb({cnt[i], i});
    }
    sort(order.rbegin(), order.rend());
    auto result = solve(s[order[0].S], s[order[1].S]);
    if (inv) {
      for (auto &it : result) {
        it ^= 1;
      }
    }
    cout << result << '\n';
  }
}