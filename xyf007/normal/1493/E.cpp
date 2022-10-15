#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int n;
std::string l, r;
void Add(std::string &s) {
  std::size_t pos = s.find_last_of('0');
  s.at(pos) = '1';
  for (size_t i = pos + 1; i < s.size(); i++) {
    s.at(i) = '0';
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> l >> r;
  if (l.front() != r.front()) {
    for (int i = 1; i <= n; i++) {
      std::cout << 1;
    }
    return 0;
  }
  if (r.back() == '1') {
    std::cout << r;
    return 0;
  }
  Add(l);
  if (l >= r) {
    std::cout << r;
  } else {
    Add(r);
    std::cout << r;
  }
  return 0;
}