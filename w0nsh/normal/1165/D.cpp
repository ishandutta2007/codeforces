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

ll lcm(ll a, ll b){
	ll gc = std::__gcd(a, b);
	return a/gc*b;
}

std::vector<ll> get_divisors(ll a){
	std::vector<ll> ret;
	for(ll i = 2; i*i <= a; ++i){
		if(a%i == 0){
			ret.push_back(i);
			if(i*i != a) ret.push_back(a/i);
		}
	}
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::vector<ll> A(n);
		FOR(i, n) std::cin >> A[i];
		std::sort(A.begin(), A.end());
		ll licz = A[0]*A.back();
		bool wrong = false;
		FOR(i, (n+1)/2){
			if(A[i]*A[SZ(A)-1-i] != licz) wrong = true;
		}
		auto xd = get_divisors(licz);
		std::sort(xd.begin(), xd.end());
		if(SZ(xd) != SZ(A)) wrong = true;
		else{
			FOR(i, n) if(A[i] != xd[i]) wrong = true;
		}
		if(wrong) std::cout << -1 << "\n";
		else std::cout << licz << "\n";
		// int n;
		// std::cin >> n;
		// ll lc = 1;
		// bool wrong = false;
		// std::vector<ll> A;
		// FOR(i, n){
		// 	ll cur;
		// 	std::cin >> cur;
		// 	A.push_back(cur);
		// 	lc = lcm(cur, lc);
		// 	if(lc > 1000000ll*1000000ll){
		// 		wrong = true;
		// 		break;
		// 	}
		// }
		// if(!wrong){
		// 	std::sort(A.begin(), A.end());
		// 	if(lc == A.back()){
		// 		ll nw = A[0];
		// 		REP(i, 1, n){
		// 			if(A[i] != nw*A[0]){
		// 				wrong = true;
		// 				break;
		// 			}
		// 			nw *= A[0];
		// 		}
		// 		if(!wrong) lc = lc*A[0];
		// 	}else{
		// 		auto xd = get_divisors(lc);
		// 		if(SZ(xd) != SZ(A)) wrong = true;
		// 		else{
		// 			std::sort(xd.begin(), xd.end());
		// 			FOR(i, n) if(A[i] != xd[i]) wrong = true;
		// 		}
		// 	}
		// }
		// if(wrong) std::cout << -1 << "\n";
		// else std::cout << lc << "\n";
	}
	return 0;
}