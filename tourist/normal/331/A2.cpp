#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

pair <int, int> b[333333];
int a[333333];
long long s[333333];
int bad[333333];

int main() {
  int n;
  scanf("%d", &n);
  for (int i=0;i<n;i++) {
    scanf("%d", a+i);
    b[i] = make_pair(a[i], i);
  }
  s[0] = 0;
  for (int i=0;i<n;i++) s[i+1] = s[i] + (a[i] > 0 ? a[i] : 0);
  sort(b, b+n);
  int beg = 0;
  long long ans = -(long long)2e18;
  int ax = 0, ay = 0;
  while (beg < n) {
    int end = beg;
    while (end+1 < n && b[end+1].first == b[beg].first) end++;
    if (beg < end) {
      int x = b[beg].second;
      int y = b[end].second;
      long long cur = s[y] - s[x+1] + (b[beg].first * 2);
      if (cur > ans) {
        ans = cur;
        ax = x;
        ay = y;
      }
    }
    beg = end+1;
  }
  cout << ans << " ";
  int kb = 0, x = ax, y = ay;
  for (int i=0;i<n;i++)
    if (i >= x && i <= y && (i == x || i == y || a[i] > 0)) {
    } else {
      bad[kb++] = i;
    }
  printf("%d\n", kb);
  for (int i=0;i<kb-1;i++) printf("%d ", bad[i]+1);
  if (kb > 0) printf("%d", bad[kb-1]+1);
  printf("\n");
  return 0;
}