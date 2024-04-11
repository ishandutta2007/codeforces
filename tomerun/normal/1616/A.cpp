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
  vi cnt = vi(101, 0);
  int A;
  for (int i = 0; i < N; ++i) {
    cin >> A;
    cnt[abs(A)]++;
  }
  int ans = cnt[0] == 0 ? 0 : 1;
  for (int i = 1; i <= 100; ++i) {
    ans += cnt[i] == 0 ? 0 : cnt[i] == 1 ? 1 : 2;
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int ans = solve();
    cout << ans << endl;
  }
}