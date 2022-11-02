#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 5000;
const ll INF = ll(1E18);

int n, s, e; bool fs, fe;
ll f[MAXN + 5], g[MAXN + 5], x[MAXN + 5];
ll a[MAXN + 5], b[MAXN + 5], c[MAXN + 5], d[MAXN + 5];

void read() {
	scanf("%d%d%d", &n, &s, &e);
	for(int i=1;i<=n;i++) scanf("%lld", &x[i]);
	for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
	for(int i=1;i<=n;i++) scanf("%lld", &b[i]);
	for(int i=1;i<=n;i++) scanf("%lld", &c[i]);
	for(int i=1;i<=n;i++) scanf("%lld", &d[i]);
}

int main() {
	read();
	
	int cnt = 0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=cnt;j++) g[j] = f[j], f[j] = INF;
		if( i == s ) {
			if( fe ) {
				f[cnt + 1] = INF;
				for(int j=0;j<=cnt;j++) {
					f[j] = min(f[j], g[j] + c[i] + x[i]);
					f[j + 1] = min(f[j + 1], g[j] + d[i] - x[i]);
				}
				cnt++;
			}
			else {
				for(int j=0;j<=cnt;j++) {
					if( j ) f[j - 1] = min(f[j - 1], g[j] + c[i] + x[i]);
					f[j] = min(f[j], g[j] + d[i] - x[i]);
				}
			}
			fs = true;
		}
		else if( i == e ) {
			if( fs ) {
				f[cnt + 1] = INF;
				for(int j=0;j<=cnt;j++) {
					f[j] = min(f[j], g[j] + a[i] + x[i]);
					f[j + 1] = min(f[j + 1], g[j] + b[i] - x[i]);
				}
				cnt++;
			}
			else {
				for(int j=0;j<=cnt;j++) {
					if( j ) f[j - 1] = min(f[j - 1], g[j] + a[i] + x[i]);
					f[j] = min(f[j], g[j] + b[i] - x[i]);
				}
			}
			fe = true;
		}
		else {
			f[cnt + 1] = INF;
			for(int j=1;j<=cnt;j++) {
				f[j - 1] = min(f[j - 1], g[j] + c[i] + a[i] + 2*x[i]);
				f[j] = min(f[j], min(g[j] + c[i] + b[i], g[j] + d[i] + a[i]));
				f[j + 1] = min(f[j + 1], g[j] + b[i] + d[i] - 2*x[i]);
			}
			
			if( fs && (!fe) ) {
				f[0] = min(f[0], g[0] + d[i] + a[i]);
				f[1] = min(f[1], g[0] + b[i] + d[i] - 2*x[i]);
			}
			if( (!fs) && fe ) {
				f[0] = min(f[0], g[0] + c[i] + b[i]);
				f[1] = min(f[1], g[0] + b[i] + d[i] - 2*x[i]);
			}
			if( i == 1 )
				f[1] = min(f[1], g[0] + b[i] + d[i] - 2*x[i]);
			
			cnt++;
		}
	}
	
	
	printf("%lld\n", f[0]);
}
/*
i -> j :
xi - xj + ci + bj (j < i)
xj - xi + di + aj (j > i)
*/