#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  double P;
  cin >> P;
  const auto Solve = [&](int x) -> double {
    // 50%: x * (n - x) * (n - x - 1) / 2 / total
    // 0%: (n - x) * (n - x - 1) * (n - x - 2) / 6 / total
    double total = 1ll * N * (N - 1) * (N - 2) / 6;
    double ans = 1;
    ans -= 1.0 * (N - x) * (N - x - 1) * (N - x - 2) / 6 / total;
    ans -= 1.0 * x * (N - x) * (N - x - 1) / 4 / total;
    return ans;
  };
  int lo = 0, hi = N;
  while (lo < hi) {
    int md = (lo + hi) / 2;
    if (Solve(md) >= P) {
      hi = md;
    } else {
      lo = md + 1;
    }
  }
  cout << lo << '\n';
}