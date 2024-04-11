#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  int t, k, n, m, v, l;
  
  scanf("%d %d", &t, &k);
  while (t--) {
    scanf("%d %d", &n, &m);
    if (k != 1) {
      l = 2 * k + 2;
      v = min(n / l - (n % l == 0), m / l - (m % l == 0));
      n -= v * l;
      m -= v * l;
      if (n <= k || m <= k) {
        printf("%c\n", (m + n) % 2 ? '+' : '-');
      } else if (n == k + 1 || m == k + 1) {
        printf("+\n");
      } else if (n < 2 * k + 2 || m < 2 * k + 2) {
        printf("%c\n", (m + n) % 2 ? '-' : '+');
      } else {
        printf("+\n");
      }
    } else {
      if (min(n, m) % 2 == 0) {
        puts("+");
      } else {
        puts((n + m) % 2 ? "+" : "-");
      }
    }
  }
  
  return 0;
}