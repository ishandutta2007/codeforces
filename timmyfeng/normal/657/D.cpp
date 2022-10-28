#include <bits/stdc++.h>
using namespace std;

const int N = 150000;
const int L = 32;

pair<long long, double> yield[2 * N];
array<long long, 2> problem[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> problem[i][0];
  }

  long long total = 0;
  for (int i = 0; i < n; ++i) {
    cin >> problem[i][1];
    total += problem[i][1];
  }

  sort(problem, problem + n, [](array<long long, 2> a, array<long long, 2> b) {
    return a[0] * b[1] > b[0] * a[1];
  });

  double lo = 0.0, hi = 1.0;
  for (int z = 0; z < L; ++z) {
    double c = (lo + hi) / 2;

    long long prv = 0;
    for (int i = 0, j = 0; i < n; i = j) {
      long long cur = 0;
      for ( ; j < n && problem[i][0] * problem[j][1] == problem[j][0] * problem[i][1]; ++j) {
        cur += problem[j][1];
      }
      for (int k = i; k < j; ++k) {
        yield[2 * k] = {problem[k][0], problem[k][0] * (1.0 - c * (prv + problem[k][1]) / total)};
        yield[2 * k + 1] = {problem[k][0], problem[k][0] * (1.0 - c * (prv + cur) / total)};
      }
      prv += cur;
    }
    sort(yield, yield + 2 * n);

    bool ok = true;
    for (int i = 1; i < 2 * n; ++i) {
      ok &= (yield[i - 1].second <= yield[i].second);
    }

    (ok ? lo : hi) = c;
  }

  cout << lo << "\n";
}