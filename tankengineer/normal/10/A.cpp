//CF 10A
#include<cstdio>
#include<algorithm>

using namespace std;

int n, p1, p2, p3, t1, t2, l, r, ans, ta, tb, tc, t;

int main() {
  scanf("%d %d %d %d %d %d", &n, &p1, &p2, &p3, &t1, &t2);
  scanf("%d %d", &l, &r);
  ans += p1 * (r - l);
  t = r;
  for (int i = 2; i <= n; i++) {
    scanf("%d %d", &l, &r);      
    ta = min(l - t, t1);
    tb = max(min(l - t - t1, t2), 0);
    tc = max(l - t - t1 - t2, 0);
    ans += p1 * ta + p2 * tb + p3 * tc;
    ans += p1 * (r - l);
    t = r;
  }
  printf("%d\n", ans);
  return 0;
}