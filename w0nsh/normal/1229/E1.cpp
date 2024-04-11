#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
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

int pr[6][6];
int sub[2][1<<18];
int mas[1<<18];
int p[2][1<<20];
VI m3;
int comp[20];

int cm(int a){
	int ret = 0;
	FOR(i, 20) if(a & (1<<i)) ret += (1<<comp[i]);
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::map<int, int> map;
	FOR(i, 1<<6) if(__builtin_popcount(i) == 3) m3.push_back(i), map[i] = SZ(m3)-1;
	FOR(i, 1<<6) if(__builtin_popcount(i) == 3) comp[map[i]] = map[i^63];
	assert(SZ(map) == 20);
	int n;
	std::cin >> n;
	FOR(i, n) FOR(j, n) std::cin >> pr[i][j], pr[i][j] = (1ll*pr[i][j]*modpow(100, MOD-2))%MOD;
	REP(i, n, 6) pr[i][i] = 1;
	n = 6;
	FOR(mask, 1<<18){
		sub[0][mask] = 1;
		sub[1][mask] = 1;
		FOR(i, 6) FOR(j, 3){
			if(mask & (1<<((i*3)+j))){
				sub[0][mask] = (1ll*sub[0][mask]*pr[i][j])%MOD;
				sub[1][mask] = (1ll*sub[1][mask]*pr[i][3+j])%MOD;
			}else{
				int od = 1-pr[i][j];
				if(od < 0) od += MOD;
				sub[0][mask] = (1ll*sub[0][mask]*od)%MOD;
				od = 1-pr[i][3+j];
				if(od < 0) od += MOD;
				sub[1][mask] = (1ll*sub[1][mask]*od)%MOD;
			}
		}
		int ind = 0;
		TRAV(m, m3){
			VI guys;
			FOR(i, 6) if(m & (1<<i)) guys.push_back(i);
			bool bad = false;
			FOR(xd, 1<<3){
				int ms = 0;
				FOR(i, 3) if(xd & (1<<i)) ms |= (mask >> (guys[i]*3)) & 7;
				if(__builtin_popcount(xd) > __builtin_popcount(ms)){
					bad = true;
					break;
				}
			}
			if(!bad) mas[mask] += (1<<ind);
			ind++;
		}
	}
	FOR(i, 1<<18) p[0][mas[i]] = (p[0][mas[i]]+sub[0][i])%MOD;
	FOR(i, 1<<18) p[1][cm(mas[i])] = (p[1][cm(mas[i])]+sub[1][i])%MOD;
	FOR(i, 20) FOR(mask, 1<<20) if(mask & (1<<i)) p[1][mask] = (p[1][mask]+p[1][mask^(1<<i)])%MOD;
	int ans = 0;
	FOR(i, 1<<20) ans = (1ll*ans+1ll*p[0][i]*p[1][i^((1<<20)-1)])%MOD;
	ans = 1-ans;
	if(ans < 0) ans += MOD;
	std::cout << ans << "\n";
	return 0;
}