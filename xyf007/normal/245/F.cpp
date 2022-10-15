#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
constexpr int kDays[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m;
int Calc(const std::string &s) {
  std::stringstream ss;
  ss << s;
  int ans = 0, x;
  ss >> x;
  for (int i = 1; i < x; i++) ans += kDays[i];
  ss >> x;
  ans += x;
  ans *= 86400;
  ss >> x;
  ans += x * 3600;
  ss >> x;
  ans += x * 60;
  ss >> x;
  ans += x;
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  std::string s;
  std::queue<int> q;
  while (std::getline(std::cin, s)) {
    while (s.empty()) std::getline(std::cin, s);
    s = s.substr(5, 15);
    std::string tmp = s;
    for (auto &&ch : tmp)
      if (!std::isdigit(ch)) ch = ' ';
    int tm = Calc(tmp);
    while (!q.empty() && tm - q.front() >= n) q.pop();
    q.emplace(tm);
    if (static_cast<int>(q.size()) >= m) {
      s.pop_back();
      std::cout << "2012-" << s;
      return 0;
    }
  }
  std::cout << -1;
  return 0;
}