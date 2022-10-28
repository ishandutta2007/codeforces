#include <bits/stdc++.h>
using namespace std;

vector<int> factors(int x) {
  vector<int> res;
  for (int i = 2; i * i <= x; ++i) {
    int a = 0;
    while (x % i == 0) {
      x /= i;
      ++a;
    }

    if (a > 0) {
      res.push_back(i);
    }
  }
  if (x > 1) {
    res.push_back(x);
  }
  return res;
}

const int N = 1000000 + 1;

int n, a, b, p[N];
long long s[N][2];

long long solve(int k) {
  for (int i = 0; i < n; ++i) {
    s[i + 1][0] = s[i][0];
    if (s[i + 1][0] < LLONG_MAX) {
      if (p[i] % k != 0) {
        if (p[i] % k == 1 || p[i] % k == k - 1) {
          s[i + 1][0] += b;
        } else {
          s[i + 1][0] = LLONG_MAX;
        }
      }
    }
    s[i + 1][1] = min(s[i + 1][0], s[i][1] + a);
  }

  long long res = s[n][1], sum = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (p[i] % k != 0) {
      if (p[i] % k == 1 || p[i] % k == k - 1) {
        sum += b;
      } else {
        break;
      }
    }
    res = min(res, sum + s[i][1]);
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> a >> b;

  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  long long ans = LLONG_MAX;
  for (int i = -1; i <= 1; ++i) {
    for (auto j : {0, n - 1}) {
      for (auto k : factors(p[j] + i)) {
        ans = min(ans, solve(k));
      }
    }
  }

  cout << ans << "\n";
}