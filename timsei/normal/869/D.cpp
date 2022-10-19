#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mpx 0

const int N = 1e9 + 5;

const int M = 2005;
const int mod = 1e9 + 7;

int n , m , fir[M] , to[M] , cnt , val[M] , ans , MaxSize , ne[M];

struct Edge {
	int from , to;
}E[5];

int getsize(int x) {
	int l = x , r = x;
	int ans = 0;
	while(1) {
		ans += (min(r , n) - min(l , n)) + 1;
		l = l * 2; r = r * 2 + 1;
		if(l > n) return ans;
	}
}

int LCA(int x , int y) {
	if(x == y) return x;
	if(x > y) return LCA(x >> 1 , y);
	return LCA(x , y >> 1);
}

int id[M] , sz , fa[M] , dep[M];
map<int,int>Map;

int newnode(int x) {
	if(Map[x]) return Map[x];
	id[++ sz] = x; Map[x] = sz; return sz;
}

void add(int x , int y) {
	ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y;
}

void link(int x , int y) {
	add(x , y); add(y , x);
}

void paint(int x , int y) {
	if(x == y) return;
	link(newnode(x) , newnode(x >> 1));
	paint(x >> 1 , y);
}

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

bool vis[M];

void getSize(int x , int f) {
	if(vis[x]) return;
	vis[x] = 1;
	fa[x] = f; dep[x] = dep[f] + 1;
	vector<int>son; son.clear();
	val[x] = getsize(id[x]);
	Foreachson(i , x) {
		int V = to[i];
		if(V == f) continue;
		getSize(V , x);
		son.push_back(id[V]);
	}
	sort(son.begin() , son.end());
	son.erase(unique(son.begin() , son.end()) , son.end());
	for(int i = 0;i <(int) son.size();i ++) {
		val[x] -= getsize(son[i]);
	}
}

void build(void) {
	newnode(1);
	for(int i = 1;i <= m;i ++) {
		int lca = LCA(E[i].from , E[i].to);
		paint(E[i].from , lca); paint(E[i].to , lca); paint(lca , 1);
	}
	getSize(1 , 0);
}

vector<int>P , now;



int Lca(int x , int y) {
	if(x == y) return x;
	if(dep[x] < dep[y]) swap(x , y);
	return Lca(fa[x] , y);
}

void note(int x , int y) {
	if(dep[x] < dep[y]) swap(x , y);
	vis[x] = 1; if(x == y) return;
	note(fa[x] , y);
}

bool check(int x , int y) {
	if(vis[x] || vis[y]) return 0;
	if(x == y) return 1;
	if(dep[x] < dep[y]) swap(x , y);
	return check(fa[x] , y);
}

int jump(int x) {
	int cur = x;
	for(int i = 0;i < now.size();i ++) {
		int S = newnode(E[now[i]].from);
		int lca = Lca(S , cur);
		if(!check(S , lca) || !check(cur , lca)) return -1;
		note(S , lca); note(cur , lca);
		cur = newnode(E[now[i]].to);
		if(vis[cur]) return -1;
	}
	vis[cur] = 1;
	return cur;
}

int dfs(int now , int f) {
	if(now == -1) return 0;
	int res = val[now]; vis[now] = 1;
	Foreachson(i , now) {
		int V = to[i];
		if(vis[V]) continue;
		res += dfs(V , now);
	} 
	return res % mod;
}

void dance(void) {
	now = P; 
	sort(now.begin() , now.end());
	do {
		for(int i = 1;i <= sz;i ++) {
			for(int j = 1;j <= sz;j ++) vis[j] = 0;
			int cur = jump(i);
			int dance;
			ans += (dance = dfs(cur , 0)) * val[i] % mod;
			ans %= mod;
		}
	} while(next_permutation(now.begin() , now.end()));
}

void DFS(int x) {
	if(x == m + 1) {
		dance(); return;
	}
	P.push_back(x);
	DFS(x + 1);
	P.pop_back();
	swap(E[x].from , E[x].to);
	P.push_back(x);
	DFS(x + 1);
	P.pop_back();
	DFS(x + 1);
}

void doit(void) {
	DFS(1);
}

main(void) {
	scanf("%lld%lld",&n,&m);
	if(n == 1) {
		puts("1"); return 0;
	}
	for(int i = 1;i <= m;i ++) {
		scanf("%lld%lld",&E[i].from , &E[i].to);
	}
	build();
	doit();
	printf("%lld\n" ,ans);
	return 0;
}