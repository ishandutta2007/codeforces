#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
int n, m; ll G[40 + 5];
int fa[40 + 5], siz[40 + 5];
int find(int x) {
	return fa[x] = (fa[x] == x ? x : find(fa[x]));
}
void unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if( fx != fy ) fa[fx] = fy, siz[fy] += siz[fx];
}
ll check(int x) {
	ll d[40 + 5] = {};
	for(int i=0;i<n;i++)
		d[i] = -1;
	queue<int>que; que.push(x); d[x] = 0;
	while( !que.empty() ) {
		int f = que.front(); que.pop();
		for(int i=0;i<n;i++)
			if( (G[f]>>i) & 1 ) {
				if( d[i] == -1 ) {
					d[i] = d[f] ^ 1;
					que.push(i);
				}
				else {
					if( d[i] != (d[f] ^ 1) )
						return 0;
				}
			}
	}
	return 2;
}
ll solve1() {
	ll ret1 = 1, ret2 = 1, ret3 = 1, ret4 = 1;
	for(int i=0;i<n;i++)
		if( fa[i] == i ) {
			ret1 <<= 1;
			ret2 = ret2*check(i);
			ret3 = (siz[i] == 1) ? (ret3<<1) : ret3;
			ret4 = (siz[i] == 1) ? (ret4<<1) : 0;
		}
	return ret2 - ret1 + (ret3<<1) - ret4;
}
ll f[1<<20];
void dfs1(int d, int mxd, int s1, int s2) {
	if( d == mxd ) {
		f[s1]++;
		return ;
	}
	dfs1(d + 1, mxd, s1, s2);
	if( !(s2 & (1LL<<d)) )
		dfs1(d + 1, mxd, s1|(1LL<<d), s2|G[d]);
}
int mid, t;
ll dfs2(int d, int mxd, ll s) {
	if( d == mxd ) {
		s = s & t, s = s ^ t;
		return f[s];
	}
	ll ret = dfs2(d + 1, mxd, s);
	if( !(s & (1LL<<d)) )
		ret += dfs2(d + 1, mxd, s|G[d]);
	return ret;
}
ll solve2() {
	mid = (n>>1), t = (1<<mid) - 1;
	dfs1(0, mid, 0, 0);
	for(int i=0;i<mid;i++)
		for(int j=0;j<=t;j++)
			if( j & (1LL<<i) ) f[j] += f[j^(1LL<<i)];
	return dfs2(mid, n, 0);
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++) fa[i] = i, siz[i] = 1;
	for(int i=1;i<=m;i++) {
		int x, y; scanf("%d%d", &x, &y), x--, y--;
		G[x] |= (1LL<<y), G[y] |= (1LL<<x), unite(x, y);
	}
	printf("%lld\n", (1LL<<n) + solve1() - (solve2()<<1));
}