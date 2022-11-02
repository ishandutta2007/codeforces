#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 2000;
const ll INF = (1LL << 60);

ll a[MAXN + 5][MAXN + 5], f[MAXN + 5][MAXN + 5], g[MAXN + 5], t[MAXN + 5];
int l[MAXN + 5], s[MAXN + 5], c[2*MAXN + 5], n, m;

int lowbit(int x) {return x & -x;}
void update(int p, ll k) {
	for(int i=p;i<=m;i+=lowbit(i))
		g[i] = max(g[i], k);
}
ll query(int p) {
	ll ret = -INF;
	for(int i=p;i;i-=lowbit(i))
		ret = max(ret, g[i]);
	return ret;
}
ll get(int x, int y) {
	ll ret = 0;
	for(int p=x,q=y;p;p>>=1,q++)
		ret += 1LL*p*c[q];
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%d", &l[i]);
	for(int i=1;i<=n;i++) scanf("%d", &s[i]);
	for(int i=1;i<=n+m;i++) scanf("%d", &c[i]);
	for(int i=1;i<=m;i++) g[i] = -INF;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			f[i][j] = -INF, a[i][j] = get(j, i);
	
	for(int i=n;i>=1;i--) {
		for(int j=1;j<=n;j++) t[j] = -INF; t[1] = 0;
		int lb = max(l[i] - 15, 1);
		for(int j=lb;j<=l[i];j++) {
			for(int k=1;k<=n;k++) {
				if( f[j][k] == -INF ) continue;
				int p = (k >> (l[i] - j));
				t[p + 1] = max(t[p + 1], f[j][k] + a[j][k] - a[l[i]][p]);
			}
		}
		t[1] = max(t[1], query(lb - 1));
		for(int j=1;j<=n;j++) {
			if( f[l[i]][j] < t[j] - s[i] )
				f[l[i]][j] = t[j] - s[i], update(l[i], f[l[i]][j] + a[l[i]][j]);
		}
	}
	
	printf("%lld\n", max(0LL, query(m)));
}