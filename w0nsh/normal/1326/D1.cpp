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

const int MOD = 1000000007;
int P1;
int P2;
std::vector<int> p1, p2;
int n;
std::string s;
VI A;
bool check(int k, bool write=false){
	int l = -1;
	int r = n-k;
	int hash11 = 0;
	int hash12 = 0;
	int hash21 = 0;
	int hash22 = 0;
	int ind = 0;
	REP(i, n-k, n){
		hash11 = (1ll*hash11+1ll*A[i]*p1[ind])%MOD;
		hash12 = (1ll*hash12+1ll*A[i]*p1[k-1-ind])%MOD;
		hash21 = (1ll*hash21+1ll*A[i]*p2[ind])%MOD;
		hash22 = (1ll*hash22+1ll*A[i]*p2[k-1-ind])%MOD;
		ind++;
	}
	int good = -2;
	if(hash11 == hash12 && hash21 == hash22) good = l;
	while(r < n){
		if(good != -2) break;
		l++;
		hash11 = (1ll*hash11+1ll*(A[l]-A[r])*p1[l])%MOD;
		hash21 = (1ll*hash21+1ll*(A[l]-A[r])*p2[l])%MOD;
		hash12 = (1ll*hash12+1ll*(A[l]-A[r])*p1[k-1-l])%MOD;
		hash22 = (1ll*hash22+1ll*(A[l]-A[r])*p2[k-1-l])%MOD;
		if(hash11 < 0) hash11 += MOD;
		if(hash12 < 0) hash12 += MOD;
		if(hash21 < 0) hash21 += MOD;
		if(hash22 < 0) hash22 += MOD;
		r++;
		if(hash11 == hash12 && hash21 == hash22) good = l;
	}
	if(write && good != -2){
		FOR(i, l+1) std::cout << s[i];
		REP(i, r, n) std::cout << s[i];
		std::cout << "\n";
	}
	return good != -2;
}

int main(){
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	auto xd = std::uniform_int_distribution<int>(31, 1000005);
	P1 = xd(rng);
	P2 = xd(rng);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	p1.push_back(1);
	p2.push_back(1);
	REP(i, 1, 1000005){
		p1.push_back((1ll*p1.back()*P1)%MOD);
		p2.push_back((1ll*p2.back()*P2)%MOD);
	}
	int t;
	std::cin >> t;
	while(t--){
		std::cin >> s;
		n = SZ(s);
		A.resize(n);
		FOR(i, n) A[i] = s[i]-'a'+1;
		for(int i = n; i >= 1; --i){
			if(check(i, true)) break;
		}
	}

	return 0;
}