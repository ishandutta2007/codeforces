#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
int le[MAXN + 5], ri[MAXN + 5];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d%d", &le[i], &ri[i]);
	sort(le+1, le+n+1); sort(ri+1, ri+n+1);
	long long ans = n;
	for(int i=n;i>=1;i--)
		ans += max(le[i], ri[i]);
	printf("%I64d\n", ans);
}