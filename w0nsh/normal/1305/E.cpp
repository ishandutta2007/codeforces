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
	int n, m;
	std::cin >> n >> m;
	int ile = 0;
	VI A;
	while(SZ(A) < n && ile < m){
		int cur = SZ(A)+1;
		A.push_back(cur);
		ile += (cur-1)/2;
	}
	if(ile < m){
		std::cout << -1;
		return 0;
	}
	int pocz = SZ(A)-1;
	while(ile > m){
		A.back()++;
		ile -= pocz/2;
		pocz--;
		ile += pocz/2;
		assert(pocz > 0);
	}

	int s = 1000000000/2;
	while(SZ(A) < n){
		A.push_back(s);
		s += 30005;
	}
/*
	int xd =0 ;
	FOR(i, SZ(A)){
		REP(j, i+1, SZ(A)){
			REP(k, j+1, SZ(A)){
				if(A[i] + A[j] == A[k]) xd++;
			}
		}
	}
*/
	TRAV(i, A) std::cout << i << " ";
	
//	assert(xd == m);

	return 0;
}