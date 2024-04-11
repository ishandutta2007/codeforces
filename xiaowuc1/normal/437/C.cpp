#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <cassert>
#include <cstring>
#include <cmath>

using namespace std;

int list[1005];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &list[i]);
  }
  int ret = 0;
  while(m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    ret += min(list[a], list[b]);
  }
  printf("%d\n", ret);
  return 0;  
}