#include<cstdio>
#include<algorithm>
using namespace std;

const int INF = 1000000000;

int n, m, k, t1, t2, s[1005], ans;

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) s[i] = INF;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &t1, &t2);
    s[t1] = min(s[t1], t2);
  }
  for (int i = 1; i <= m; ++i) ans += s[i];
  ans = min(ans, k);
  printf("%d\n", ans);
  return 0;
}