#include <bits/stdc++.h>

constexpr int N = 5000, D = 5000;
int min[N + 1], max[N + 1];

bool can(int n, int d) {
  return min[n] <= d && d <= max[n];
}

std::vector<int> solve(int n, int d) {
  assert(can(n, d));
  d -= n - 1;
  int nl = 0, nr = n - 1;
  while (!(min[nl] + min[nr] <= d && d <= max[nl] + max[nr])) {
    ++nl;
    --nr;
    assert(nr >= 0);
  }
  int dl = 0, dr = d;
  while (!(can(nl, dl) && can(nr, dr))) {
    ++dl;
    --dr;
    assert(dr >= 0);
  }
  std::vector<int> p;
  if (nl) {
    auto pl = solve(nl, dl);
    for (auto& v : pl) {
      v += 1;
    }
    p.push_back(0);
    p.insert(p.end(), pl.begin(), pl.end());
  }
  if (nr) {
    auto pr = solve(nr, dr);
    for (auto& v : pr) {
      v += 1 + nl;
    }
    p.push_back(0);
    p.insert(p.end(), pr.begin(), pr.end());
  }
  assert(p.size() == n - 1);
  return p;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  for (int n = 2; n <= N; ++n) {
    min[n] = std::numeric_limits<int>::max();
    for (int k = 1; k < n; ++k) {
      min[n] = std::min(min[n], n - 1 + min[k] + min[n - 1 - k]);
    }
    max[n] = std::min(n * (n - 1) / 2, D);
  }
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, d;
    std::cin >> n >> d;
    if (!can(n, d)) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      auto p = solve(n, d);
      for (auto v : p) {
        std::cout << v + 1 << ' ';
      }
      std::cout << '\n';
    }
  }
  exit(0);
}