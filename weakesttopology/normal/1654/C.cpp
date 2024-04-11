#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    std::priority_queue<int64_t> pq;
    pq.push(std::accumulate(a.begin(), a.end(), 0LL));
    bool good = true;
    while (!pq.empty()) {
      int64_t w = pq.top();
      pq.pop();
      if (a.empty() || a.back() > w) {
        good = false;
        break;
      } else if (a.back() == w) {
        a.pop_back();
      } else {
        pq.push(w / 2);
        pq.push((w + 1) / 2);
      }
    }
    good = good && a.empty();
    std::cout << (good ? "YES" : "NO") << '\n';
  }
  exit(0);
}