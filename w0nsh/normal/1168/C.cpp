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
typedef std::vector<int> VI;

const int INF = 1000000666;
int n, q;
VI A;
int dp[300005][20];
int last[20];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> q;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	std::vector<std::vector<PII> > queries(n);
	FOR(i, q){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		queries[a].push_back(MP(b, i));
	}
	FOR(i, 20) last[i] = n;
	FOR(i, n) FOR(j, 20) dp[i][j] = INF;
	std::vector<bool> ans(q);
	for(int i = n-1; i >= 0; --i){
		FOR(j, 20) if((1<<j) & A[i]){
			dp[i][j] = i;
			if(last[j] < n){
				FOR(k, 20){
					dp[i][k] = std::min(dp[i][k], dp[last[j]][k]);
				}
			}
			last[j] = i;
		}
		TRAV(que, queries[i]){
			FOR(j, 20) if((A[que.X]&(1<<j))){
				ans[que.Y] = ans[que.Y] | (dp[i][j] <= que.X);
			}
		}
	}
	FOR(i, q){
		if(ans[i]) std::cout << "Shi\n";
		else std::cout << "Fou\n";
	}
	return 0;
}