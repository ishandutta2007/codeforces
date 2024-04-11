#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

ll solve(std::string s, ll a, ll b){
	ll n = SZ(s);
	ll que = 0;
	ll ones = 0;
	ll zeros = 0;
	ll ns[2] = {0, 0};
	std::vector<ll> zlef(n), zrig(n), olef(n), orig(n);
	int ind = 0;
	TRAV(c, s){
		if(c == '?') que++;
		if(c != '1') zeros++, ns[1] += ones;
		else ones++, ns[0] += zeros;
		zlef[ind] = zeros;
		olef[ind] = ones;
		ind++;
	}
	ones = 0;
	zeros = 0;
	ind = n-1;
	for(int i = n-1; i >= 0; --i){
		if(s[i] != '1') zeros++;
		else ones++;
		zrig[ind] = zeros;
		orig[ind] = ones;
		ind--;
	}
	ll best = ns[0]*a + ns[1]*b;

	ll zdd = 0;
	ll odd = 0;
	// std::cerr << "ns " << ns[0] << " " << ns[1] << std::endl;
	FOR(i, n){
		if(s[i] == '?'){
			ns[0] -= (i == n-1 ? 0 : orig[i+1]);
			// std::cerr  << "odej " << orig[i+1] << std::endl;
			ns[1] -= (i == 0 ? 0 : olef[i-1]) + odd;
			ns[0] += (i == 0 ? 0 : zlef[i-1]) + zdd;
			ns[1] += (i == n-1 ? 0 : zrig[i+1]);
			zdd--;
			odd++;
		}

	// std::cerr << "aans " << ns[0] << " " << ns[1] << std::endl;

		best = std::min(best, ns[0]*a + ns[1]*b);
	}
	return best;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string s;
	ll a, b;
	std::cin >> s >> a >> b;
	auto fs = solve(s, a, b);
	std::reverse(s.begin(), s.end());
	std::swap(a, b);
	std::cout << std::min(fs, solve(s, a, b));
	return 0;
}