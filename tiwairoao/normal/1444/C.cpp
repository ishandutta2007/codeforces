#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
#define pr std::make_pair

const int N = 500000;

pii e[N + 5]; int cnt;
std::map<pii, int>mp;
int id(int x, int y) {
	if( x > y ) std::swap(x, y);
	if( !mp.count(pr(x, y)) )
		e[mp[pr(x, y)] = (++cnt)] = pr(x, y);
	return mp[pr(x, y)];
}
std::vector<pii>vec[N + 5];

int fa[N + 5], rnk[N + 5], val[N + 5];
pii find(int x) {
	if( fa[x] == x ) return pr(x, 0);
	else {
		pii p = find(fa[x]);
		return pr(p.first, p.second ^ val[x]);
	}
}

struct node{
	int *p, k;
}stk[4*N + 5]; int tp;
void restore() {
	while( tp ) (*stk[tp].p) = stk[tp].k, tp--;
}
bool unite(int x, int y) {
	pii fx = find(x), fy = find(y);
	if( fx.first == fy.first ) {
		return fx.second != fy.second;
	} else {
		int kx = fx.first, ky = fy.first;
		if( rnk[kx] < rnk[ky] ) std::swap(kx, ky);
		if( rnk[kx] == rnk[ky] ) stk[++tp] = (node){rnk + kx, rnk[kx]}, rnk[kx]++;
		stk[++tp] = (node){fa + ky, fa[ky]}, fa[ky] = kx;
		stk[++tp] = (node){val + ky, val[ky]}, val[ky] = (fx.second ^ fy.second ^ 1);
		return true;
	}
}

bool tag[N + 5];

int c[N + 5], n, m, k;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=n;i++) scanf("%d", &c[i]), fa[i] = i, val[i] = 0;
	for(int i=1,u,v;i<=m;i++)
		scanf("%d%d", &u, &v), vec[id(c[u], c[v])].push_back(pr(u, v));
	
	int siz = k;
	for(int i=1;i<=cnt;i++) if( e[i].first == e[i].second ) {
		tp = 0;
		for(auto x : vec[i]) if( !unite(x.first, x.second) )
			tag[e[i].first] = true;
		if( tag[e[i].first] ) siz--;
	}
	
	ll ans = 1ll * siz * (siz - 1) / 2;
	for(int i=1;i<=cnt;i++) if( e[i].first != e[i].second ) {
		if( tag[e[i].first] || tag[e[i].second] ) continue;
		
		bool flag = true; tp = 0;
		for(auto x : vec[i]) if( !unite(x.first, x.second) ) {
			flag = false;
			break;
		}
		restore(); if( !flag ) ans--;
	}
	
	printf("%lld\n", ans);
}