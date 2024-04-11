#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <cassert>
#include <cstring>
#include <cmath>

using namespace std;

int n;
char buf[1005];

int main() {
  scanf("%d\n%s", &n, buf);
  int len = strlen(buf);
  int h = 0;
  for(int i = 0; i < len; i++) {
    if(buf[i] == 'H') h++;
  }
  int ret = 1 << 30;
  for(int i = 0; i < n; i++) {
    int numH = 0;
    for(int j = 0; j < h; j++) {
      if(buf[(i+j)%len] == 'H') {
        numH++;
      }
    }
    ret = min(ret, h - numH);
  }
  printf("%d\n", ret);
  return 0;
}