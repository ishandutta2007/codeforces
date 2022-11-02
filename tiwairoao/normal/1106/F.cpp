#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int MAXK = 100 + 5;
const int MOD = 998244353;
const int MODPW = MOD - 1;
const int HASHSIZE = 1000037;
struct node{
	int ind, key;
	node(int _i=0, int _k=0):ind(_i), key(_k){}
};
vector<node>h[HASHSIZE];
void hash_insert(int n, int x) {
	h[x%HASHSIZE].push_back(node(n, x));
}
int hash_search(int x) {
	int y = x%HASHSIZE;
	for(int i=0;i<h[y].size();i++)
		if( h[y][i].key == x ) return h[y][i].ind;;
	return -1;
}
void hash_clear() {
	for(int i=0;i<HASHSIZE;i++)
		h[i].clear();
}
struct matrix{
	int m[MAXK][MAXK];
	int r, c;
}A, B;
matrix operator * (matrix A, matrix B) {
	matrix C; C.r = A.r, C.c = B.c;
	for(int i=0;i<C.r;i++)
		for(int j=0;j<C.c;j++) {
			C.m[i][j] = 0;
			for(int k=0;k<A.c;k++)
				C.m[i][j] = (C.m[i][j] + 1LL*A.m[i][k]*B.m[k][j]%MODPW)%MODPW;
		}
	return C;
}
matrix mpow(matrix A, int p) {
	matrix ret; ret.r = ret.c = A.r;
	for(int i=0;i<ret.r;i++)
		for(int j=0;j<ret.c;j++)
			ret.m[i][j] = (i == j);
	while( p ) {
		if( p & 1 ) ret = ret*A;
		A = A*A;
		p >>= 1;
	}
	return ret;
}
int solve1() {
	int k, n; scanf("%d", &k);
	for(int i=0;i<k;i++) scanf("%d", &A.m[k-1][k-i-1]);
	A.r = A.c = B.r = k; B.c = 1;
	for(int i=0;i<k;i++) B.m[i][0] = 0;
	B.m[k-1][0] = 1;
	for(int i=0;i<k-1;i++)
		for(int j=0;j<k;j++)
			A.m[i][j] = 0;
	for(int i=0;i<k-1;i++) A.m[i][i+1] = 1;
	scanf("%d", &n); B = mpow(A, n-k)*B;
	return B.m[k-1][0];
}
int pow_mod(int b, int p, int mod) {
	int ret = 1;
	while( p ) {
		if( p & 1 ) ret = 1LL*ret*b%mod;
		b = 1LL*b*b%mod;
		p >>= 1;
	}
	return ret;
}
int BSGS(int a, int b) {
	hash_clear();
	int m = int(ceil(sqrt(MOD))), tmp = 1, tmp2;
	for(int i=0;i<=m;i++) {
		if( i == m ) tmp2 = tmp;
		hash_insert(i, 1LL*tmp*b%MOD);
		tmp = 1LL*tmp*a%MOD;
	}
	tmp = tmp2;
	for(int i=1;i<=m;i++) {
		if( hash_search(tmp) != -1 ) {
			return i*m - hash_search(tmp);
		}
		tmp = 1LL*tmp*tmp2%MOD;
	}
}
typedef long long ll;
ll exgcd(ll a, ll b, ll &x, ll &y) {
	if( b == 0 ) {
		x = 1, y = 0;
		return a;
	}
	else {
		ll x1, y1;
		ll d = exgcd(b, a%b, x1, y1);
		x = y1;
		y = x1 - a/b*y1;
		return d;
	}
}
int solve2(int a, int p) {
	int b = BSGS(3, a);
	ll x, y, d = exgcd(p, MODPW, x, y);
	if( b % d ) return -1;
	else {
		x = (1LL*x*b/d%MODPW + MODPW)%MODPW;
		return pow_mod(3, x, MOD);
	}
}
int main() {
	int m, p = solve1(); scanf("%d", &m);
	printf("%d\n", solve2(m, p));
}