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

int n, q;
std::vector<PII> ans;
VI A;
std::deque<int> deq;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> q;
	A.resize(n);
	FOR(i, n) std::cin >> A[i], deq.push_back(A[i]);
	int max = *std::max_element(A.begin(), A.end());
	while(deq.front() != max){
		int a = deq.front();
		deq.pop_front();
		int b = deq.front();
		deq.pop_front();
		ans.push_back(MP(a, b));
		deq.push_front(std::max(a, b));
		deq.push_back(std::min(a, b));
	}
	VI nw;
	deq.pop_front();
	while(!deq.empty()){
		nw.push_back(deq.front());
		deq.pop_front();
	}
	FOR(_, q){
		ll m;
		std::cin >> m;
		m--;
		if(m < SZ(ans)){
			std::cout << ans[m].X << " " << ans[m].Y << "\n";
		}else{
			m -= SZ(ans);
			m %= SZ(nw);
			std::cout << max << " " << nw[m] << "\n";
		}
	}
	// TRAV(i, nw) std::cout << i << " ";
	return 0;
}