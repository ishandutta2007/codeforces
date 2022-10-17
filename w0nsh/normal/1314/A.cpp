#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n){
		std::cin >> A[i];
	}
	VI T(n);
	FOR(i, n) std::cin >> T[i];
	std::priority_queue<int> que;
	std::multiset<PII> set;
	FOR(i, n) set.insert(MP(A[i], T[i]));
	int last = 0;
	ll ans = 0;
	ll sum = 0;
	TRAV(i, set){
		while(last < i.X && SZ(que)){
			sum -= que.top();
			que.pop();
			ans += sum;
			last++;
		}
		last = i.X;
		que.push(i.Y);
		sum += i.Y;
	}
	while(SZ(que)){
		sum -= que.top();
		que.pop();
		ans += sum;
		last++;
	}
	std::cout << ans << "\n";
	
	
	return 0;
}