#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cassert>

#define MAXN 225

int n;
int list[MAXN];

using namespace std;

int main() {
  scanf("%d", &n);
  if(n <= 2 || n % 2 == 0) {
    printf("%d\n", -1);
  }
  else {
    for(int i = 1; i <= n; i++) {
      scanf("%d", &list[i]);
    }
    int ret = 0;
    for(int x = n/2; x >= 1; x--) {
      while(list[2*x] || list[2*x+1]) {
	ret++;
	if(list[x]) list[x]--;
	if(list[2*x]) list[2*x]--;
	if(list[2*x+1]) list[2*x+1]--;
      }
    }
    for(int x = n; x >= 1; x--) {
      while(list[x]) {
	ret++;
	list[x]--;
      }
    }
    printf("%d\n", ret);
  }
}