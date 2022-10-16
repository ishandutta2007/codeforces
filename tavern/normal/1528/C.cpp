#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (int)(x); i < (int)(y); ++i)
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
typedef pair<int, int> pii;

const int maxn = 3e5 + 5;

int n, clk, ans;
int in[maxn], out[maxn];
set<pii> R;
vector<int> S[maxn], T[maxn];

inline void clear(){
	FOR(i, 0, n)
		S[i].clear(), T[i].clear();
	R.clear();
	clk = ans = 0;
	return; 
}

inline void dfs2(int u){
	in[u] = ++clk;
	FOR(i, 0, T[u].size())
		dfs2(T[u][i]);
	out[u] = clk;
	return;
}

inline pii findAnc(int u){
	set<pii>::iterator it = R.lower_bound(MP(in[u] + 1, -1));
	if(it == R.begin())
		return MP(-1, -1);
	pii ret = *(--it);
	if(ret.fst <= in[u] && ret.snd >= out[u])
		return ret;
	return MP(-1, -1);
}

inline pii findDes(int u){
	set<pii>::iterator it = R.lower_bound(MP(in[u], -1));
	if(it == R.end())
		return MP(-1, -1);
	pii ret = *it;
	if(ret.fst >= in[u] && ret.snd <= out[u])
		return ret;
	return MP(-1, -1);
}

inline void dfs1(int u){
	pii p = findAnc(u), q = findDes(u);
	if(~p.fst)
		R.erase(p), R.insert(MP(in[u], out[u]));
	else if(!~q.fst)
		R.insert(MP(in[u], out[u]));
	ans = max(ans, (int)R.size());	
	
	FOR(i, 0, S[u].size())
		dfs1(S[u][i]);
	if(~p.fst)
		R.insert(p), R.erase(MP(in[u], out[u]));
	else if(!~q.fst)
		R.erase(MP(in[u], out[u]));
	return; 
}

inline void solve(){
	scanf("%d", &n);
	clear();
	FOR(i, 1, n){
		int p; scanf("%d", &p); --p;
		S[p].PB(i);
	}
	FOR(i, 1, n){
		int p; scanf("%d", &p); --p;
		T[p].PB(i);
	}
	
	dfs2(0);
	dfs1(0);
	printf("%d\n", ans);
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}