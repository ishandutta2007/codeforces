#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
const int MOD = 1000000007;
int modpow(int a, int e){
	int ret = 1;
	while(e > 0){
		if(e&1) ret = (1ll*ret*a)%MOD;
		a = (1ll*a*a)%MOD;
		e>>=1;
	}
	return ret;
}

VI fact, invfact;

int binco(int n, int k){
	if(k < 0 || k > n) return 0;
	int xd = (1ll*fact[n]*invfact[k])%MOD;
	return (1ll*xd*invfact[n-k])%MOD;
}

int pref[2005][2005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	const int N = 100000;
	fact.resize(N);
	invfact.resize(N);
	fact[0] = invfact[0] = 1;
	REP(i, 1, N) fact[i] = (1ll*fact[i-1]*i)%MOD, invfact[i] = modpow(fact[i], MOD-2);

	int n, m, r;
	std::cin >> n >> m >> r;

	std::vector<PR<PII, int> > A;
	FOR(i, n){
		int x, y, b;
		std::cin >> x >> y >> b;
		A.push_back(MP(MP(x, y), b));
	}

	auto dist = [&](PII a, PII b){
		return std::max(std::abs(a.X-b.X), std::abs(a.Y-b.Y));
	};

	TRAV(i, A){
		pref[i.X.X][i.X.Y]++;
	}

	FOR(i, 2005){
		FOR(j, 2005){
			if(i > 0) pref[i][j] += pref[i-1][j];
			if(j > 0) pref[i][j] += pref[i][j-1];
			if(i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];
		}
	}

	VI cnt(n);

	int ans = 0;
	FOR(i, n){
		PII xx = A[i].X;
		TRAV(pr, A){
			if(dist(xx, pr.X) <= r) cnt[i]++;
		}
	}

	auto g1 = [&](int res, int a){
		int xd = binco(res+a, m);
		xd -= binco(res, m);
		if(xd < 0) xd += MOD;
		return xd;
	};

	auto g2 = [&](int res, int a, int b){
		int xd = binco(res+a+b, m);
		xd -= binco(res+a, m) + binco(res+b, m);
		xd %= MOD;
		xd += binco(res, m);
		xd %= MOD;
		if(xd < 0) xd += MOD;
		return xd;
	};

	auto przec = [&](PII a, PII b){
		PII x = MP(std::max(a.X-r, b.X-r), std::min(a.X+r, b.X+r));
		PII y = MP(std::max(a.Y-r, b.Y-r), std::min(a.Y+r, b.Y+r));
		if(x.X > x.Y || y.X > y.Y) return 0;
		if(x.Y > 2000) x.Y = 2000;
		if(y.Y > 2000) y.Y = 2000;
		if(x.X < 1) x.X = 1;
		if(y.X < 1) y.X = 1;
		return pref[x.Y][y.Y]-pref[x.X-1][y.Y]-pref[x.Y][y.X-1]+pref[x.X-1][y.X-1];
	};

	FOR(i, n) FOR(j, n){
		if(i == j){
			int c = cnt[i];
			int rest = n-c;
			ans = (ans + 1ll*(1ll*g1(rest, c)*A[i].Y%MOD)*A[j].Y)%MOD;
		}else{
			int p = przec(A[i].X, A[j].X);
			int a = cnt[i]-p;
			int b = cnt[j]-p;
			assert(a >= 0 && b >= 0);
			assert(p >= 0);
			int rest = n-a-b-p;
			assert(rest >= 0);

			ans = (ans + 1ll*(1ll*g2(rest, a, b)*A[i].Y%MOD)*A[j].Y)%MOD;
			ans = (ans + 1ll*(1ll*g1(n-p, p)*A[i].Y%MOD)*A[j].Y)%MOD;
		}
	}

	std::cout << ans << "\n";

	return 0;
}