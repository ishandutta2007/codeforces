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

const int N = 200010;

char a[N][55], b[N][55];
int p[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s %s", a[i], b[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
    p[i]--;
  }
  string res = "";
  for (int id = 0; id < n; id++) {
    int i = p[id];
    string x = "", y = "";
    for (int j = 0; a[i][j]; j++) x += a[i][j];
    for (int j = 0; b[i][j]; j++) y += b[i][j];
    if (x > y) {
      swap(x, y);
    }
    if (x > res) {
      res = x;
      continue;
    }
    if (y > res) {
      res = y;
      continue;
    }
    puts("NO");
    return 0;
  }
  puts("YES");
  return 0;
}