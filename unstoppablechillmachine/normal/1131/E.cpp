#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

vector<int> get(string &s) {
  vector<int> res(26, 0);
  pair<char, int> cur = {s[0], 1};
  res[cur.F - 'a'] = 1;
  for (int i = 1; i < SZ(s); i++) {
    if (s[i] == cur.F) {
      cur.S++;
    }
    else {
      cur = {s[i], 1};
    }
    res[cur.F - 'a'] = max(res[cur.F - 'a'], cur.S);
  }
  return res;
}

void source() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (auto &it : s) {
    cin >> it;
  }
  vector<int> kek = get(s[0]);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      kek[j] = min(kek[j], (int)1e9);
    }
    vector<int> cur = get(s[i]);
    if (cur[s[i][0] - 'a'] == SZ(s[i])) {
      kek[s[i][0] - 'a'] += SZ(s[i]) * (kek[s[i][0] - 'a'] + 1);
      for (int j = 0; j < 26; j++) {
        if (s[i][0] - 'a' != j) {
          kek[j] = min(kek[j], 1ll);
        }
      }
      continue;
    }
    if (s[i][0] - 'a' == s[i].back() - 'a') {
      int cnt = 0;
      for (int j = 0;; j++) {
        if (s[i][j] != s[i][0]) {
          break;
        }
        cnt++;
      }
      for (int j = SZ(s[i]) - 1; j >= 0; j--) {
        if (s[i][j] != s[i][0]) {
          break;
        }
        cnt++;
      }
      vector<int> kek2(26);
      for (int j = 0; j < 26; j++) {
        if (j == s[i][0] - 'a') {
          if (kek[j]) {
            kek2[j] = max(cur[j], cnt + 1);
          }
          else {
            kek2[j] = cur[j];
          }
        }
        else {
          kek2[j] = cur[j];
          if (kek2[j] == 0 && kek[j] > 0) {
            kek2[j] = 1;
          }
        }
      }
      kek = kek2;
    }
    else {
      int cnt1 = 0, cnt2 = 0;
      for (int j = 0;; j++) {
        if (s[i][j] != s[i][0]) {
          break;
        }
        cnt1++;
      }
      for (int j = SZ(s[i]) - 1;; j--) {
        if (s[i][j] != s[i].back()) {
          break;
        }
        cnt2++;
      }
      vector<int> kek2(26);
      for (int j = 0; j < 26; j++) {
        if (j == s[i][0] - 'a') {
          kek2[j] = cur[j];
          if (kek[j]) {
            kek2[j] = max(kek2[j], cnt1 + 1);
          }
        }
        else if (j == s[i].back() - 'a') {
          kek2[j] = cur[j];
          if (kek[j]) {
            kek2[j] = max(kek2[j], cnt2 + 1);
          }
        }
        else {
          kek2[j] = cur[j];
          if (kek2[j] == 0 && kek[j]) {
            kek2[j] = 1;
          }
        }
      }
      kek = kek2;
    }
    for (int j = 0; j < 26; j++) {
      kek[j] = min(kek[j], (int)1e9);
    }
  }
  int ans = 0;
  for (auto it : kek) {
    ans = max(ans, it);
  }
  cout << ans;
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}