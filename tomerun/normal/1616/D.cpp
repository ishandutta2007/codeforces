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
array<int, 50000> A;
int X;

int solve() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  cin >> X;
  int ans = 0;
  int pos = 0;
  while (pos < N) {
    ans++;
    int64_t sum = A[pos] - X;
    pos++;
    int64_t pmax = 0;
    while (pos < N) {
      int64_t nsum = sum + A[pos] - X;
      if (nsum < pmax) {
        break;
      }
      pmax = max(pmax, sum);
      sum = nsum;
      ans++;
      pos++;
    }
    pos++;
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