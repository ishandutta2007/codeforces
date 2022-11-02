#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, k, ma[1005][1005], t1, t2, x[1005], y[1005];
char ch;

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &ma[i][j]);
    }
  }
  for (int i = 1; i <= n; ++i) x[i] = i;
  for (int j = 1; j <= m; ++j) y[j] = j;
  for (int i = 1; i <= k; ++i) {
    getchar();
    scanf("%c %d %d", &ch, &t1, &t2);
    if (ch == 'r') {
      swap(x[t1], x[t2]);
    }
    if (ch == 'c') {
      swap(y[t1], y[t2]);
    }
    if (ch == 'g') {
      printf("%d\n", ma[x[t1]][y[t2]]);
    }
  }
  return 0;
}