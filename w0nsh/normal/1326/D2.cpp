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
void check(int l, int r){
	PII best = MP(-1, -5);
	PII h1 = MP(0, 0);
	PII h2 = MP(0, 0);
	int ind = 0;
	REP(i, l, r+1){
		h1.X = (1ll*h1.X + 1ll*A[i]*p1[ind])%MOD;
		h1.Y = (1ll*h1.Y*P1 + 1ll*A[i])%MOD;
		h2.X = (1ll*h2.X + 1ll*A[i]*p2[ind])%MOD;
		h2.Y = (1ll*h2.Y*P2 + 1ll*A[i])%MOD;
		if(h1.X == h1.Y && h2.X == h2.Y){
			if(best.Y-best.X+1 < i-l+1){
				best.X = l;
				best.Y = i;
			}
		}
		ind++;
	}
	h1 = h2 = MP(0, 0);
	ind = 0;
	for(int i = r; i >= l; --i){
		h1.X = (1ll*h1.X + 1ll*A[i]*p1[ind])%MOD;
		h1.Y = (1ll*h1.Y*P1 + 1ll*A[i])%MOD;
		h2.X = (1ll*h2.X + 1ll*A[i]*p2[ind])%MOD;
		h2.Y = (1ll*h2.Y*P2 + 1ll*A[i])%MOD;
		if(h1.X == h1.Y && h2.X == h2.Y){
			if(best.Y-best.X+1 < r-i+1){
				best.X = i;
				best.Y = r;
			}
		}
		ind++;
	}
	assert(best.X != -1);
	REP(i, best.X, best.Y+1) std::cout << s[i];
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
		int l = 0;
		int r = n-1;
		while(l < r && A[l] == A[r]){
			l++;
			r--;
		}
		FOR(i, l) std::cout << s[i];
		if(l <= r) check(l, r);
		REP(i, r+1, n) std::cout << s[i];
		std::cout << "\n";
	}

	return 0;
}