#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const int maxn = 5005;

int n, m, cnt = 0, cnt1, cnt2, cnt3;
int col[maxn], bel[maxn], vis[maxn], f[maxn][maxn], p[maxn][maxn];
vector<pii> vec;
vector<int> g[maxn];

inline void dfs(int u, int &b, int &w, int c){
	col[u] = c;
	bel[u] = cnt;
	if(c)
		++b;
	else
		++w;
	FOR(i, 0, g[u].size()){
		int v = g[u][i];
		if(!~col[v]){
			dfs(v, b, w, c ^ 1);
		}
		else if(col[v] != (c ^ 1)){
			puts("NO");
			exit(0);
		}
	}
	return;
}

int main(){
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &cnt1, &cnt2, &cnt3);
	FOR(i, 0, m){
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		g[u].PB(v);
		g[v].PB(u);
	}
	memset(col, -1, sizeof(col));
	FOR(i, 0, n) if(!~col[i]){
		int b = 0, w = 0;
		dfs(i, b, w, 0);
		vec.PB(MP(b, w));
		++cnt;
	}
	f[0][0] = true;
	FOR(i, 0, vec.size()) REP(j, 0, n) if(f[i][j]){
		f[i + 1][j + vec[i].fst] = true;
		p[i + 1][j + vec[i].fst] = 0;
		f[i + 1][j + vec[i].snd] = true;
		p[i + 1][j + vec[i].snd] = 1;
	}
	if(f[vec.size()][cnt2] == true){
		for(int i = vec.size(), j = cnt2; i >= 0; --i){
			vis[i - 1] = p[i][j];
			if(!p[i][j])
				j -= vec[i - 1].fst;
			else
				j -= vec[i - 1].snd;
		}
		puts("YES");
		int tot = 0;
		FOR(i, 0, n){
			if((col[i] && !vis[bel[i]]) || (!col[i] && vis[bel[i]]))
				putchar('2');
			else{
				if(tot < cnt1)
					putchar('1'), ++tot;
				else
					putchar('3'), ++tot;
			}
		}
		puts("");
	}
	else
		puts("NO");
	return 0;
}