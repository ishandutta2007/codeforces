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

const int co = 500000;
const int n = 400;

int ll, rr, i, mid;
int x[n+10];
double r[n+10];

int main() {
//  freopen("out","w",stdout);
  printf("%d\n", n);
  printf("%d %d\n", 0, co);
  x[0] = 0;
  r[0] = co;
  ll = 1; rr = 1000000;
  while (ll < rr) {
    mid = (ll+rr) >> 1;
    x[1] = mid;
    int fail = 0;
    for (i=1;i<n-1;i++) {
      if (r[i-1] < 1e-9) { fail = 1; break; }
      r[i] = 1.0*(x[i]-x[i-1])*(x[i]-x[i-1])/(4.0*r[i-1]);
      x[i+1] = (int)x[i]+2*r[i]-0.0001;
      if (x[i] == x[i+1]) fail = 1;
    }
    if (fail) ll = mid+1;
    else rr = mid;
  }
    x[1] = ll;
    int fail = 0;
    for (i=1;i<n-1;i++) {
      r[i] = 1.0*(x[i]-x[i-1])*(x[i]-x[i-1])/(4.0*r[i-1]);
      x[i+1] = (int)x[i]+2*r[i]-0.0001;
      if (x[i] == x[i+1]) fail = 1;
    }
  for (i=1;i<n-1;i++) printf("%d %d\n", x[i], co);
  printf("%d %d\n", 2*co, co*2);
  return 0;
}