#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

constexpr ll MOD = 9999999900000001ll;
ll P = 31;

int dp[5005];
bool good[5005][5005];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, A, B;
	std::cin >> n >> A >> B;
	std::string s;
	std::cin >> s;

	std::vector<ll> pref(SZ(s)+1);
	std::vector<ll> pw(SZ(s)+1);
	pw[0] = 1;
	FOR(i, SZ(s)){
		pw[i+1] = (1ll * pw[i] * P)%MOD;
		pref[i+1] = (1ll * pref[i] * P + (s[i] - 'a'+1)) % MOD;
	}

	auto hash = [&](int a, int b){
		__int128 ehh = pref[a];
		ehh *= pw[b-a+1];
		ehh %= MOD;
		ll xd = (pref[b+1] - (ll)ehh)%MOD;
		xd += MOD;
		xd %= MOD;
		return xd;
	};

	// std::map<int, int> minpos;
	std::vector<PR<ll, PII>> heh;
	heh.reserve(SZ(s) * (SZ(s) + 1) / 2);
	FOR(i, SZ(s)){
		REP(j, i, SZ(s)){
			ll hsh = hash(i, j);
			// auto it = minpos.find(hsh);
			heh.push_back(MP(hsh, MP(i, j)));
			// if(it == minpos.end()) minpos[hsh] = i;
			// else{
			// 	good[i][j] = (it->Y <= i - (j-i+1));
			// }
		}
	}
	// assert(heh.size() <= SZ(s) * (SZ(s) + 1) / 2);
	std::sort(heh.begin(), heh.end());
	int left = 0;
	while(left < SZ(heh)){
		int right = left;
		int len = heh[left].Y.Y - heh[left].Y.X + 1;
		// assert(len > 0);
		while(right < SZ(heh)-1 && heh[right+1].X == heh[left].X){
			right++;
			assert(heh[right].Y.Y - heh[right].Y.X + 1 == len);
		}

		int mn = heh[left].Y.X;
		REP(i, left, right+1){
			// assert(mn <= heh[i].Y.X);
			if(mn <= heh[i].Y.X - len){
				good[heh[i].Y.X][heh[i].Y.Y] = true;
			}
		}

		left = right+1;
	}

	// auto good = [&](int a, int b){
	// 	return minpos[hash(a, b)] <= a - (b-a+1);
	// };

	dp[0] = A;
	REP(i, 1, SZ(s)){
		dp[i] = dp[i-1] + A;
		FOR(j, i){
			if(good[j+1][i])
				dp[i] = std::min(dp[i], dp[j] + B);
		}
	}

	std::cout << dp[SZ(s)-1] << "\n";

	return 0;
}