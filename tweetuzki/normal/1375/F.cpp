#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

int main() {
  long long a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);
  std::cout << "First" << std::endl;
  std::cout << (long long) 1e10 << std::endl;
  int id;
  std::cin >> id;
  if (id == 0) return 0;
  else if (id == 1) {
    a += (long long) 1e10;
    long long value = 2 * a - b - c;
    std::cout << value << std::endl;
    std::cin >> id;
    if (id == 0) return 0;
    else if (id == 2) std::cout << a - c << std::endl;
    else std::cout << a - b << std::endl;
  } else if (id == 2) {
    b += (long long) 1e10;
    long long value = 2 * b - a - c;
    std::cout << value << std::endl;
    std::cin >> id;
    if (id == 0) return 0;
    else if (id == 1) std::cout << b - c << std::endl;
    else std::cout << b - a << std::endl;
  } else {
    c += (long long) 1e10;
    long long value = 2 * c - a - b;
    std::cout << value << std::endl;
    std::cin >> id;
    if (id == 0) return 0;
    else if (id == 1) std::cout << c - b << std::endl;
    else std::cout << c - a << std::endl;
  }
  return 0;
}