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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, 2*n) A.push_back(A[i]);
	n = 3*n;
	std::vector<PII> deq;
	int pos = 0;
	VI ans(n, -1);
	VI from(n, -1);
	FOR(i, n){
		deq.push_back(MP(A[i], i));
		while(SZ(deq)-1-pos > 0){
			if(deq[SZ(deq)-2].X <= deq.back().X){
				from[deq[SZ(deq)-2].Y] = deq.back().Y;
				std::swap(deq.back(), deq[SZ(deq)-2]);
				deq.pop_back();
			}else break;
		}
		while(pos < SZ(deq)-1){
			if(deq[pos].X > 2*deq.back().X){
				ans[deq[pos].Y] = deq.back().Y;
				pos++;
			}else break;
		}
	}
	for(int i = n-1; i >= 0; --i){
		if(from[i] != -1) ans[i] = ans[from[i]];
	}
	FOR(i, n/3) std::cout << (ans[i] == -1 ? ans[i] : ans[i]-i) << " ";

	return 0;
}