#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <cassert>
#include <cstring>
#include <cmath>

using namespace std;

int x[1000];
int y[1000];
int num[1000];
bool used[1000];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d%d%d", &x[i], &y[i], &num[i]);
  }
  double ret = 0;
  for(int qq = 0; qq < n && k < 1000000; qq++) {
    double highest = 1e20;
    int bestIndex = -1;
    for(int i = 0; i < n; i++) {
      if(used[i]) continue;
      double curr = sqrt(x[i] * x[i] + y[i] * y[i]);
      if(curr < highest) {
        bestIndex = i;
        highest = curr;
      }
    }
    ret = highest;
    used[bestIndex] = true;
    k += num[bestIndex];
  }
  if(k < 1000000) ret = -1;
  printf("%.12f\n", ret);
  return 0;  
}