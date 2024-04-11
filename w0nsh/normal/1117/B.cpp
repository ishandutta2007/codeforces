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

int n, m, k, m1, m2;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	FOR(i, n){
		int a;
		std::cin >> a;
		if(a > m1) m2 = m1, m1 = a;
		else if(a > m2) m2 = a; 
	}
	ll hap = 0;
	int xd = m/(k+1);
	m -= xd*(k+1);
	hap += 1ll*xd*m1*k;
	hap += 1ll*xd*m2;
	hap += 1ll*m*m1;
	std::cout << hap;
	return 0;
}