#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pr make_pair

typedef pair<int, int> pii;

const int B = 320;
const int N = 100000;
const int HASHSIZE = 1000037;

int ans[N + 5], n, m, q;
vector<pii>edges[N + 5];

vector<pair<pii, int> >hsh[HASHSIZE + 5];
int func(const pii &x) {
	return (1ll * x.fi * 1313131 + x.se) % HASHSIZE;
}
void hinsert(const pii &x, const int &i) {
	hsh[func(x)].push_back(pr(x, i));
}
void hsearch(const pii &x) {
	int k = func(x);
	for(auto p : hsh[k]) if( x == p.fi )
		ans[p.se]++;
}

int fa[N + 5]; bool vis[N + 5];
int find(int x) {return fa[x] = (fa[x] == x ? x : find(fa[x]));}
bool unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if( fx != fy ) {
		fa[fx] = fy;
		return true;
	} else return false;
}

int x[N + 5], y[N + 5];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1,u,v,c;i<=m;i++) scanf("%d%d%d", &u, &v, &c), edges[c].push_back(pr(u, v));
	
	scanf("%d", &q);
	for(int i=1;i<=q;i++) scanf("%d%d", &x[i], &y[i]), hinsert(pr(min(x[i], y[i]), max(x[i], y[i])), i);
	for(int i=1;i<=n;i++) fa[i] = i;
	for(int i=1;i<=m;i++) {
		if( (int)edges[i].size() <= B ) {
			vector<int>vec;
			for(auto e : edges[i]) {
				if( !vis[e.fi] ) vec.push_back(e.fi), vis[e.fi] = true;
				if( !vis[e.se] ) vec.push_back(e.se), vis[e.se] = true;
				unite(e.fi, e.se);
			}
			for(unsigned u=0;u<vec.size();u++)
				for(unsigned v=u+1;v<vec.size();v++)
					if( find(vec[u]) == find(vec[v]) )
						hsearch(pr(min(vec[u], vec[v]), max(vec[u], vec[v])));
			for(auto k : vec) vis[k] = false, fa[k] = k;
		} else {
			for(auto e : edges[i]) unite(e.fi, e.se);
			for(int j=1;j<=q;j++)
				if( find(x[j]) == find(y[j]) ) ans[j]++;
			for(int j=1;j<=n;j++) fa[j] = j;
		}
	}
	for(int i=1;i<=q;i++) printf("%d\n", ans[i]);
	
}