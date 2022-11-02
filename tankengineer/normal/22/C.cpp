//22C
#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, v, cntv;

int main() {
  scanf("%d %d %d", &n, &m, &v);
  if (m < n - 1 || m > (n - 2) * (n - 3) / 2 + n - 1) {
    puts("-1");
  } else {
    cntv = n; if (cntv == v) cntv = v - 1;
    for (int i = 1; i <= n; i++) {
      if (i != v) {
        printf("%d %d\n", i, v);
        m--;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (i != j && i != v && j != v && i != cntv && j != cntv) {
          if (m == 0) return 0;
          printf("%d %d\n", i, j);
          m--;
        }
      }
    }
  }
  return 0;
}