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

int n, a, r, m;
VI A;

ll solve(int h){
	ll mn = 0;
	ll mx = 0;
	TRAV(i, A) mn += std::max(0, h-i), mx += std::max(0, i-h);
	
	ll wsp = std::min(mn, mx);
	mn -= wsp;
	mx -= wsp;
	return wsp*m + mn*a + mx*r;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> a >> r >> m;
	A.resize(n);
	m = std::min(m, a+r);

	FOR(i, n) std::cin >> A[i];
	std::sort(A.begin(), A.end());

	int left = 0;
	int right = 1000000006;
	while(right - left > 3){
		int h = (left+right)/2;
		if(solve(h) < solve(h+1)){
			right = h+1;
		}else{
			left = h;
		}
	}

	ll ans = 1000000000ll*1000000000ll*4ll;
	REP(i, std::max(0, left-2), right+2) ans = std::min(ans, solve(i));
	std::cout << ans << "\n";

	return 0;
}