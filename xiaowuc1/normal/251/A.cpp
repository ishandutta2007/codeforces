#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int list[100005];

int main() {
  int n,d;
  scanf("%d%d", &n, &d);
  for(int i = 0; i < n; i++) {
    scanf("%d", &list[i]);
  }
  long long ret = 0;
  int j = 0;
  for(int i = 0; i < n; i++) {
    while(j < n && list[j] - list[i] <= d) {
      j++;
    }
    long long add = j-i-1;
    add *= (j-i-2);
    add /= 2;
    ret += add;
  }
  printf("%I64d\n", ret);
  return 0;
}