#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

struct MaxQueue{
	std::deque<PR<ll, int> > deq;
	int size = 0;

	ll max(){
		if(deq.empty()) return 0;
		return deq.back().X;
	}

	void pop_back(){
		if(deq.empty()) return;
		size--;
		deq.back().Y--;
		if(deq.back().Y == 0) deq.pop_back();
	}

	void push_front(ll a){
		size++;
		int cnt = 1;
		while(!deq.empty() && deq.front().X <= a) cnt += deq.front().Y, deq.pop_front();
		deq.push_front(MP(a, cnt));
	}
};

int n, k, x;
VI A;
ll dp[5005][5005];
MaxQueue que[5005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k >> x;
	A.resize(n+1);
	FOR(i, n) std::cin >> A[i+1];
	REP(i, 1, n+1){
		if(i <= k) dp[i][1] = A[i];
//		REP(pl, 1, k+1) REP(j, 1, i) if(i-pl >= 1 && dp[i-pl][j] > 0)
//			dp[i][j+1] = std::max(dp[i][j+1], dp[i-pl][j] + A[i]);
		REP(j, 1, 5005) if(que[j].size > k) que[j].pop_back();
		REP(j, 1, i) if(que[j].max() > 0) dp[i][j+1] = que[j].max() + A[i];
		REP(j, 1, 5005) que[j].push_front(dp[i][j]);
	}
	ll mx = 0;
	FOR(i, k) mx = std::max(mx, dp[n-i][x]);
	if(mx == 0) std::cout << -1 << "\n";
	else std::cout << mx << "\n";
	return 0;
}