#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 55;
int n, m, a[N], b[N], anst, cnt;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
  anst = 0; cnt = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (b[i] % a[j] == 0 && b[i] / a[j] > anst) {
         anst = b[i] / a[j];
         cnt = 0;
      }
      if (b[i] % a[j] == 0 && b[i] / a[j] == anst) ++cnt;
    }
  }
  printf("%d\n", cnt);       
  return 0;
}