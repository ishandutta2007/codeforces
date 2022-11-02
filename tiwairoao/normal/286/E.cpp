#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 998244353;
const int MAXN = (1 << 21);
const int G = 3;

inline int add(int x, int y) {return (x + y >= MOD ? x + y - MOD : x + y);}
inline int sub(int x, int y) {return (x - y < 0 ? x - y + MOD : x - y);}
inline int mul(int x, int y) {return 1LL * x * y % MOD;}

int pow_mod(int b, int p) {
	int ret = 1;
	for(int i=p;i;i>>=1,b=mul(b,b))
		if( i & 1 ) ret = mul(ret, b);
	return ret;
}

int w[22], iw[22];
void init() {
	for(int i=0;i<22;i++) {
		w[i] = pow_mod(G, (MOD - 1) / (1 << i));
		iw[i] = pow_mod(w[i], MOD - 2);
	}
}
int length(int n) {
	int len; for(len = 1; len < n; len <<= 1);
	return len;
}
void ntt(int *A, int n, int type) {
	for(int i=0,j=0;i<n;i++) {
		if( i < j ) swap(A[i], A[j]);
		for(int k=(n>>1);(j^=k)<k;k>>=1);
	}
	for(int i=1;(1<<i)<=n;i++) {
		int s = (1 << i), t = (s >> 1);
		int u = (type == 1 ? w[i] : iw[i]);
		for(int j=0;j<n;j+=s) {
			for(int k=0,p=1;k<t;k++,p=mul(p,u)) {
				int x = A[j+k], y = mul(p, A[j+k+t]);
				A[j+k] = add(x, y), A[j+k+t] = sub(x, y);
			}
		}
	}
	if( type == -1 ) {
		int iv = pow_mod(n, MOD - 2);
		for(int i=0;i<n;i++)
			A[i] = mul(A[i], iv);
	}
}
vector<int>ans;
int f[MAXN + 5]; bool tag[MAXN + 5];
int n, m;
int main() {
	init(); scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) {
		int x; scanf("%d", &x);
		tag[x - 1] = true, f[x - 1] = 1;
	}
	int len = length(m + m - 1);
	ntt(f, len, 1);
	for(int i=0;i<len;i++)
		f[i] = mul(f[i], f[i]);
	ntt(f, len, -1);
	for(int i=1;i<=m;i++) {
		bool p = (i >= 2 ? f[i - 2] : false);
		if( tag[i - 1] ) {
			if( !p ) ans.push_back(i);
		}
		else {
			if( p ) {
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	printf("%d\n", (int)ans.size());
	for(int i=0;i<(int)ans.size();i++)
		printf("%d ", ans[i]);
}