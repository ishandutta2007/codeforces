#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 300000;
int a[MAXN + 5];
int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	long long ans = 0;
	for(int i=1,j=n;i<=j;i++,j--)
		ans += 1LL*(a[i]+a[j])*(a[i]+a[j]);
	printf("%I64d\n", ans);
}