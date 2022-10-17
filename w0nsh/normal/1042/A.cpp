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
	int n, m;
	std::cin >> n >> m;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	int max = 0;
	FOR(i, n) max = std::max(max, A[i]);
	int odp2 = max + m;	
	int free = 0;
	FOR(i, n) free += max - A[i];
	m -= free;
	int odp1;
	if(m <= 0) odp1 = max;
	else odp1 = max + m/n + (m%n == 0 ? 0 : 1);
	std::cout << odp1 << " " << odp2 << "\n"; 
	return 0;
}