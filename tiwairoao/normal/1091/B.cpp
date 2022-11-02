#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1000;
const int INF = (1<<30);
int x[MAXN + 5], y[MAXN + 5];
int a[MAXN + 5], b[MAXN + 5];
int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d%d", &x[i], &y[i]);
	for(int i=1;i<=n;i++)
		scanf("%d%d", &a[i], &b[i]);
	int mxx = -INF, mxy = -INF;
	int mxa = -INF, mxb = -INF;
	for(int i=1;i<=n;i++) {
		mxx = max(mxx, x[i]);
		mxy = max(mxy, y[i]);
		mxa = max(mxa, -a[i]);
		mxb = max(mxb, -b[i]);
	}
	printf("%d %d\n", mxx - mxa, mxy - mxb);
}