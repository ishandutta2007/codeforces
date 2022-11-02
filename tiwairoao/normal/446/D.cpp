#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 500;
const double EPS = 1E-7;
struct matrix{
	int r, c; double m[100 + 5][100 + 5];
	friend matrix operator * (matrix A, matrix B) {
		matrix C; C.r = A.r, C.c = B.c;
		for(int i=0;i<C.r;i++)
			for(int j=0;j<C.c;j++)
				C.m[i][j] = 0;
		for(int i=0;i<C.r;i++) {
			for(int k=0;k<A.c;k++)
				for(int j=0;j<C.c;j++)
					C.m[i][j] += A.m[i][k] * B.m[k][j];
		}
		return C;
	}
}M2, B;
matrix mpow(matrix A, int p) {
	matrix R; R.r = R.c = A.r;
	for(int i=0;i<R.r;i++)
		for(int j=0;j<R.c;j++)
			R.m[i][j] = (i == j);
	while( p ) {
		if( p & 1 ) R = R * A;
		A = A * A;
		p >>= 1;
	}
	return R;
}
double M[MAXN + 5][100 + MAXN + 5];
void gauss(int n, int m) {
	int r = 1, c = 1;
	while( r <= n && c <= m ) {
		int mxr = r;
		for(int i=r;i<=n;i++)
			if( fabs(M[i][c]) - fabs(M[mxr][c]) > EPS )
				mxr = i;
		if( fabs(M[mxr][c]) > EPS ) {
			if( r != mxr ) {
				for(int j=1;j<=m;j++)
					swap(M[r][j], M[mxr][j]);
			}
			double k = M[r][c];
			for(int j=1;j<=m;j++)
				M[r][j] /= k;
			for(int i=1;i<=n;i++)
				if( i != r ) {
					k = M[i][c];
					for(int j=1;j<=m;j++)
						M[i][j] -= k*M[r][j];
				}
			r++;
		}
		c++;
	}
}
int a[MAXN + 5], id[MAXN + 5], cnt;
int type[MAXN + 5], deg[MAXN + 5];
int n, m, k;
void addedge(int u, int v) {
	if( type[v] ) M[u][n + id[v]] += 1;
	else M[u][v] -= 1;
	deg[u]++;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=n;i++) {
		scanf("%d", &type[i]);
		if( type[i] ) a[id[i] = (++cnt)] = i;
	}
	for(int i=1;i<=m;i++) {
		int u, v; scanf("%d%d", &u, &v);
		addedge(u, v), addedge(v, u);
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n+cnt;j++)
			M[i][j] /= deg[i];
		M[i][i] = 1;
	}
	gauss(n, n + cnt);
	M2.r = M2.c = cnt;
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=cnt;j++)
			M2.m[i - 1][j - 1] = M[a[i]][n + j];
	B.r = 1, B.c = cnt;
	for(int i=1;i<=cnt;i++)
		B.m[0][i - 1] = M[1][n + i];
	B = B*mpow(M2, k - 2);
	printf("%.7lf\n", B.m[0][id[n] - 1]);
}