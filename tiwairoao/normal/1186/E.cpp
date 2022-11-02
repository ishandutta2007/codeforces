#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1000;
ll s[MAXN + 5][MAXN + 5];
int n[MAXN + 5], m[MAXN + 5];
char c[MAXN + 5];
ll fun1(int dep, int x, int y) {
	if( dep == -1 ) return s[x][y];
	if( x <= n[dep] && y <= m[dep] )
		return fun1(dep - 1, x, y);
	if( x <= n[dep] && y > m[dep] ) {
		if( dep ) return (1LL*x*(y-m[dep]) - fun1(dep - 1, x, y-m[dep])) + 1LL*x*m[dep-1];
		else return (1LL*x*(y-m[dep]) - fun1(dep - 1, x, y-m[dep]) + fun1(dep - 1, x, m[dep]));
	}
	if( x > n[dep] && y <= m[dep] ) {
		if( dep ) return (1LL*(x-n[dep])*y - fun1(dep - 1, x-n[dep], y)) + 1LL*n[dep-1]*y;
		else return (1LL*(x-n[dep])*y - fun1(dep - 1, x-n[dep], y) + fun1(dep - 1, n[dep], y));
	}
	if( x > n[dep] && y > m[dep] ) {
		//puts("?");
		if( dep ) {
			//printf("? %lld %lld %lld\n", fun2(dep - 1, x-n[dep]), fun3(dep - 1, y-m[dep]), 1LL*n[dep]*m[dep]/2);
			return fun1(dep - 1, x-n[dep], y-m[dep]) + 1LL*(x-n[dep])*m[dep-1] + 1LL*n[dep-1]*(y-m[dep]) + 1LL*n[dep]*m[dep]/2;
		}
		else {
			//printf("| %lld %lld %lld %lld\n", 1LL*x*y, (1LL*(x-n[dep])*(y-m[dep]) - fun1(dep - 1, x-n[dep], y-m[dep])), fun1(dep - 1, x-n[dep], m[dep]) + fun1(dep - 1, n[dep], y-m[dep]), s[n[0]][m[0]]);
			return 1LL*(x-n[dep])*m[dep] + 1LL*n[dep]*(y-m[dep]) + fun1(dep - 1, x-n[dep], y-m[dep]) + s[n[0]][m[0]] - fun1(dep - 1, x-n[dep], m[dep]) - fun1(dep - 1, n[dep], y-m[dep]);
		}
	}
}
ll sum(int x, int y) {
	if( x == 0 || y == 0 ) return 0;
	int dep; for(dep = 0; x - n[dep] > n[dep] || y - m[dep] > m[dep]; dep++);
	return fun1(dep, x, y);
}
int main() {
	int q;
	scanf("%d%d%d", &n[0], &m[0], &q);
	for(int i=1;i<=n[0];i++) {
		scanf("%s", c + 1);
		for(int j=1;j<=m[0];j++)
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + (c[j] - '0');
	}
	for(int i=1;i<=MAXN;i++)
		n[i] = 2*n[i-1], m[i] = 2*m[i-1];
	for(int i=1;i<=q;i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%lld\n", sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1));
	}
}