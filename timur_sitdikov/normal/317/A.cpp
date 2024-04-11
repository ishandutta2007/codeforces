#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int64_t SolveMPerfectProblem(int64_t x, int64_t y, int64_t m) {
  if (x >= m || y >= m) {
    return 0;
  }
  if (x <= 0 && y <= 0) {
    return -1;
  }
  if (x > y) {
    swap(x, y);
  }
  int64_t count = 0;
  if (x < 0) {
    count = (-x + y - 1) / y;
    x += count * y;
    if (x > y) {
      swap(x, y);
    }
  }
  while(y < m) {
    count++;
    int64_t sum = x + y;
    x = y;
    y = sum;
  }
  return count;
}

// To execute C++, please define "int main()"
int main() {
  int64_t x, y, m;
  cin >> x >> y >> m;
  cout << SolveMPerfectProblem(x, y, m) << endl;
  return 0;
}

/*
Test #1

Answer


Test #2

Answer

*/