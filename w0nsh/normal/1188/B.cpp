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

int n, p, k;
VI A;

int modpow(int a, int e){
	if(e == 0) return 1;
	int t = modpow(a, e/2);
	t = (1ll*t*t)%p;
	if(e&1) return (1ll*t*a)%p;
	return t;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> p >> k;
	A.resize(n);
	std::map<int, int> map;
	FOR(i, n){
		int a;
		std::cin >> a;
		int xd = (-1ll*k*a+1ll*modpow(a, 4))%p;
		if(xd < 0) xd += p;
		map[xd]++;
	}
	int xd = 0;
	TRAV(i, map){
		xd += (i.Y*(i.Y-1)/2ll)%p;
	}
	std::cout << xd;
	return 0;
}