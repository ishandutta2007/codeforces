#include <iostream>
#include <vector>
#include <limits>

constexpr long long inf = std::numeric_limits<long long>::max() / 2;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int Q;
    std::cin >> Q;
    for (int q = 0; q < Q; ++q) {
      int N;
      std::cin >> N;

      std::vector<long long> a(N);
      for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
      }
      std::sort(a.begin(), a.end());
      std::reverse(a.begin(), a.end());

      std::vector<long long> dp(N + 1, -inf);
      dp[0] = 0;

      for (auto x : a) {
        int l = -1;
        for (; l + 2 <= N && dp[l + 2] + x > dp[l + 1]; ++l);

        int b = N + 1;
        for (; dp[b - 1] == -inf; --b);

        int r = b;
        for (; r - 2 >= 0 && dp[r - 2] - x > dp[r - 1]; --r);

        for (int i = 0; i <= l; ++i) {
          dp[i] = i + dp[i + 1] + x;
        }
        for (int i = std::min(b, N - 1); i >= r; --i) {
          dp[i] = i + dp[i - 1] - x;
        }
        for (int i = l + 1; i < r; ++i) {
          dp[i] += i;
        }
      }

      std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';
    }

    exit(0);
}