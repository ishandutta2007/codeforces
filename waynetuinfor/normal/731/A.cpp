#include <iostream>
#include <string>
#include <algorithm>

std::string s;
int ptr, dist;

int main() {
  std::ios_base::sync_with_stdio(false); std::cin.tie(0);
  std::cin >> s;
  ptr = 0;
  for (int i = 0; i < s.length(); ++i) {
    dist += std::min({ abs(s[i] - 'a' - ptr), abs(25 - s[i] + 'a') + ptr + 1, abs(s[i] - 'a') + abs(25 - ptr) + 1 });
    ptr = s[i] - 'a';
    // std::cout << dist << '\n';
  }
  std::cout << dist << '\n';
  return 0;
}