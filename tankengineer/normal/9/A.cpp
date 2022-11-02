//CF 9A
#include<stdio.h>
#include<cstring>

const char ans[6][4] = {"1/1", "5/6", "2/3", "1/2", "1/3", "1/6"};
int a, b;

int main() {
  scanf("%d %d", &a, &b);
  printf("%s\n", ans[(a < b ? b : a) - 1]);
  return 0;
}