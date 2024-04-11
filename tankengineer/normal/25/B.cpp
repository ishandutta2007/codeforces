//25B
#include<cstdio>

int n;
char num[105];

int main() {
  scanf("%d", &n);
    scanf("%s", &num);
    for (int i = 0; i < n; i++) {
      printf("%c", num[i]);
        if (i % 2 && i != n - 1 && !(n % 2 && i == n - 1 - 1)) printf("-");
    }
    printf("\n");
    return 0;
}