#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1005;

int n, x[N], y[N], t[N], sc[N], ord[N], f[N], ans;
bool g[N][N];
double tf;

bool cmp(int i, int j) {return t[i] < t[j];}
int dis(int x, int y) {return x * x + y * y;}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d %lf", &x[i], &y[i], &t[i], &tf);
    sc[i] = (int)(tf * 1000000 + 0.5);
    ord[i] = i;
  }
  sort(ord + 1, ord + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    g[0][i] = true;
    for (int j = i + 1; j <= n; ++j) {
      g[i][j] = (dis(x[ord[i]] - x[ord[j]], y[ord[i]] - y[ord[j]]) <= (((long long)(t[ord[j]] - t[ord[i]])) * (t[ord[j]] - t[ord[i]])));
    }
  }
  f[0] = 0;
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (!g[j][i]) continue;
      f[i] = max(f[i], f[j] + sc[ord[i]]);
    }
    ans = max(ans, f[i]);
  }
  printf("%.12lf\n", (double)ans / 1000000.0);
  return 0;
}