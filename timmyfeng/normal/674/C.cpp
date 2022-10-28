#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;
const int K = 50;

struct convex_hull_trick {

  double intersect(array<double, 2> f, array<double, 2> g) {
    return (g[1] - f[1]) / (f[0] - g[0]);
  }

  double evaluate(array<double, 2> f, double x) {
    return f[0] * x + f[1];
  }

  deque<array<double, 2>> lines;

  void update(double m, double b) {
    array<double, 2> nxt = {m, b};
    while (lines.size() >= 2) {
      array<double, 2> prv = lines[lines.size() - 2];
      array<double, 2> cur = lines.back();
      if (intersect(prv, cur) > intersect(cur, nxt)) {
        break;
      }
      lines.pop_back();
    }
    lines.push_back(nxt);
  }

  double query(double x) {
    while (lines.size() >= 2) {
      if (evaluate(lines[0], x) < evaluate(lines[1], x)) {
        break;
      }
      lines.pop_front();
    }
    return evaluate(lines.front(), x);
  }

} hull[K];

double t[N], prefix[N], suffix[N], expected[N][K];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(6);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  double ans = 0.0, offset = 0.0;
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + t[i];
    ans += prefix[i + 1] / t[i];
  }

  for (int i = n - 1; i >= 0; --i) {
    suffix[i] = suffix[i + 1] + 1.0 / t[i];
  }

  hull[0].update(prefix[0], expected[0][0]);
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= i && j < k; ++j) {
      expected[i][j] = expected[i - 1][j];
      if (j) {
        expected[i][j] = min(expected[i][j],
            hull[j - 1].query(suffix[i]) - prefix[i] * suffix[i]
        );
      }
      hull[j].update(prefix[i], expected[i][j]);
      offset = min(offset, expected[i][j]);
    }
  }

  cout << ans + offset << "\n";
}