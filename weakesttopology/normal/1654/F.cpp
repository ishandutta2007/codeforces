#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::string S;
  std::cin >> S;
  std::vector<int> p(1 << N);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(), [&](int i, int j) { return S[i] < S[j]; });
  std::vector<int> rank(1 << N), tmp(1 << N);
  for (int i = 1; i < (1 << N); ++i) {
    rank[p[i]] = rank[p[i - 1]] + (S[p[i]] != S[p[i - 1]]);
  }
  for (int k = 0; k < N; ++k) {
    auto key = [&](int j) {
      return std::pair(rank[j], rank[j ^ (1 << k)]);
    };
    std::sort(p.begin(), p.end(), [&](int i, int j) { return key(i) < key(j); });
    tmp[p[0]] = 0;
    for (int i = 1; i < (1 << N); ++i) {
      tmp[p[i]] = tmp[p[i - 1]] + (key(p[i - 1]) != key(p[i]));
    }
    std::swap(tmp, rank);
  }
  std::string T(1 << N, '*');
  for (int i = 0; i < (1 << N); ++i) {
    T[i] = S[i ^ p[0]];
  }
  std::cout << T << '\n';
  exit(0);
}