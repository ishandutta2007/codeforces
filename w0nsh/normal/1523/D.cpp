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

int n, m, p;
std::vector<ll> A;

int los(int a, int b){
	return a + (((1ll*std::rand())<<6) + std::rand())%(b-a+1);
}

int compress(ll a, ll mask){
	int ret = 0;
	int cnt = 0;
	FOR(i, m) if(mask & (1ll<<i)){
		if(a & (1ll << i)) ret |= (1<<cnt);
		cnt++;
	}
	return ret;
}

ll decompress(int a, ll mask){
	ll ret = 0;
	int pos = 0;
	FOR(i, m) if(mask & (1ll<<i)){
		if(a & (1<<pos)) ret |= (1ll<<i);
		pos++;
	}
	return ret;
}

std::string solve(){
	ll mask = A[los(0, n-1)];

	VI B(n);
	int M = __builtin_popcountll(mask);
	assert(M <= 15);
	FOR(i, n) {
		B[i] = compress(A[i], mask);
		B[i] = ((1<<M)-1)^B[i];
	}

	VI F(1<<M);
	FOR(i, n) F[B[i]]++;

	FOR(i, M){
		FOR(ms, 1<<M){
			if(ms & (1<<i)){
				F[ms] += F[ms ^ (1<<i)];
			}
		}
	}

	int best = 0;
	FOR(ms, 1<<M){
		if(F[ms ^ ((1<<M)-1)] >= (n+1)/2){
			if(__builtin_popcount(ms) > __builtin_popcount(best)){
				best = ms;
			}
		}
	}

	ll heh = decompress(best, mask);
	std::string s;
	FOR(i, m){
		if(heh & (1ll<<i)) s.push_back('1');
		else s.push_back('0');
	}
	return s;
}

int cnt_ans = 0;
std::string ans;

int main(){
	std::srand(std::time(0) + 666);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m >> p;
	A.resize(n);
	FOR(i, n){
		std::string s;
		std::cin >> s;
		ll num = 0;
		FOR(j, m) if(s[j] == '1') num |= (1ll << j);
		A[i] = num;
	}

	FOR(j, m) ans.push_back('0');

	FOR(_, 15){
		auto xd = solve();
		int cnt = 0;
		FOR(i, m) if(xd[i] == '1') cnt++;
		if(cnt > cnt_ans) {
			cnt_ans = cnt;
			ans = xd;
		}
	}

	std::cout << ans << "\n";

	return 0;
}