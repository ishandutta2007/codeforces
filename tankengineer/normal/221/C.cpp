#include<cstdio>
#include<algorithm>
using namespace std;

int n, a[100005], b[100005], cnt;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) b[i] = a[i];
  sort(b + 1, b + n + 1);
  cnt = 0;
  for (int i = 1; i <= n; ++i) cnt += (a[i] == b[i]) ? 0 : 1;
  if (cnt <= 2) printf("YES"); else printf("NO");
  return 0;
}