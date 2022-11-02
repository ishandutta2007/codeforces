#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 500000;
const int INF = (1 << 30);

int read() {
	int x = 0; char ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( '0' <= ch && ch <= '9' ) x = 10 * x + ch - '0', ch = getchar();
	return x;
}

int stk[MAXN + 5], tp;
int l[MAXN + 5], r[MAXN + 5];
ll f[MAXN + 5], g[MAXN + 5];
int ans[MAXN + 5];

int m[MAXN + 5], n;
int main() {
	n = read();
	for(int i=1;i<=n;i++)
		m[i] = read();
	m[0] = m[n + 1] = 0;
	
	stk[tp = 1] = 0;
	for(int i=1;i<=n;i++) {
		while( tp >= 1 && m[stk[tp]] >= m[i] )
			tp--;
		l[i] = stk[tp], stk[++tp] = i;
	}
	
	stk[tp = 1] = n + 1;
	for(int i=n;i>=1;i--) {
		while( tp >= 1 && m[stk[tp]] >= m[i] )
			tp--;
		r[i] = stk[tp], stk[++tp] = i;
	}
	
	for(int i=1;i<=n;i++)
		f[i] = f[l[i]] + 1LL*(i - l[i])*m[i];
	for(int i=n;i>=1;i--)
		g[i] = g[r[i]] + 1LL*(r[i] - i)*m[i];
		
	ll res = 0; int pos = 0;
	for(int i=1;i<=n;i++)
		if( res < f[i] + g[i] - m[i] )
			res = f[i] + g[i] - m[i], pos = i;
	int p = pos;
	while( p > 0 ) {
		for(int i=l[p]+1;i<=p;i++)
			ans[i] = m[p];
		p = l[p];
	}
	p = pos;
	while( p < n + 1 ) {
		for(int i=p;i<=r[p]-1;i++)
			ans[i] = m[p];
		p = r[p];
	}
	
	for(int i=1;i<=n;i++)
		printf("%d ", ans[i]);
}