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

const int MOD = 1000000007;

int aryt2(ll a){
	return 1ll*(a%MOD)*((a+1)%MOD)%MOD;
}

int np(ll a, ll b){
	ll right = aryt2(b);
	ll left = (a == 1 ? 0 : aryt2(a-1));
	ll xd = right-left-(b-a+1);
	xd %= MOD;
	if(xd < 0) xd += MOD;
	return xd;
}

int pp(ll a, ll b){
	ll right = aryt2(b);
	ll left = (a == 1 ? 0 : aryt2(a-1));
	ll xd = right-left;
	xd %= MOD;
	if(xd < 0) xd += MOD;
	return xd;
}

int solve(ll a){
	ll ans = 0;
	ll p[2];
	p[0] = 1;
	p[1] = 1;
	ll ile = 1;
	int k = 0;
	ll done = 0;
	while(done < a){
		ll l = p[k];
		ll num = std::min(ile, a-done);
		done += num;
		ans = (ans + (k == 0 ? np(p[0], p[0]+num-1ll) : pp(p[1], p[1]+num-1ll)))%MOD;
		p[k] += num;
		ile *= 2;
		k = (k+1)%2;
	}
	return ans;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	ll l, r;
	std::cin >> l >> r;
	ll ans = solve(r)-(l == 1 ? 0 : solve(l-1));
	ans %= MOD;
	if(ans < 0) ans += MOD;
	std::cout << ans;
	return 0;
}