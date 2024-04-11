#include <cstdio>
#include <algorithm>
using namespace std;

#define rep(i, x, n) for(int i=x;i<n;i++)

const int N = 50;

struct matrix{
	double m[N + 5][N + 5];
	friend matrix operator * (const matrix &A, const matrix &B) {
		matrix C;
		rep(i, 0, N) rep(j, 0, N) C.m[i][j] = 0;
		rep(i, 0, N) rep(k, 0, N) rep(j, 0, N)
			C.m[i][j] += A.m[i][k] * B.m[k][j];
		return C;
	}
}M;

matrix mpow(matrix A, int p) {
	matrix R;
	rep(i, 0, N) rep(j, 0, N)
		R.m[i][j] = (i == j);
	for(;p;p>>=1,A=A*A)
		if( p & 1 ) R = R*A;
	return R;
}

int n; double p;
double t[N + 5][N + 5], t2[N + 5][N + 5];
double s[N + 5][N + 5], s2[N + 5][N + 5];
double f[N + 5][N + 5];
void init() {
	t[1][1] = p, t[1][2] = 1 - p;
	rep(i, 2, N) {
		t[i][1] = p, t[i][2] = (1 - p) + p*p, t2[i][2] = 1;
		rep(j, 3, N) t[i][j] = t[i][j - 1]*t[i - 1][j - 1], t2[i][j] = t2[i][j - 1]*t[i - 1][j - 1];
	}
	rep(i, 1, N) rep(j, 1, N)
		s[i][j] = t[i][j]*(1 - t[i - 1][j]), s2[i][j] = t2[i][j]*(1 - t[i - 1][j]);
	s2[1][2] = 1;
	
	double sum = 0;
	rep(i, 1, N) sum += s2[N - 1][i];
	rep(i, 1, N) M.m[1][i] = s2[N - 1][i] / sum;
	
	sum = 0;
	rep(i, 2, N) {
		sum += s[N - 1][i - 1];
		rep(j, 1, i) M.m[i][j] = s[N - 1][j] / sum;
	}
	rep(i, 1, N) M.m[i][0] = i; M.m[0][0] = 1;
	
	f[1][1] = 1, f[1][2] = 2;
	rep(i, 2, N) {
		sum = 0; f[i][1] = 1;
		rep(j, 1, N) sum += s2[i - 1][j];
		rep(j, 1, N) f[i][1] += f[i - 1][j]*s2[i - 1][j]/sum;
		
		sum = 0;
		rep(j, 2, N) {
			f[i][j] = j, sum += s[i - 1][j - 1];
			rep(k, 1, j)
				f[i][j] += f[i - 1][k]*s[i - 1][k]/sum;
		}
	}
	f[N - 1][0] = 1;
}

int main() {
	scanf("%d%lf", &n, &p), p /= 1E9, init();
	
	double ans = 0;
	if( n >= N ) {
		M = mpow(M, n - N + 1);
		rep(i, 0, N) rep(j, 0, N)
			ans += M.m[i][j]*f[N - 1][j]*s[N - 1][i];
	} else rep(i, 1, N) ans += s[n][i]*f[n][i];
	printf("%.9f\n", ans);
}