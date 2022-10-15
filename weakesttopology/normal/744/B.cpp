#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<int> ans(N, std::numeric_limits<int>::max());
  int cnt = 0;
  auto query = [&](std::vector<int> w) {
    ++cnt;
    int K = w.size();
    if (K == 0) return;
    std::cout << K << '\n';
    std::vector<bool> on(N);
    for (int j = 0; j < K; ++j) {
      std::cout << w[j] + 1 << "\n "[j + 1 < K];
      on[w[j]] = true;
    }
    std::cout << std::flush;
    for (int i = 0; i < N; ++i) {
      int x;
      std::cin >> x;
      if (!on[i]) {
        ans[i] = std::min(ans[i], x);
      }
    }
  };
  std::vector<int> I = {0};
  int R = 1;
  while (R < N) R *= 2;
  while (R > 1) {
    std::vector<int> nI;
    R /= 2;
    std::vector<int> w[2];
    for (int i : I) {
      for (int add = 0; add < R; ++add) {
        for (int t : {0, 1}) {
          int j = i + t * R + add;
          if (j < N) {
            w[t].push_back(j);
          }
        }
      }
      nI.push_back(i);
      nI.push_back(i + R);
    }
    for (int t : {0, 1}) {
      query(w[t]);
    }
    std::swap(I, nI);
  }
  std::cout << "-1\n";
  for (int i = 0; i < N; ++i) {
    std::cout << ans[i] << "\n "[i + 1 < N];
  }
  std::cout << std::flush;
  std::cerr << "cnt == " << cnt << std::endl;
  exit(0);
}