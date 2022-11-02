#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
constexpr int INF = 1 << 30;

int main() {
  int n, m;
  cin >> n >> m;

  //  m + 2 
  vector<int> cnt(m + 2, 0);
  while (n--) {
    int a;
    cin >> a;
    ++cnt[--a];  // 0-indexed
  }

  // 2
  auto dp = vector(7, vector(7, -INF));
  dp[0][0] = 0;

  for (auto c : cnt) {
    auto ndp = vector(7, vector(7, -INF));

    for (int p = 0; p <= 6; ++p) {
      for (int q = 0; q <= 6; ++q) {
        // 
        for (int r = 0; r <= min(c, 6); ++r) {
          for (int shuntsu = 0; shuntsu <= min({p, q, c - r}); ++shuntsu) {
            int kotsu = (c - r - shuntsu) / 3;  // 
            ndp[q - shuntsu][r] = max(ndp[q - shuntsu][r], dp[p][q] + shuntsu + kotsu);
          }
        }
      }
    }

    swap(dp, ndp);
  }

  cout << dp[0][0] << endl;
  return 0;
}