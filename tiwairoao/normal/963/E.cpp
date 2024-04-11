#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = int(1E9) + 7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

#define lb(x) max(0, x - d)
#define rb(x) min(n - 1, x + d)

struct mint{
	int x; mint(int _x=0) : x(_x) {}
	friend mint operator + (mint a, mint b) {return a.x + b.x >= MOD ? a.x + b.x - MOD : a.x + b.x;}
	friend mint operator - (mint a, mint b) {return a.x - b.x < 0 ? a.x - b.x + MOD : a.x - b.x;}
	friend mint operator * (mint a, mint b) {return 1LL*a.x*b.x%MOD;}
	friend mint pow(mint b, int p) {
		mint ret = 1;
		for(int i=p;i;i>>=1,b*=b)
			if( i & 1 ) ret *= b;
		return ret;
	}
	friend mint operator / (mint a, mint b) {return a*pow(b, MOD-2);}
	friend void operator += (mint &a, mint b) {a = a + b;}
	friend void operator -= (mint &a, mint b) {a = a - b;}
	friend void operator *= (mint &a, mint b) {a = a * b;}
	friend void operator /= (mint &a, mint b) {a = a / b;}
};

mint A[8000][8000];
void gauss(int n, int d) {
	for(int i=0;i<n;i++) {
		mint k = pow(A[i][i], MOD-2);
		for(int j=i;j<=rb(i);j++)
			A[i][j] *= k;
		A[i][n] *= k;
		for(int j=i+1;j<=rb(i);j++) {
			k = A[j][i];
			for(int p=i;p<=rb(i);p++)
				A[j][p] -= k*A[i][p];
			A[j][n] -= k*A[i][n];
		}
	}
	for(int i=n-1;i>=0;i--)
		for(int j=i-1;j>=0;j--)
			A[j][n] -= A[i][n] * A[j][i];
}

int R; mint p[4], s;
int id[105][105], cnt;

int main() {
	scanf("%d", &R);
	for(int i=0;i<4;i++) scanf("%d", &p[i].x), s += p[i];
	for(int i=0;i<4;i++) p[i] /= s;
	int mx = 0;
	for(int i=-R;i<=R;i++)
		for(int j=-R;j<=R;j++)
			if( i*i + j*j <= R*R )
				id[i+R][j+R] = (cnt++);
	for(int i=-R;i<=R;i++)
		for(int j=-R;j<=R;j++) {
			if( i*i + j*j > R*R ) continue;
			int t1 = id[i+R][j+R];
			for(int k=0;k<4;k++) {
				int x0 = i + dx[k], y0 = j + dy[k];
				if( x0*x0 + y0*y0 > R*R ) continue;
				int t2 = id[x0+R][y0+R];
				A[t1][t2] -= p[k], mx = max(mx, abs(t1 - t2));
			}
			A[t1][t1] = A[t1][cnt] = 1;
		}
	gauss(cnt, mx);
	printf("%d\n", A[id[R][R]][cnt].x);
}