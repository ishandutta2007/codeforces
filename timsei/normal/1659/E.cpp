#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = N * 2;

int cnt, n, q, u, v, w, m;

struct Edge {
	int x, y, w;
	void input() {
		scanf("%d%d%d", &x, &y, &w);
	}
}who[M];

vector < Edge > odd, all;

struct Un {
	int fa[N], S[N];
	void init() {
		for(int i = 1; i <= n; ++ i) fa[i] = i, S[i] = 0;
	}
	
	int getf(int x) {
		return (fa[x] == x) ? x : fa[x] = getf(fa[x]);
	}
	
	void doit(int x, int y) {
		x = getf(x); y = getf(y);
		fa[x] = y;
	}
	
}All[30];

bool ok[N];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < 30; ++ i) All[i].init();
	for(int i = 1; i <= m; ++ i) {
		who[i].input();
	}
	for(int i = 1; i <= m; ++ i) {
		for(int j = 0; j < 30; ++ j) if(who[i].w & (1 << j)) {
			All[j].doit(who[i].x, who[i].y);
		}
		if(who[i].w % 2 == 0) ok[who[i].x] = ok[who[i].y] = 1;
	}
	for(int j = 0; j < 30; ++ j) {
		for(int i = 1; i <= n; ++ i) if(ok[i]) {
			All[j].S[All[j].getf(i)] = 1;
		}
	}
	for(cin >> q; q --;) {
		scanf("%d%d", &u, &v);
		bool ok = 1;
		for(int j = 0; j < 30; ++ j) {
			if(All[j].getf(u) == All[j].getf(v)) {
				ok = 0; puts("0"); break;
			}
		}
		if(!ok) continue;
		for(int j = 1; j < 30; ++ j) {
			if(All[j].S[All[j].getf(u)]) {
//				cerr << j <<' ' << All[j].getf(u) << endl;
				ok = 0; puts("1"); break;
			}
		}
		if(!ok) continue;
		puts("2");
	}
}