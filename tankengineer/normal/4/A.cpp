//CF 4A
#include<cstdio>
int n;
int main() {
  scanf("%d", &n);
  puts(n % 2 || n == 2 ? "NO" : "YES");
  return 0;
}