#include <cstdio>
#include <algorithm>
using namespace std;
 
const int MAXN = 4000;
const int INF = int(1E9);
 
int s[MAXN + 5][MAXN + 5], tr[MAXN + 5][MAXN + 5];
 
int read() {
	int x = 0; char ch = getchar();
	while( ch > '9' || ch < '0' ) ch = getchar();
	while( '0' <= ch && ch <= '9' ) x = 10*x + ch - '0', ch = getchar();
	return x;
}
void solve(int *A, int *B, int opl, int opr, int l, int r) {
	if( l > r ) return ;
	int m = (l + r) >> 1, opm = opl;
	for(int i=opl;i<=opr;i++)
		if( A[m] > B[i] + tr[i+1][m] )
			A[m] = B[i] + tr[i+1][m], opm = i;
	solve(A, B, opl, opm, l, m - 1);
	solve(A, B, opm, opr, m + 1, r);
}
int f[MAXN + 5], g[MAXN + 5];
int main() {
	int n = read(), k = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) {
			if( i <= j ) tr[i][j] = (s[j][j] - 2*s[i-1][j] + s[i-1][i-1])/2;
			else tr[i][j] = INF;
		}
	for(int i=1;i<=n;i++) f[i] = INF;
	for(int i=1;i<=k;i++) {
		for(int i=0;i<=n;i++) g[i] = f[i], f[i] = INF;
		solve(f, g, 0, n, 1, n), f[0] = 0;
	}
	printf("%d\n", f[n]);
}