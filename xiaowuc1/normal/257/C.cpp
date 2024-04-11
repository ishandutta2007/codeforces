#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>

#define PI 2*atan2(1,0)

using namespace std;

int main() {
  double list[100005];
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int x,y;
    scanf("%d%d", &x, &y);
    list[i] = atan2(y, x);
  }
  sort(list, list+n);
  list[n] = list[0] + 2 * PI;
  double ret = 360;
  for(int i = 0; i < n; i++) {
    int j = i+1;
    double ang = list[j] - list[i];
    ang *= 180;
    ang /= PI;
    ang = 360 - ang;
    if(ang < ret) {
      ret = ang;
    }
  }
  printf("%f\n", ret);
  return 0;
}