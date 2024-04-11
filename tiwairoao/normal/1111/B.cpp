#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
double a[MAXN + 5];
int main() {
	int n, k, m; scanf("%d%d%d", &n, &k, &m);
	for(int i=1;i<=n;i++) scanf("%lf", &a[i]);
	sort(a + 1, a + n + 1);
	double ans = 0, res = 0;
	for(int i=1;i<=n;i++) ans += a[i];
	ans /= n;
	for(int i=n;i>=1;i--) {
		res += a[i];
		if( i-1 <= m ) {
			double p = min(1.0*(m-i+1), 1.0*k*(n-i+1));
			ans = max(ans, (res+p)/(n-i+1));
		}
	}
	printf("%.10lf\n", ans);
}