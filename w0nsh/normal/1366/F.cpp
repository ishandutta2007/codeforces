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

std::vector<std::vector<PII> > g;
std::vector<PR<PII, int> > edges;

const int MOD = 1000000007;
const ll INF = 1000000000ll*1000000000ll;

const int ILE = 2002;
int dp[2005][2005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m, q;
	std::cin >> n >> m >> q;
	g.resize(n);
	FOR(i, m){
		int a, b, c;
		std::cin >> a >> b >> c;
		a--;b--;
		g[a].push_back(MP(b, c));
		g[b].push_back(MP(a, c));
		edges.push_back(MP(MP(a, b), c));
	}

	FOR(i, ILE) FOR(j, ILE) dp[i][j] = -1;
	dp[0][0] = 0;
	
	REP(k, 1, ILE){
		FOR(i, n){
			TRAV(ch, g[i]){
				if(dp[ch.X][k-1] == -1) continue;
				dp[i][k] = std::max(dp[i][k], dp[ch.X][k-1]+ch.Y);
			}
		}
	}

	std::map<ll, ll> map;

	ll ans = 0;

	REP(k, 1, std::min(q+1, ILE)){
		TRAV(ed, edges){
			ll b = std::max(dp[ed.X.X][k], dp[ed.X.Y][k]);
			if(b == -1) continue;
			b -= 1ll*k*ed.Y;
			if(map.count(ed.Y) == 0) map[ed.Y] = -INF;
			map[ed.Y] = std::max(map[ed.Y], b);
		}

		ll best = 0;
		TRAV(pr, map){
			ll cur = 1ll*pr.X*k + pr.Y;
			if(cur > best) best = cur;
		}

//		std::cout << k << ": " << best << std::endl;
		ans = (ans+best)%MOD;
	}

	std::vector<PR<ll, ll> > vec;

	auto fun = [&](PR<ll, ll> a, PR<ll, ll> b, PR<ll, ll> c){
		// przec(a, c) <= przec(a, b)
		ll u1 = a.Y-c.Y;
		ll d1 = c.X-a.X;
		if(d1 < 0) d1 *= -1, u1 *= -1;
		ll u2 = a.Y-b.Y;
		ll d2 = b.X-a.X;
		if(d2 < 0) d2 *= -1, u2 *= -1;
		return u1*d2 <= u2*d1;
	};

	TRAV(pr, map){
		while(SZ(vec) >= 2 && fun(vec[SZ(vec)-2], vec.back(), MP(pr.X, pr.Y))){
			vec.pop_back();
		}
		vec.push_back(MP(pr.X, pr.Y));
	}

	auto eval = [&](PR<ll, ll> f, ll x){
		__int128_t xd = x;
		__int128_t a = f.X;
		__int128_t b = f.Y;
		return xd*a+b;
	};

	VI bad(SZ(vec)-1);
	FOR(i, SZ(vec)-1){
		int left = 0;
		int right = q+2;
		while(left < right){
			int mid = (left+right)/2;
			
			if(eval(vec[i], mid) >= eval(vec[i+1], mid)) left = mid+1;
			else right = mid;
		}

		bad[i] = left;
	}
	bad.push_back(q+1);

	int from = ILE;
	FOR(i, SZ(vec)){
		int upto = bad[i]-1;
		upto = std::min(upto, q);

		//std::cerr << i << ": " << from << " - " << upto << std::endl;

		if(from <= upto){
			ll a = vec[i].X%MOD;
			ll b = vec[i].Y%MOD;
			if(b < 0) b += MOD;
			ll il = upto-from+1;
			ans = (ans+1ll*il*b)%MOD;
			int cg = (1ll*(from-1)*il)%MOD;
			cg = (cg+1ll*il*(il+1)/2)%MOD;
			ans = (ans+1ll*a*cg)%MOD;
		}

		from = std::max(from, upto+1);
	}

	std::cout << ans << "\n";

	return 0;
}