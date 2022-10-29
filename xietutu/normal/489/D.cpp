#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
struct edge {
	int v; edge* next;
};
int g[3005][3005];
long long ans;
struct gra {
	edge ES[100005],* tot[3005];
	int EC;
	void add(int u,int v) {
		ES[++EC].v = v; ES[EC].next = tot[u]; tot[u] = ES + EC;
	}
} in,out;
void work(int x) {
	for (edge* e1 = in.tot[x]; e1; e1 = e1->next)
		for (edge* e2 = out.tot[x]; e2; e2 = e2->next) 
			++g[e1->v][e2->v];	
}
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m; ++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		in.add(v,u); out.add(u,v);
	}
	for (int i = 1; i <= n; ++i) work(i);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j && g[i][j] >= 2) 
				ans += (long long)(g[i][j]) * (long long)(g[i][j] - 1) / 2;
	std::cout << ans << std::endl;
}