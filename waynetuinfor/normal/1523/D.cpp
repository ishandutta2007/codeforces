#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int N, M, P;
  std::cin >> N >> M >> P;
  std::vector<uint64_t> mask(N);
  for (int i = 0; i < N; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < M; ++j) {
      if (s[j] == '1') mask[i] ^= (1ULL << j);
    }
  }
  auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  std::mt19937 rng(seed);
  std::uniform_int_distribution<int> dis(0, N - 1);
  constexpr int kIter = 50;
  uint64_t best = 0;
  for (int it = 0; it < kIter; ++it) {
    int p = dis(rng);
    std::vector<int> bits;
    bits.reserve(P);
    for (int bit = 0; bit < M; ++bit) {
      if (mask[p] >> bit & 1) bits.push_back(bit); 
    }
    const int K = bits.size();
    std::vector<int> cnt(1 << K);
    for (int i = 0; i < N; ++i) {
      int k = 0;
      for (int j = 0; j < K; ++j) {
        if (mask[i] >> bits[j] & 1) k ^= (1 << j);
      }
      cnt[k]++;
    }
    for (int i = 0; i < K; ++i) {
      for (int j = 0; j < (1 << K); ++j) {
        if ((j >> i & 1) == 0) cnt[j] += cnt[j ^ (1 << i)];
      }
    }
    for (int i = 0; i < (1 << K); ++i) {
      if (cnt[i] >= (N + 1) / 2) {
        uint64_t cur = 0;
        for (int j = 0; j < K; ++j) {
          if (i >> j & 1) cur ^= (1ULL << bits[j]);
        }
        if (__builtin_popcountll(cur) > __builtin_popcountll(best)) {
          best = cur;
        }
      }
    }
  }
  for (int i = 0; i < M; ++i) std::cout << (best >> i & 1);
  std::cout << "\n";
  return 0;
}