#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;

const double MAGIC = 3.14159265358979;

inline double dist(int a, int b, int c, int d) {
  return sqrt(1.0 * ((a - c) * (a - c) + (b - d) * (b - d)));
}

double d[444][444];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector < pair <int, int> > a;
  for (int x = 0; x <= n; x++) {
    for (int y = 0; y <= m; y++) {
      if (dist(0, 0, x, y) < MAGIC || dist(0, m, x, y) < MAGIC ||
          dist(n, 0, x, y) < MAGIC || dist(n, m, x, y) < MAGIC) {
        a.push_back(make_pair(x, y));
      }
    }
  }
  int k = a.size();
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      d[i][j] = dist(a[i].first, a[i].second, a[j].first, a[j].second);
    }
  }
  double ans = -1.0;
  int a1 = -1;
  int a2 = -1;
  int a3 = -1;
  int a4 = -1;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      if (i != j) {
        for (int p = 0; p < k; p++) {
          if (i != p && j != p) {
            for (int q = 0; q < k; q++) {
              if (i != q && j != q && p != q) {
                double sum = d[i][j] + d[j][p] + d[p][q];
                if (sum > ans) {
                  ans = sum;
                  a1 = i;
                  a2 = j;
                  a3 = p;
                  a4 = q;
                }
              }
            }
          }
        }
      }
    }
  }
  printf("%d %d\n", a[a1].first, a[a1].second);
  printf("%d %d\n", a[a2].first, a[a2].second);
  printf("%d %d\n", a[a3].first, a[a3].second);
  printf("%d %d\n", a[a4].first, a[a4].second);
  return 0;
}