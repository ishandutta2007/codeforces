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

const int m = 360360;

int k;
int f[m+10];

int go(int from, int to) {
  int i, j;
  for (i=0;i<m;i++) f[i] = 42424242;
  f[from] = 0;
  for (i=m-1;i>=1;i--)
    if (f[i] < 42424242) {
      if (f[i]+1 < f[i-1]) f[i-1] = f[i]+1;
      for (j=2;j<=k;j++) {
        int z = i-(i % j);
        if (f[i]+1 < f[z]) f[z] = f[i]+1;
      }
    }
  return f[to];
}

int main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  long long a, b;
  cin >> a >> b >> k;
  long long ans = 0;
  if (a/m == b/m) {
    ans = go(a % m, b % m);
  } else {
    ans = go(a % m, 0);
    ans += 1+go(m-1, b % m);
    ans += (long long)(1+go(m-1, 0))*(a/m - b/m - 1);
  }
  cout << ans << endl;
  return 0;
}