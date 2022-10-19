#include <bits/stdc++.h>
using namespace std;

const int N = 6e3 + 5;
const int M = N * 2;

int fir[N], ne[M], to[M], cnt = 1, x, y, n, m, du[N], cur[N];

void add(int x, int y) {
	ne[++ cnt] = fir[x];
	fir[x] = cnt;
	to[cnt] = y;
}

void link(int x, int y) {
	add(x, y);
	add(y, x);
}

#define forw(i, x) for(int i = fir[x]; i; i = ne[i])

int fa[N], vis[N], ban[M];

int getf(int x) {
	return (fa[x] == x) ? x : fa[x] = getf(fa[x]);
}

vector <int> ans;

void print() {
	cout << ans.size() << endl;
	for(int i = 0; i < (int) ans.size(); ++ i)
	printf("%d ", ans[i]);
	puts("");
}

void flower(int x) {
	ans.push_back(-1);
	forw(i, x) {
		int V = to[i];
		if(ban[i]) {
			ans.push_back(V);
			ans.push_back(x);
		}
	}
}

bool connect() {
	for(int i = 1; i <= n; ++ i) fa[i] = i, vis[i] = 0;
	for(int i = 2; i <= cnt; i += 2) {
		if(ban[i] || ban[i ^ 1]) continue;
		int x = to[i], y = to[i ^ 1];
		vis[x] = vis[y] = 1;
		fa[getf(x)] = getf(y);
	}
	int tot = 0;
	for(int i = 1; i <= n; ++ i) if(vis[i]) 
	tot += (fa[i] == i);
	return tot == 1;
}

#define Foreachson(i, x) for(int &i = cur[x]; i; i = ne[i])

void dfs(int x) {
	Foreachson(i, x) {
		int V = to[i];
		if(vis[i / 2] || ban[i] || ban[i ^ 1]) continue;
		vis[i / 2] = 1;
		dfs(V);
	}
	ans.push_back(x);
}

void erluerPath(int s, int t)  {
	for(int i = 1; i <= n; ++ i) cur[i] = fir[i];
	memset(vis, 0, sizeof(vis));
	dfs(s);
	reverse(ans.begin(), ans.end());
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++ i) {
		scanf("%d%d", &x, &y);
		link(x, y);
		++ du[x];
		++ du[y];
	}
	if(!connect()) {
		puts("0");
		return 0;
	}
	set <int> G, H;
	for(int i = 1; i <= n; ++ i) if(du[i] & 1) G.insert(i);
	H = G;
	
	if(G.size() == 2) {
		erluerPath(*G.begin(), *G.rbegin());
		print();
		return 0;
	} else if(!G.size()) {
		int s = 0;
		for(int i = 1; i <= n; ++ i) if(du[i]) s = i;
		erluerPath(s, s);
		print();
		return 0;
	}
	
	for(int i = 1; i <= n; ++ i) {
		memset(ban, 0, sizeof(ban));
		G = H;
		if(du[i] & 1) G.erase(i);
		int now = du[i] & 1, ok = 1;
		forw(j, i) {
			int V = to[j];
			if(du[V] & 1) {
				G.erase(V);
				ban[j] = 1;
				now ^= 1;
			} else ok = 0;
		}
		
		
		if(now) G.insert(i);
		
		if(connect() && !ok && G.size() <= 2) {
			if(G.size() == 2 && G.find(i) != G.end()) {
				G.erase(i);
				erluerPath(*G.begin(), i);
				flower(i);
				print();
				return 0;
			} else if(G.size() == 0) {
				erluerPath(i, i);
				flower(i);
				print();
				return 0;
			}
		}
		
		if(now) G.erase(i);
		else G.insert(i);
		
		forw(j, i) {
			int V = to[j];
			if(du[V] & 1) {
				G.insert(V);
				ban[j] = 0;
				if(G.size() > 2);
				else
				if(!connect());
				else
				if(G.size() == 2 && G.find(i) == G.end());
				else {
					if(G.size() == 2) {
						G.erase(i);
						erluerPath(*G.begin(), i);
						flower(i);
						print();
						return 0;
					} else if(G.size() == 0) {
						erluerPath(i, i);
						flower(i);
						print();
						return 0;						
					}
				}
				ban[j] = 1;
				G.erase(V);
			}			
		}
	}
	puts("0");
	return 0;
}