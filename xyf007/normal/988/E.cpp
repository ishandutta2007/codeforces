#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
std::string s;
int f(char a, char b) {
  std::string x = s;
  std::size_t p1 = x.rfind(b);
  if (p1 == std::string::npos) return 0x7fffffff;
  x.erase(p1, 1);
  std::size_t p2 = x.rfind(a);
  if (p2 == std::string::npos) return 0x7fffffff;
  x.erase(p2, 1);
  std::size_t sum = x.find_first_not_of('0');
  if (x.empty()) sum = 0;
  if (sum == std::string::npos) return 0x7fffffff;
  int len = s.size();
  return sum + (len - 1 - p1) + (len - 2 - p2);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> s;
  int ans = std::min({f('0', '0'), f('5', '0'), f('2', '5'), f('7', '5')});
  std::printf("%d", ans == 0x7fffffff ? -1 : ans);
  return 0;
}