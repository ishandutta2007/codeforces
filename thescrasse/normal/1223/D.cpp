#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, x, f[300010], l[300010], s[300010], dp[300010];
vector<pair<long long, long long>> a;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    a.clear();
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> x;
      a.push_back({x, i});
    }
    sort(a.begin(), a.end());
    for (i = 0; i < n; i++) {
      if (i != 0) {
        if (a[i].first == a[i - 1].first) {
          s[a[i].second] = s[a[i - 1].second];
        } else {
          s[a[i].second] = s[a[i - 1].second] + 1;
        }
      } else {
        s[a[i].second] = 0;
      }
    }
    for (i = 0; i <= s[a[n - 1].second]; i++) {
      f[i] = -1;
      l[i] = -1;
    }
    for (i = 0; i < n; i++) {
      if (f[s[i]] == -1) {
        f[s[i]] = i;
      }
      l[s[i]] = i;
    }

    res = 1;
    dp[s[a[n - 1].second]] = 1;
    for (i = s[a[n - 1].second] - 1; i >= 0; i--) {
      if (l[i] < f[i + 1]) {
        dp[i] = dp[i + 1] + 1;
        res = max(dp[i], res);
      } else {
        dp[i] = 1;
      }
    }

    res = s[a[n - 1].second] - res + 1;

    cout << res << endl;
  }

  return 0;
}