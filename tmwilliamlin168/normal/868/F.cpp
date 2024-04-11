#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF=1e18;

int a[100001], cnt[100001], costL=0, costR=-1;
ll dp[2][100001], cost=0;

inline void moveCostL(int i) {
	while(costL<i) {
		--cnt[a[costL]];
		cost-=cnt[a[costL]];
		++costL;
	}
	while(costL>i) {
		--costL;
		cost+=cnt[a[costL]];
		++cnt[a[costL]];
	}
}

inline void moveCostR(int i) {
	while(costR<i) {
		++costR;
		cost+=cnt[a[costR]];
		++cnt[a[costR]];
	}
	while(costR>i) {
		--cnt[a[costR]];
		cost-=cnt[a[costR]];
		--costR;
	}
}

void computeDp(int i, int jl, int jr, int kl, int kr) {
	//cout << i << " " << jl << " " << jr << " " << kl << " " << kr << endl;
	if(jl>jr)
		return;
	int jm=(jl+jr)/2, km;
	moveCostR(jm);
	dp[i][jm]=INF;
	for(int k=kl; k<jm&&k<=kr; ++k) {
		moveCostL(k+1);
		if(dp[i^1][k]+cost<dp[i][jm]) {
			dp[i][jm]=dp[i^1][k]+cost;
			km=k;
		}
	}
	computeDp(i, jl, jm-1, kl, km);
	computeDp(i, jm+1, jr, km, kr);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i)
		cin >> a[i];
	memset(dp[0], 69, 8*n);
	dp[0][0]=0;
	for(int i=1; i<=k; ++i)
		computeDp(i&1, 1, n, 0, n-1);
	cout << dp[k&1][n];
}