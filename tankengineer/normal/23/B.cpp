//23B
#include<cstdio>

int t, n;

int main() {
  scanf("%d", &t);
  for (; t; t--) {
    scanf("%d", &n);
    printf("%d\n", n > 1 ? n - 2 : 0);
  }
  return 0;
}