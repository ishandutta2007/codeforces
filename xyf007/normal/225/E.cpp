#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
constexpr int kMod = 1e9 + 7,
              kPw[] = {0,       1,       2,       4,        6,       12,
                       16,      18,      30,      60,       88,      106,
                       126,     520,     606,     1278,     2202,    2280,
                       3216,    4252,    4422,    9688,     9940,    11212,
                       19936,   21700,   23208,   44496,    86242,   110502,
                       132048,  216090,  756838,  859432,   1257786, 1398268,
                       2976220, 3021376, 6972592, 13466916, 20996010};
int n;
int Ksm(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) {
      s = s * static_cast<long long>(a) % kMod;
    }
    a = a * static_cast<long long>(a) % kMod;
    b >>= 1;
  }
  return s;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  std::cout << (Ksm(2, kPw[n]) + kMod - 1) % kMod;
  return 0;
}