#include <iostream>

const int maxn = 200000 + 5;
int A[maxn], n, rem;

int main() {
  std::ios_base::sync_with_stdio(false); std::cin.tie(0);
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> A[i];
  for (int i = 0; i < n; ++i) {
    if (rem) --A[i];
    if (A[i] < 0) { std::cout << "NO\n"; return 0; }
    rem = A[i] % 2;
  }
  if (rem) std::cout << "NO\n";
  else std::cout << "YES\n";
  return 0;
}