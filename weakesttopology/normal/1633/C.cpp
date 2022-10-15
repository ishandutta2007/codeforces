#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int64_t hc, dc, hm, dm;
    std::cin >> hc >> dc >> hm >> dm;
    int K;
    int64_t w, a;
    std::cin >> K >> w >> a;
    bool good = false;
    for (int k = 0; k <= K; ++k) {
      int64_t nhc = hc + k * a;
      int64_t ndc = dc + (K - k) * w;
      int64_t rc = (nhc + dm - 1) / dm;
      int64_t rm = (hm + ndc - 1) / ndc;
      if (rc >= rm) {
        good = true;
        break;
      }
    }
    std::cout << (good ? "YES" : "NO") << '\n';
  }
  exit(0);
}