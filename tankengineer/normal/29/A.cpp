//29A
#include<cstdio>

int n, p[105], r[105];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &p[i], &r[i]);
    for (int j = 1; j < i; j++) {
      if (p[j] + r[j] == p[i] && p[i] + r[i] == p[j]) {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0; 
}