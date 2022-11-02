#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 5000;
const int MAXM = 100000;
typedef long long ll;
struct edge{
	int u, v, id; ll w;
	bool flag;
}edges[MAXM + 5];
bool cmp(edge a, edge b) {
	return a.w < b.w;
}
int n, m, k;
void Read() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%I64d", &edges[i].u, &edges[i].v, &edges[i].w);
		edges[i].id = i;
	}
}
int fa[MAXN + 5];
int Find(int x) {
	if( x == fa[x] ) return x;
	return fa[x] = Find(fa[x]);
}
void Kruscal() {
	sort(edges+1, edges+m+1, cmp);
	for(int i=1;i<=n;i++)
		fa[i] = i;
	for(int i=1;i<=m;i++)
		if( edges[i].u != 1 && edges[i].v != 1 ) {
			if( Find(edges[i].u) != Find(edges[i].v) ) {
				edges[i].flag = true;
				fa[Find(edges[i].u)] = Find(edges[i].v);
			}
		}
}
int mini[MAXN + 5];
vector<int>List, G[MAXN + 5];
void addedge(int u, int v, int p) {
	G[u].push_back(p); G[v].push_back(p);
}
void dfs(int rt, int pre, int key) {
	mini[rt] = key;
	for(int i=0;i<G[rt].size();i++) {
		if( edges[G[rt][i]].u == rt ) {
			if( edges[G[rt][i]].v == pre ) continue;
			if( key == -1 || edges[key].w < edges[G[rt][i]].w ) dfs(edges[G[rt][i]].v, rt, G[rt][i]);
			else dfs(edges[G[rt][i]].v, rt, key);
		}
		else {
			if( edges[G[rt][i]].u == pre ) continue;
			if( key == -1 || edges[key].w < edges[G[rt][i]].w ) dfs(edges[G[rt][i]].u, rt, G[rt][i]);
			else dfs(edges[G[rt][i]].u, rt, key);
		}
	}
}
int main() {
	Read(); Kruscal();
	for(int i=1;i<=m;i++) {
		if( edges[i].u == 1 ) {
			if( mini[Find(edges[i].v)] == 0 ) {
				mini[Find(edges[i].v)] = i;
				edges[i].flag = true;
			}
			List.push_back(i);
		}
		else if( edges[i].v == 1 ) {
			if( mini[Find(edges[i].u)] == 0 ) {
				mini[Find(edges[i].u)] = i;
				edges[i].flag = true;
			}
			List.push_back(i);
			swap(edges[i].u, edges[i].v);
		}
	}
	ll ans = 0, res = 0;
	for(int i=1;i<=m;i++)
		if( edges[i].flag )
			ans += edges[i].w;
	int num = 0;
	for(int i=2;i<=n;i++)
		if( fa[i] == i ) num++;
	res = ans;
	if( num == k ) {
		printf("%d\n", n-1);
		for(int j=1;j<=m;j++)
			if( edges[j].flag )
				printf("%d ", edges[j].id);
		return 0;
	}
	for(int i=num+1;i<=k;i++) {
		for(int j=1;j<=n;j++)
			G[j].clear();
		for(int j=1;j<=m;j++)
			if( edges[j].flag )
				addedge(edges[j].u, edges[j].v, j);
		for(int j=0;j<G[1].size();j++) 
			dfs(edges[G[1][j]].v, 1, -1);
		int p = -1;
		for(int j=0;j<List.size();j++) {
			if( edges[List[j]].flag == true ) continue;
			if( p == -1 || edges[List[j]].w - edges[mini[edges[List[j]].v]].w < edges[p].w - edges[mini[edges[p].v]].w )
				p = List[j];
		 }
		 if( p == -1 ) break;
		 ans = ans + edges[p].w - edges[mini[edges[p].v]].w;
		 edges[mini[edges[p].v]].flag = false;
		 edges[p].flag = true;
		 res = min(res, ans);
		 if( i == k ) {
		 	printf("%d\n", n-1);
		 	for(int j=1;j<=m;j++)
				if( edges[j].flag )
					printf("%d ", edges[j].id);
		 	return 0;
		 }
	}
	printf("%d\n", -1);
}