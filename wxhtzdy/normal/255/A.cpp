#include <bits/stdc++.h>

using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> sum(3);
  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    sum[i % 3] += x;
  }
  int id = max_element(sum.begin(), sum.end()) - sum.begin();
  std::cout << (id == 0 ? "chest" : (id == 1 ? "biceps" : "back"));
  return 0;
}