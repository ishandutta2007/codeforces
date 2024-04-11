#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int x, y, z, x1, y1, z1, a1, a2, a3, a4, a5, a6;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> x >> y >> z >> x1 >> y1 >> z1 >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  int ans = 0;
  if (y < 0) {
    ans += a1;
  }
  if (y > y1) {
    ans += a2;
  }
  if (z < 0) {
    ans += a3;
  }
  if (z > z1) {
    ans += a4;
  }
  if (x < 0) {
    ans += a5;
  }
  if (x > x1) {
    ans += a6;
  }
  std::cout << ans;
  return 0;
}