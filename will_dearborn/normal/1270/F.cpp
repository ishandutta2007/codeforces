#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

int w[41000000];

ll solve(string s) {
  int n = s.size();
  vi v;
  vi c(n + 1);
  for (int i = 0; i < n; ++i) {
    c[i + 1] = c[i] + s[i] - '0';
    if (s[i] == '1') v.push_back(i);
  }
  ll res = 0;
  const int M = 1000;
  const int D = 200;
  for (int k = 1; k <= min(M, (int)v.size()); ++k) {
    for (int l = 0; l + k <= v.size(); ++l) {
      int len = v[l + k - 1] - v[l] + 1;
      int l1 = (l == 0) ? v[l] + 1 : v[l] - v[l - 1];
      int l2 = (l + k == v.size()) ? n - v[l + k - 1] : v[l + k] - v[l + k - 1];
      res += l1 * (ll)(l2 / k);
      l2 %= k;
      res += l2 * (ll)(l1 / k);
      l1 %= k;
      if (l1 > l2) swap(l1, l2);
      int r = ((-len) % k + k) % k;
      if (l1 <= r) {
        res += min(l1, max(0, min(l2, r + 1) - (r - l1 + 1)));
      } else {
        res += r + 1;
        l1 -= r;
        l2 -= r;
        int r1 = k - r;
        res += min(l1, max(0, min(l2, r1 + 1) - (r1 - l1 + 1)));
      }
    }
  }
  for (int d = 1; d <= D; ++d) {
    int l = 0;
    for (int r = 1; r <= n; ++r) {
      while (l < r && c[r] - c[l] > M) {
        w[n + c[l] * d - l]++;
        ++l;
      }
      res += w[n + c[r] * d - r];
    }
    for (int l = 0; l <= n; ++l) {
      w[n + c[l] * d - l] = 0;
    }
  }
  return res;
}

ll stupid(string s) {
  int n = s.size();
  vi v;
  vi c(n + 1);
  for (int i = 0; i < n; ++i) {
    c[i + 1] = c[i] + s[i] - '0';
    if (s[i] == '1') v.push_back(i);
  }
  ll res = 0;
  for (int l = 0; l < n; ++l) for (int r = l + 1; r <= n; ++r) {
    if (c[r] > c[l] && (r - l) % (c[r] - c[l]) == 0) ++res;
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (0) for (int n = 1; n <= 10; ++n) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      string s(n, '0');
      for (int i = 0; i < n; ++i) if (mask & (1 << i)) s[i] = '1';
      assert(solve(s) == stupid(s));
    }
  }
  string s;
  while (cin >> s) {
    cout << solve(s) << endl;
  }
  return 0;
}