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

using namespace std;

unsigned int a[111111];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i=0;i<n;i++) {
    int x[4];
    scanf("%d.%d.%d.%d", x+0, x+1, x+2, x+3);
    a[i] = 0;
    for (int j=0;j<4;j++)
      for (int p=7;p>=0;p--) {
        a[i] <<= 1;
        if (x[j] & (1 << p)) a[i]++;
      }
  }
  sort(a, a+n);
  unsigned int mask = 0;
  for (int z=1;z<=31;z++) {
    mask += (1LL << (32-z));
    int nets = 1;
    for (int i=0;i<n-1;i++)
      if ((a[i] & mask) != (a[i+1] & mask)) nets++;
    if (nets == k) {
      printf("%d.%d.%d.%d\n", mask >> 24, (mask >> 16) & 255, (mask >> 8) & 255, mask & 255);
      return 0;
    }
  }
  printf("%d\n", -1);
  return 0;
}