#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXK = 200;
const int MOD = int(1E9) + 7;

struct mint{
	int x, y; 
	mint(int _x=0, int _y=0) : x(_x), y(_y) {}
	friend mint operator + (mint a, mint b) {
		int x = (a.x + b.x >= MOD ? a.x + b.x - MOD : a.x + b.x); 
		int y = (a.y + b.y >= MOD ? a.y + b.y - MOD : a.y + b.y); 
		return mint(x, y);
	}
	friend mint operator - (mint a, mint b) {
		int x = (a.x - b.x < 0 ? a.x - b.x + MOD : a.x - b.x); 
		int y = (a.y - b.y < 0 ? a.y - b.y + MOD : a.y - b.y); 
		return mint(x, y);
	}
	friend mint operator * (mint a, mint b) {
		int x = (1LL*a.x*b.x + 5LL*a.y*b.y) % MOD; 
		int y = (1LL*a.x*b.y + 1LL*a.y*b.x) % MOD; 
		return mint(x, y);
	}
	friend mint mpow(mint a, ll k) {
		mint r = 1;
		while( k ) {
			if( k & 1 ) r = r * a;
			a = a * a;
			k >>= 1;
		}
		return r;
	}
	friend mint operator / (mint a, mint b) {
		mint p = a * mint(b.x, (MOD - b.y)%MOD), q = mint((1LL*b.x*b.x%MOD + MOD - 5LL*b.y*b.y%MOD)%MOD, 0);
		return p * mpow(q, MOD-2);
	}
}s[MAXK + 5][MAXK + 5], c[MAXK + 5][MAXK + 5];

const mint A1 = 1/mint(0,1);
const mint A2 = (1 + mint(0,1))/2;
const mint B1 = 1/mint(0,MOD-1);
const mint B2 = (1 - mint(0,1))/2;

void init() {
	for(int i=0;i<=MAXK;i++) {
		c[i][0] = 1;
		for(int j=1;j<=i;j++)
			c[i][j] = c[i-1][j] + c[i-1][j-1];
	}
	for(int i=0;i<=MAXK;i++)
		for(int j=0;j<=i;j++)
			c[i][j] = c[i][j] * mpow(A1, j) * mpow(B1, i-j);
	s[0][0] = 1;
	for(int i=1;i<=MAXK;i++)
		for(int j=1;j<=i;j++)
			s[i][j] = s[i-1][j-1] + (i-1)*s[i-1][j];
	for(int i=0;i<=MAXK;i++)
		for(int j=0;j<=MAXK;j++)
			if( (i + j) & 1 ) s[i][j] = 0 - s[i][j];
}

int k;
mint get(mint a, ll m) {
	if( a.x == 1 && a.y == 0 ) return m%MOD + 1;
	else return (mpow(a, m + 1) - 1) / (a - 1);
}
mint solve(ll m) {
	mint ans = 0;
	for(int j=0;j<=k;j++) {
		mint del = 0;
		for(int p=0;p<=j;p++) {
			mint tmp = mpow(A2, p) * mpow(B2, j-p);
			del = del + c[j][p] * get(tmp, m);
		}
		ans = ans + s[k][j] * del;
	}
	return ans;
}

int main() {
	ll l, r; init();
	scanf("%d%lld%lld", &k, &l, &r), l += 2, r += 2;
	mint p = 1; for(int i=1;i<=k;i++) p = p*i;
	printf("%d\n", ((solve(r) - solve(l-1))/p).x);
}