//15B
#include<cstdio>
#include<algorithm>
using namespace std;

int t;
long long n, m, x1, y1, x2, y2, tx1, tx2, ty1, ty2, tx3, tx4, ty3, ty4, ans;

int main() {
  scanf("%d", &t);
  for (; t; t--) {
    scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &m, &n, &x1, &y1, &x2, &y2);
    tx1 = max((long long)1, 1 - x2 + x1);
    tx2 = min(m, m - x2 + x1);
    ty1 = max((long long)1, 1 - y2 + y1);
    ty2 = min(n, n - y2 + y1);
    tx3 = max((long long)1, 1 + x2 - x1);
    tx4 = min(m, m + x2 - x1);
    ty3 = max((long long)1, 1 + y2 - y1);
    ty4 = min(n, n + y2 - y1);
    ans = n * m - (tx2 - tx1 + 1) * (ty2 - ty1 + 1) - (tx4 - tx3 + 1) * (ty4 - ty3 + 1);
    if (tx2 >= tx4) {
      tx2 = tx4;
      tx3 = tx1;
    }
    if (ty2 >= ty4) {
      ty2 = ty4;
      ty3 = ty1;
    }
    if (tx2 >= tx3 && ty2 >= ty3) {
      ans += (tx2 - tx3 + 1) * (ty2 - ty3 + 1);
    }
    
    printf("%I64d\n", ans);
  }
  return 0;
}