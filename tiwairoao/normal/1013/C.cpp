#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
int a[2*MAXN + 5];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1;i<=2*n;i++)
		scanf("%d", &a[i]);
	sort(a+1, a+2*n+1);
	long long ans = a[2+n-1] - a[2];
	for(int i=3;i+n-1<2*n;i++)
		ans = min(ans, 1LL*a[i+n-1] - a[i]);
	ans = ans * (a[2*n] - a[1]);
	ans = min(ans, 1LL*(a[n]-a[1])*(a[2*n]-a[n+1]));
	printf("%I64d\n", ans);
}