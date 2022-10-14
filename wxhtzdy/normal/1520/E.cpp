/**
 *    author:  milos
 *    created: 25.04.2021 09:24:34
**/
#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long n;
  cin >> n;
  string str;
  cin >> str;
  vector<int> pos;
  for (int i = 0; i < n; i++) {
    if (str[i] == '*') {
      pos.push_back(i);
    }
  }
  int m = (int) pos.size();
  if (m <= 1) {
    cout << 0 << '\n';
    return;
  }
  vector<long long> pref(m);
  for (int i = 0; i < m; i++) {
    if (i == 0) {
      pref[i] = pos[i];
    } else {
      pref[i] = pref[i - 1] + pos[i];
    }
  }
  long long res = n * 1LL * n;
  long long t = m * 1LL * (m - 1) / 2;
  for (int i = 0; i < n; i++) {
    if (i <= pos[0]) {
      res = min(res, pref[m - 1] - (i * 1LL * m + t));
      continue;
    }
    if (i >= pos[m - 1]) {
      res = min(res, (i * 1LL * m + t) - pref[m - 1]);
      continue;
    }
    int bot = 0, top = m - 1, ans = 0;
    while (bot <= top) {
      int mid = bot + top >> 1;
      if (pos[mid] <= i + mid) {
        ans = mid;
        bot = mid + 1;
      } else {
        top = mid - 1;
      }
    }
    long long l = i * 1LL * (ans + 1) + ans * 1LL * (ans + 1) / 2;
    long long r = i * 1LL * (m - ans - 1) + t - ans * 1LL * (ans + 1) / 2;
    res = min(res, l - pref[ans] + (pref[m - 1] - pref[ans]) - r);
  }
  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin >> test;
  while (test-- > 0) {
    solve();
  }
  return 0;
}