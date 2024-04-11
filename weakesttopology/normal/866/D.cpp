#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<int> p(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> p[i];
  }
  std::priority_queue<int> pq;
  int64_t ans = 0;
  for (int i = 0; i < N; ++i) {
    pq.push(-p[i]);
    if (-pq.top() < p[i]) {
      ans += p[i] + pq.top();
      pq.pop();
      pq.push(-p[i]);
    }
  }
  std::cout << ans << '\n';
  exit(0);
}