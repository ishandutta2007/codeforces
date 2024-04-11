#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdlib>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = a; i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

ll n;
std::vector<ll> A;
const ll MOD = 998244353;

std::vector<ll> p2;
void calc_p2(){
	p2.resize(n);
	p2[0] = 1;
	REP(i, 1, SZ(p2)){
		p2[i] = p2[i-1]<<1;
		p2[i] %= MOD;
	}
}

void answer(){
	ll ans = 0;
	FOR(i, n){
		ans += (A[i]*p2[n-i-1])%MOD;
		ans %= MOD;
	}
	FOR(i, n-1){
		ans += ((((n-i-1)*A[i])%MOD)*p2[n-i-2])%MOD;
		ans %= MOD;
	}
	std::cout << ans << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	calc_p2();
	FOR(i, n) std::cin >> A[i];
	answer();
	return 0;
}