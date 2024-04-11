#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int list[100];

int main() {
  int n,m,k;
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &list[i]);
  }
  sort(list, list+n);
  int curr = k;
  int ret = 0;
  int currIndex = n-1;
  while(curr < m) {
    if(currIndex == -1) {
      printf("%d\n", -1);
      return 0;
    }
    else {
      curr += list[currIndex--] - 1;
      ret++;
    }
  }
  printf("%d\n", ret);
  return 0;
}