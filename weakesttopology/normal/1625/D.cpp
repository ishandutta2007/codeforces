#include <bits/stdc++.h>

constexpr int L = 30;
struct Trie {
  struct Node {
    Node* go[2];
    int i, value;
    Node() : go{}, i(-1), value(0) {}
  };
  std::deque<Node> tr;
  Trie() : tr(1) {}
  std::pair<int, int> compute(std::bitset<L> v, std::bitset<L> K) const {
    const Node* node = &tr[0];
    int i = -1, value = 0;
    for (int l = L - 1; l >= 0 && node; --l) {
      int x = v[l] ^ K[l] ^ 1;
      if (!K[l] && node->go[x] && node->go[x]->value > value) {
        i = node->go[x]->i;
        value = node->go[x]->value;
      }
      node = node->go[x ^ 1];
    }
    return {i, value};
  }
  void insert(std::bitset<L> v, int i, int value) {
    Node* node = &tr[0];
    for (int l = L - 1; l >= 0; --l) {
      int x = v[l];
      if (!node->go[x]) {
        node->go[x] = &tr.emplace_back();
      }
      node = node->go[x];
      if (value > node->value) {
        node->i = i;
        node->value = value;
      }
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, K;
  std::cin >> N >> K;
  if (K == 0) {
    std::cout << N << '\n';
    for (int i = 0; i < N; ++i) {
      std::cout << i + 1 << ' ';
    }
    std::cout << '\n';
    exit(0);
  }
  --K;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }
  std::vector<int> p(N, -1);
  std::vector<int> I(N);
  std::iota(I.begin(), I.end(), 0);
  std::sort(I.begin(), I.end(), [&](int i, int j) { return a[i] < a[j]; });
  std::vector<int> dp(N);
  Trie trie;
  int opt = -1;
  for (auto i : I) {
    auto [j, value] = trie.compute(a[i], K);
    dp[i] = value + 1;
    p[i] = j;
    if (opt == -1 || dp[opt] < dp[i]) {
      opt = i;
    }
    trie.insert(a[i], i, dp[i]);

  }
  if (dp[opt] == 1) {
    std::cout << -1 << '\n';
  } else {
    std::cout << dp[opt] << '\n';
    for (int i = opt; i != -1; i = p[i]) {
      std::cout << i + 1 << ' ';
    }
    std::cout << '\n';
  }
  exit(0);
}