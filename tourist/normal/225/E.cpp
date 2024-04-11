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

using namespace std;

const int md = 1000000007;

int a[40] = {2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,2203,2281,3217,4253,4423,9689,9941,11213,19937,21701,23209,44497,
             86243,110503,132049,216091,756839,859433,1257787,1398269,2976221,3021377,6972593,13466917,20996011};

int main() {
//  freopen("in","r",stdin);
//  freopen("out","w",stdout);
  int n;
  scanf("%d",&n);
  int x = 1;
  for (int i=1;i<a[n-1];i++) {
    x *= 2;
    if (x >= md) x -= md;
  }
  printf("%d\n",(x+md-1) % md);
  return 0;
}