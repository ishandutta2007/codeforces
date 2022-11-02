#include <map>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAXN = 50000;
 
int N, M, P; ll K;
inline int add(int x, int y) {x += y; return x >= P ? x - P : x;}
inline int mul(int x, int y) {return 1LL * x * y % P;}
 
struct matrix{
	int m00, m01, m10, m11; matrix() {m00 = m01 = m10 = m11 = 0;}
	matrix(int _a, int _b, int _c, int _d) : m00(_a), m01(_b), m10(_c), m11(_d) {}
	
	friend matrix operator * (const matrix &A, const matrix &B) {
		matrix C;
		C.m00 = add(mul(A.m00, B.m00), mul(A.m01, B.m10));
		C.m01 = add(mul(A.m00, B.m01), mul(A.m01, B.m11));
		C.m10 = add(mul(A.m10, B.m00), mul(A.m11, B.m10));
		C.m11 = add(mul(A.m10, B.m01), mul(A.m11, B.m11));
		return C;
	}
}A[MAXN + 5], S;
 
namespace segtree{
	#define lch (x << 1)
	#define rch (x << 1 | 1)
	
	int le[4*MAXN + 5], ri[4*MAXN + 5]; matrix B[4*MAXN + 5];
	void build(int x, int l, int r) {
		le[x] = l, ri[x] = r;
		if( l == r ) {
			B[x] = A[l];
			return ;
		}
		int m = (l + r) >> 1;
		build(lch, l, m), build(rch, m + 1, r);
		B[x] = B[rch] * B[lch];
	}
	matrix query(int x, int l, int r) {
		if( l > ri[x] || r < le[x] ) return matrix(1, 0, 0, 1);
		if( l <= le[x] && ri[x] <= r ) return B[x];
		return query(rch, l, r) * query(lch, l, r);
	}
}
 
matrix getM(int l, int r) {return segtree::query(1, l, r);}
matrix mpow(matrix B, ll p) {
	matrix R(1, 0, 0, 1);
	for(ll i=p;i;i>>=1,B=B*B)
		if( i & 1 ) R = R*B;
	return R;
}
matrix get(ll l, ll r) {
	if( l > r ) return matrix(1, 0, 0, 1);
	if( (l / N) == (r / N) )
		return getM(l % N, r % N);
	else return getM(0, r % N) * mpow(S, (r / N) - (l / N) - 1) * getM(l % N, N - 1);
}
 
int s[MAXN + 5];
void init() {
	for(int i=0;i<N;i++) A[i] = matrix(s[i + 1 == N ? 0 : i + 1], s[i], 1, 0);
	S = matrix(1, 0, 0, 1); for(int i=0;i<N;i++) S = A[i] * S;
	segtree::build(1, 0, N - 1);
}
 
map<ll, pii>mp;
int main() {
	scanf("%lld%d%d", &K, &P, &N);
	for(int i=0;i<N;i++) scanf("%d", &s[i]);
	init();
	
	scanf("%d", &M);
	for(int i=0;i<M;i++) {
		ll j; int v; scanf("%lld%d", &j, &v);
		if( j - 1 < K ) {
			if( !mp.count(j - 1) ) mp[j - 1] = make_pair(s[j % N], s[(j - 1) % N]);
			mp[j - 1].first = v;
		}
		if( j < K ) {
			if( !mp.count(j) ) mp[j] = make_pair(s[(j + 1) % N], s[j % N]);
			mp[j].second = v;
		}
	}
	
	ll nw = 0; matrix ans = matrix(1, 0, 0, 1);
	for(map<ll, pii>::iterator it=mp.begin();it!=mp.end();it++) {
		ll x = it->first; int p = it->second.first, q = it->second.second;
		ans = matrix(p, q, 1, 0) * get(nw, x - 1) * ans;
		nw = x + 1;
	}
	ans = get(nw, K - 1) * ans, printf("%d\n", ans.m10);
}