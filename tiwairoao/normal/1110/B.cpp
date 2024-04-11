#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
int a[MAXN + 5], b[MAXN + 5];
int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=n;i++) scanf("%d", &b[i]);
	int ans = n;
	for(int i=1;i<n;i++) a[i] = b[i + 1] - b[i] - 1;
	sort(a + 1, a + n);
	for(int i=1;i<=n-k;i++)
		ans += a[i];
	printf("%d\n", ans);
}