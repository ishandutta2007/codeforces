#include<cmath>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 50;
const int MAXM = 100;
const int MAXT = 10*20000;
const int INF = int(1E9);
const double PI = acos(-1);
struct complex{
	double r, i;
	complex(double _r=0, double _i=0):r(_r), i(_i){}
}tmp1[MAXT + 5], tmp2[MAXT + 5], tmp3[MAXT + 5];
typedef complex cplx;
cplx operator + (cplx a, cplx b) {return cplx(a.r+b.r, a.i+b.i);}
cplx operator - (cplx a, cplx b) {return cplx(a.r-b.r, a.i-b.i);}
cplx operator * (cplx a, cplx b) {return cplx(a.r*b.r-a.i*b.i, a.i*b.r+a.r*b.i);}
cplx w[2][MAXT + 5]; 
void init() {
	int s; for(s = 2;s <= MAXT;s <<= 1); s >>= 1;
	w[0][s] = cplx(cos(2*PI/s), sin(2*PI/s));
	w[1][s] = cplx(w[0][s].r, -w[0][s].i);
	for(s >>= 1;s >= 2;s >>= 1) {
		w[0][s] = w[0][s<<1] * w[0][s<<1];
		w[1][s] = w[1][s<<1] * w[1][s<<1];
	}
}
void fft(cplx *A, int n, int type) {
	for(int i=0,j=0;i<n;i++) {
		if( i > j ) swap(A[i], A[j]);
		for(int l=(n>>1);(j^=l)<l;l>>=1);
	}
	for(int s=2;s<=n;s<<=1) {
		int t = (s>>1); cplx u = w[type][s];
		for(int i=0;i<n;i+=s) {
			cplx p = cplx(1, 0);
			for(int j=0;j<t;j++, p=p*u) {
				cplx x = A[i+j], y = A[i+j+t];
				A[i+j] = x + p*y; A[i+j+t] = x - p*y;
			}
		}
	}
	if( type ) {
		for(int i=0;i<n;i++)
			A[i].r /= n;
	}
}
struct edge{
	int u, v, w;
	double p[MAXT + 5], f[MAXT + 5];
}e[MAXM + 5];
int G[MAXN + 5][MAXN + 5];
int n, m, t, x;
void floyd() {
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}
double dp[MAXN + 5][MAXT + 5];
void divide_conquer(int le, int ri) {
	if( le == ri ) {
		if( le >= t )
			for(int i=1;i<=m;i++)
				dp[e[i].u][le] = min(dp[e[i].u][le], e[i].f[le] + e[i].w);
		return ;
	}
	int mid = (le + ri) >> 1, len;
	divide_conquer(le, mid);
	for(len = 1;len < ri-le;len <<= 1);
	for(int i=1;i<=m;i++) {
		for(int j=le;j<=mid;j++)
			tmp1[j-le] = cplx(dp[e[i].v][j], 0);
		for(int j=mid-le+1;j<len;j++)
			tmp1[j] = cplx(0, 0);
		for(int j=1;j<=ri-le;j++)
			tmp2[j-1] = cplx(e[i].p[j], 0);
		for(int j=ri-le;j<len;j++)
			tmp2[j] = cplx(0, 0);
		fft(tmp1, len, 0); fft(tmp2, len, 0);
		for(int j=0;j<len;j++)
			tmp3[j] = tmp1[j]*tmp2[j];
		fft(tmp3, len, 1);
		for(int j=mid+1;j<=ri;j++)
			e[i].f[j] += tmp3[j-le-1].r;
	}
	divide_conquer(mid+1, ri);
}
int main() {
	init();
	scanf("%d%d%d%d", &n, &m, &t, &x);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if( i != j ) G[i][j] = INF;
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		G[e[i].u][e[i].v] = min(G[e[i].u][e[i].v], e[i].w);
		for(int j=1;j<=t;j++) {
			int p; scanf("%d", &p);
			e[i].p[j] = 1.0*p/100000;
		}
	}
	floyd();
	for(int i=1;i<=n;i++) {
		for(int j=0;j<t;j++)
			dp[i][j] = G[i][n] + x;
		for(int j=t;j<=2*t;j++)
			if( i == n ) dp[i][j] = 0;
			else dp[i][j] = INF;
	}
	divide_conquer(0, 2*t);
	printf("%lf\n", dp[1][2*t]);
}