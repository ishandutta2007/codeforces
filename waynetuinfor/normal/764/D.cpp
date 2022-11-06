#include <iostream>

int N, x1, y1, x2, y2;

int main() {
  std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
  std::cin >> N;
  std::cout << "YES\n";
  for (int i = 0; i < N; ++i) {
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cout << ((12 + 2 * (x1 % 2) + (y1 % 2)) % 4) + 1 << '\n';
  }
  return 0;
}