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
const int sigma = 30;
const int maxn = 205;

bool f;
int n;
int vis[sigma];
char s[maxn];
vector<int> ans;
vector<int> g[sigma];

inline void dfs(int u, int p){
	vis[u] = true;
	ans.PB(u);
	FOR(i, 0, g[u].size()){
		int v = g[u][i];
		if(vis[v] && v != p){
			f = false;
			return;
		}
		else if(v == p)
			continue;
		dfs(v, u);
	}
	return;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s", s);
		n = strlen(s);
		FOR(i, 0, 26){
			g[i].clear();
			vis[i] = false;
		}
		ans.clear();
		FOR(i, 1, n){
			int u = s[i] - 'a', v = s[i - 1] - 'a';
			g[u].PB(v);
			g[v].PB(u);
		}
		f = true;
		FOR(i, 0, 26){
			sort(g[i].begin(), g[i].end());
			g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
			f &= (g[i].size() <= 2);
		}
		FOR(i, 0, 26) if(f){
			if(!vis[i] && g[i].size() <= 1)
				dfs(i, -1);
		}
		FOR(i, 0, 26)
			f &= vis[i];
		if(!f)
			puts("NO");
		else{
			puts("YES");
			FOR(i, 0, ans.size())
				putchar(ans[i] + 'a');
			puts("");
		}
	}
	return 0;
}