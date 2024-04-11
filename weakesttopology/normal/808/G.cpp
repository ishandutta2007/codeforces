#include <bits/stdc++.h>

template <typename Iterator>
std::vector<int> prefix_function(Iterator first, Iterator last) {
  int N = last - first;
  std::vector<int> p(N + 1, 0);
  for (int len = 2; len <= N; ++len) {
    int x = p[len - 1];
    while (x && first[len - 1] != first[x]) x = p[x];
    if (first[len - 1] == first[x]) ++x;
    p[len] = x;
  }
  return p;
}

constexpr int K = 26, inf = std::numeric_limits<int>::max();

std::vector<std::array<int, K>> build_automaton(const std::string& S) {
  auto p = prefix_function(S.begin(), S.end());
  int N = S.size();
  std::vector<std::array<int, K>> go(N + 1);
  go[0][S[0] - 'a'] = 1;
  for (int len = 1; len <= N; ++len) {
    go[len] = go[p[len]];
    if (len < N) {
      go[len][S[len] - 'a'] = len + 1;
    }
  }
  return go;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string S, T;
  std::cin >> S >> T;
  auto go = build_automaton(T);
  int N = T.size();
  std::vector<int> dp(N + 1, -inf);
  dp[0] = 0;
  for (auto c : S) {
    std::vector<int> ndp(N + 1, -inf);
    if (c != '?') {
      c -= 'a';
      for (int u = 0; u <= N; ++u) {
        int v = go[u][c];
        ndp[v] = std::max(ndp[v], dp[u] + (v == N));
      }
    } else {
      for (int u = 0; u <= N; ++u) {
        for (auto v : go[u]) {
          ndp[v] = std::max(ndp[v], dp[u] + (v == N));
        }
      }
    }
    std::swap(dp, ndp);
  }
  std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';
  exit(0);
}