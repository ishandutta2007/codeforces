#include <bits/stdc++.h>

const int N = 200000;

struct edge{
	int u, v, w;
	friend bool operator < (const edge &a, const edge &b) {
		return a.w < b.w;
	}
}e[N + 5];

int fa[N + 5];
int find(int x) {
	return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
}
bool unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if( fx != fy ) {
		fa[fx] = fy; return true;
	} else return false;
}

int n, m, k;
void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	std::sort(e + 1, e + m + 1);
	
	for(int i=1;i<=n;i++) fa[i] = i;
	for(int i=1;i<=m;i++) {
		if( e[i].w > k ) {
			int cnt = 0;
			for(int j=1;j<=n;j++) if( find(j) == j )
				cnt++;
			
			if( cnt == 1 ) break;
			else {
				long long ans = 0;
				for(;i<=m;i++) if( unite(e[i].u, e[i].v) )
					ans += (e[i].w - k);
				printf("%lld\n", ans); return ;
			}
		} else unite(e[i].u, e[i].v);
	}
	
	int ans = (1 << 30);
	for(int j=1;j<=m;j++)
		ans = std::min(ans, std::abs(e[j].w - k));
	printf("%d\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}