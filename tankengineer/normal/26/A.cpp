//26A
#include<cstdio>

int n, ans, tag[5005];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j < i; j++) {
            if (tag[j] == 0 && i % j == 0) tag[i]++;
        }
        if (tag[i] == 2) ans++;
    }
    printf("%d\n", ans);
  return 0;
}