#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define PB push_back
#define MP make_pair
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double Lf;
typedef pair<int, int> pii;

const int maxn = 2e5 + 5;

int n;
int p[maxn], vis[maxn];
vector<pii> ans;

inline void swp(int x, int y){ ans.PB(MP(x, y)); return; }

inline void solve(vector<int> c1, vector<int> c2){
	if(c1.size() == 1 && c2.size() == 1)
		return;
	swp(c1[0], c2[0]);
	FOR(i, 1, c2.size())
		swp(c1[0], c2[i]);
	FOR(i, 1, c1.size())
		swp(c2[0], c1[i]);
	swp(c1[0], c2[0]);
	return;
}

inline void solve2(vector<int> c){
	if(c.size() == 1)
		return;
	if(c.size() == 2){
		FOR(i, 0, n)
			vis[i] = 0;
		int u = -1;
		FOR(i, 0, c.size())
			vis[c[i]] = true;
		FOR(i, 0, n) if(!vis[i])
			u = i;
		swp(u, c[0]);
		swp(u, c[1]);
		swp(u, c[0]);
	}
	else{
		swp(c[0], c[1]);
		swp(c[1], c[2]);
		FOR(i, 3, c.size())
			swp(c[1], c[i]);
		swp(c[0], c[2]);
		swp(c[0], c[1]);
	}
	return;
}

int main(){
	scanf("%d", &n);
	FOR(i, 0, n)
		scanf("%d", p + i), --p[i];
		
	vector<vector<int> > cyc;
	FOR(i, 0, n) if(!vis[i]){
		vector<int> vec;
		for(int j = i; !vis[j]; j = p[j])
			vis[j] = true, vec.PB(j);
		cyc.PB(vec);
	}
	
	FOR(i, 0, cyc.size() >> 1)
		solve(cyc[i << 1], cyc[i << 1 | 1]);
	if(cyc.size() & 1)
		solve2(cyc[cyc.size() - 1]);
		
	printf("%d\n", ans.size());
	FOR(i, 0, ans.size())
		printf("%d %d\n", ans[i].fst + 1, ans[i].snd + 1);
	return 0;
}