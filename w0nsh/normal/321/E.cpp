#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::pair<ll, ll> PLL;
typedef std::vector<int> VI;

const int INF = 2000000666;

int n, k;
int tab[4005][4005];
int pref[4005][4005];

inline void read(int* x){
	char c = 0;while(c < 33) c = getchar();while(c > 32){(*x) = c - '0';c = getchar();}
}

int sum(int a, int b){
	return (pref[b+1][b+1]-pref[a][b+1]-pref[b+1][a]+pref[a][a])/2;
}

int dp[805][4005];
// dp[g][i] = min[j<i](dp[g-1][j] + sum(j+1, i))
void calc(int lev){
	std::queue<PR<PII, PII> > que;
	que.push(MP(MP(0, n-1), MP(0, n-1)));
	while(!que.empty()){
		int a = que.front().X.X;
		int b = que.front().X.Y;
		int lo = que.front().Y.X;
		int hi = que.front().Y.Y;
		que.pop();
		if(a > b) continue;
		int mid = (a+b)/2;
		int opt = -1;
		REP(i, lo, hi+1){
			if(i >= mid) break;
			int cand = dp[lev-1][i] + sum(i+1, mid);
			if(cand < dp[lev][mid]){
				opt = i;
				dp[lev][mid] = cand;
			}
		}
		que.push(MP(MP(mid+1, b), MP(std::max(0, opt), hi)));
		if(opt != -1) que.push(MP(MP(a, mid-1), MP(lo, opt)));
	}
}

int main(){
	std::scanf("%d%d", &n, &k);
	FOR(i, n) FOR(j, n) read(&tab[i][j]);
	FOR(i, n) FOR(j, n) pref[i+1][j+1] = pref[i+1][j]+pref[i][j+1]-pref[i][j]+tab[i][j];
	FOR(i, 805) FOR(j, 4005) dp[i][j] = INF;
	FOR(i, n) dp[1][i] = sum(0, i);
	REP(i, 2, k+1) calc(i);
	std::printf("%d\n", dp[k][n-1]);
	return 0;
}