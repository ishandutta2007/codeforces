#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
#include <array>
#include <numeric>
#include <memory>
#include <random>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;
using vi = vector<int>;

int N;
array<int, 100> A;

int solve() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  if (N <= 2) return 0;
  int ans = N - 2;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      double slope = (A[j] - A[i]) * 1.0 / (j - i);
      double y0 = A[i] - slope * i;
      int cnt = 0;
      for (int k = 0; k < N; ++k) {
        if (k == i || k == j) continue;
        double y = y0 + slope * k;
        if (abs(A[k] - y) > 1e-6) cnt++;
      }
      ans = min(ans, cnt);
    }
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    auto ans = solve();
    cout << ans << endl;
  }
}