#include <bits/stdc++.h>

typedef long long ll;

const int N = 200000;

std::vector<int>G[N + 5]; int m;
void adde(int u, int v) {
	G[u].push_back(v), G[v].push_back(u);
}

int fa[N + 5], n;
int find(int x) {return (fa[x] == x) ? x : (fa[x] = find(fa[x]));}
bool unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if( fx != fy ) {
		fa[fx] = fy;
		return true;
	} else return false;
}

struct edge{int u, v, w;}e[N + 5];

std::vector<edge>ve;

bool tag[N + 5];
bool check() {
	if( (ll)n * (n - 1) / 2 - m > n - 1 ) return false;
	else {
		for(int i=1;i<=n;i++) fa[i] = i;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) tag[j] = false;
			for(auto x : G[i]) tag[x] = true;
			for(int j=i+1;j<=n;j++) if( !tag[j] ) {
				ve.push_back((edge){i, j, 0});
				if( !unite(i, j) ) return false;
			}
		}
		return true;
	}
}

ll solve1() {
	int k = 0; for(int i=1;i<=m;i++) k ^= e[i].w;
	
	ll ans = 0;
	for(int i=1;i<=n;i++) fa[i] = i;
	for(auto x : ve) unite(x.u, x.v);
	for(int i=1;i<=m;i++) {
		tag[i] = unite(e[i].u, e[i].v);
		if( tag[i] ) ans += e[i].w;
	}
	
	for(int i=1;i<=n;i++) fa[i] = i;
	for(int i=1;i<=m;i++) if( tag[i] ) unite(e[i].u, e[i].v);
	for(int i=1;i<=m;i++) if( find(e[i].u) != find(e[i].v) )
		k = std::min(k, e[i].w);
	return ans + k;
}

void link(int x) {
	for(int i=1;i<=n;i++) tag[i] = false;
	for(auto y : G[x]) tag[y] = true;
	for(int i=1;i<=n;i++) if( !tag[i] ) unite(i, x);
}
ll solve2() {
	int mn = 1; for(int i=1;i<=n;i++) if( G[i].size() < G[mn].size() ) mn = i;
	for(int i=1;i<=n;i++) fa[i] = i; link(mn);
	for(int i=1;i<=n;i++) if( find(i) != mn ) link(i);
	
	ll ans = 0;
	for(int i=1;i<=m;i++) if( unite(e[i].u, e[i].v) ) ans += e[i].w;
	return ans;
}

int main() {
	scanf("%d%d", &n, &m); 
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		adde(e[i].u, e[i].v);
	}
	std::sort(e + 1, e + m + 1, [](const edge &a, const edge &b){
		return a.w < b.w;
	});
	
	if( check() ) printf("%lld\n", solve1());
	else printf("%lld\n", solve2());
}