#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int x[5], y[5];
ll CountB(int x1, int y1, int x2, int y2) {
	if( ((x2-x1+1)&1) && ((y2-y1+1)&1) && ((x1+y1)&1) )
		return 1LL*(x2-x1+1)*(y2-y1+1)/2 + 1;
	else return 1LL*(x2-x1+1)*(y2-y1+1)/2;
}
void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=4;i++)
		scanf("%d%d", &x[i], &y[i]);
	ll bsiz = CountB(1, 1, m, n);
	bsiz -= CountB(x[1], y[1], x[2], y[2]);
	bsiz -= CountB(x[3], y[3], x[4], y[4]);
	if( x[2] < x[3] || x[1] > x[4] ) ;
	else if( y[2] < y[3] || y[1] > y[4]) ;
	else bsiz += CountB(max(x[1], x[3]), max(y[1], y[3]), min(x[2], x[4]), min(y[2], y[4]));
	bsiz += 1LL*(y[4]-y[3]+1)*(x[4]-x[3]+1);
	printf("%I64d %I64d\n", 1LL*n*m-bsiz, bsiz);
}
int main() {
	int t;
	scanf("%d", &t);
	for(int i=1;i<=t;i++)
		solve();
}