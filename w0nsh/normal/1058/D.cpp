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

int n, m, k;

void fail(){
	std::cout << "NO\n";
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	ll mult = 2ll*n*m;
	if(mult % k != 0) fail();
	ll a, b;
	if(std::__gcd(2*n, k) > 1){
		a = 2*n / std::__gcd(2*n, k);
		k /= std::__gcd(2*n, k);
		b = m / k;
	}else if(std::__gcd(2*m, k) > 1){
		b = 2*m / std::__gcd(2*m, k);
		k /= std::__gcd(2*m, k);
		a = n / k;
	}else fail();
	std::cout << "YES\n";
	// std::cout << a << "," << b << "\n";
    std::cout << n << " " << m << "\n";
    std::cout << n-a << " " << m << "\n";
    std::cout << n << " " << m-b << "\n";
    // if(a*b != 2ll*n*m/orig_k){
    //     std::cout << "XDDDD" << std::endl;
    //     return 1;
    // }
	return 0;
}