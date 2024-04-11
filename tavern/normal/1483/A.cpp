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

const int maxn = 1e5 + 5;
const int maxm = maxn;

int n, m;
int cnt[maxn], ans[maxm], sz[maxm];
vector<int> buck[maxn], vec[maxm];

inline void solve(){
	scanf("%d%d", &n, &m);
	
	FOR(i, 0, n)
		buck[i].clear(), cnt[i] = 0;
	FOR(i, 0, m)
		vec[i].clear(), ans[i] = -1;
	
	FOR(i, 0, m){
		scanf("%d", sz + i);
		FOR(j, 0, sz[i]){
			int x; scanf("%d", &x);
			--x;
			vec[i].PB(x);
			buck[x].PB(i);
		}
	}
	
	int half = (m + 1) >> 1;
	
	FOR(i, 0, n) if(buck[i].size() <= half){
		FOR(j, 0, buck[i].size())
			ans[buck[i][j]] = i;
	}
	
	bool f = 0;
	FOR(i, 0, m) if(vec[i].size() == 1 && !~ans[i]){
		if(cnt[vec[i][0]] < half)
			ans[i] = vec[i][0], ++cnt[vec[i][0]];
		else{
			puts("NO");
			return;
		}
	}
	
	FOR(i, 0, m) if(!~ans[i]){
		int x = -1;
		FOR(j, 0, vec[i].size()) if(!~x || cnt[vec[i][j]] < cnt[x])
			x = vec[i][j];
		if(!~x){
			puts("NO");
			return;
		}
		ans[i] = x;
		++cnt[x];
	}
	
	puts("YES");
	FOR(i, 0, m)
		printf("%d ", ans[i] + 1); puts("");
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}