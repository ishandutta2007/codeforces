#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll INF = ll(1E18);

#define rep(i, x, n) for(int i=x;i<n;i++)

int s[100], id[1<<8], t;
struct matrix{
	ll m[100][100];
	friend matrix operator * (const matrix &A, const matrix &B) {
		matrix C; rep(i, 0, t) rep(j, 0, t) C.m[i][j] = INF;
		rep(i, 0, t) rep(k, 0, t) rep(j, 0, t)
			C.m[i][j] = min(C.m[i][j], A.m[i][k] + B.m[k][j]);
		return C;
	}
}M, A[25*8 + 5];
matrix mpow(matrix B, int p) {
	matrix R; rep(i, 0, t) rep(j, 0, t) R.m[i][j] = (i == j ? 0 : INF);
	for(;p;p>>=1,B=B*B) if( p & 1 ) R = R*B;
	return R;
}

map<int, int>mp; int c[10], k;
matrix get(int p) {
	matrix R; rep(i, 0, t) rep(j, 0, t) R.m[i][j] = INF;
	rep(i, 0, t) {
		if( s[i] & 1 ) {
			for(int j=1;j<=k;j++) {
				if( !((s[i] >> j) & 1) ) {
					int s0 = ((s[i] | (1 << j)) >> 1);
					R.m[i][id[s0]] = c[j] + (mp.count(p + j) ? mp[p + j] : 0);
				}
			}
		} else R.m[i][id[s[i] >> 1]] = 0;
	}
	return R;
}

int b[1<<8], a[25*8 + 5], cnt;
int main() {
	int x, n, q; scanf("%d%d%d%d", &x, &k, &n, &q);
	for(int i=1;i<=k;i++) scanf("%d", &c[i]);
	for(int i=1,p,w;i<=q;i++) {
		scanf("%d%d", &p, &w), mp[p] = w;
		for(int j=1;j<=k;j++)
			if( 1 <= p - j && p - j <= n - x )
				a[++cnt] = p - j;
	}
	sort(a + 1, a + cnt + 1), cnt = unique(a + 1, a + cnt + 1) - a - 1;
	rep(i, 1, (1 << k)) {
		b[i] = b[i >> 1] + (i & 1);
		if( b[i] == x ) s[id[i] = (t++)] = i;
	}
	
	M = get(n + 5); for(int i=1;i<=cnt;i++) A[i] = get(a[i]);
	matrix R; rep(i, 0, t) rep(j, 0, t) R.m[i][j] = (i == j ? 0 : INF);
//	for(int i=1;i<=n-x;i++) R = R*get(i);
	for(int i=1;i<=cnt;i++) {
		if( a[i] - a[i-1] - 1 > 0 ) R = R * mpow(M, a[i] - a[i-1] - 1);
		R = R * A[i];
	}
	if( n - x - a[cnt] > 0 ) R = R * mpow(M, n - x - a[cnt]);
	printf("%lld\n", R.m[0][0]);
}