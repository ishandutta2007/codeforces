#include <cstdio>
typedef long long ll;
const int MAXN = 100;
const int MOD = int(1E9) + 7;
struct matrix{
	int m[MAXN + 5][MAXN + 5], r, c;
	friend matrix operator * (matrix A, matrix B) {
		matrix C; C.r = A.r, C.c = B.c;
		for(int i=0;i<C.r;i++)
			for(int j=0;j<C.c;j++)
				C.m[i][j] = 0;
		for(int i=0;i<C.r;i++)
			for(int k=0;k<A.c;k++)
				for(int j=0;j<C.c;j++)
					C.m[i][j] = (C.m[i][j] + 1LL*A.m[i][k]*B.m[k][j]%MOD)%MOD;		
		return C;
	}
}A;
matrix m_pow(matrix A, ll p) {
	matrix ret; ret.r = A.r, ret.c = A.c;
	for(int i=0;i<A.r;i++)
		for(int j=0;j<A.c;j++)
			ret.m[i][j] = (i == j);
	while( p ) {
		if( p & 1 )
			ret = ret * A;
		A = A * A;	
		p >>= 1;
	}
	return ret;
}
int main() {
	ll N; int M; scanf("%lld%d", &N, &M);
	for(int i=0;i<M;i++)
		for(int j=0;j<M;j++)
			A.m[i][j] = 0;
	for(int i=1;i<M;i++)
		A.m[i][i-1] = 1;
	A.m[0][0] = A.m[0][M-1] = 1;
	A.r = A.c = M, A = m_pow(A, N);
	int ans = 0;
	for(int i=0;i<M;i++)
		ans = (ans + A.m[M-1][i]) % MOD;
	printf("%d\n", ans);
}