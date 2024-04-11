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

int x[444444];

int main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  int n, d, i, j;
  scanf("%d %d", &n, &d);
  for (i=0;i<n;i++) scanf("%d", x+i);
  j = 0;
  long long ans = 0;
  for (i=0;i<n;i++) {
    while (x[i]-x[j] > d) j++;
    ans += (long long)(i-j)*(i-j-1)/2;
  }
  cout << ans << endl;
  return 0;
}