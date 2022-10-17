#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

std::string s, t;
int zer, one;
std::vector<PII> gp;
ll MOD = 1000000007;
ll _pw = 31;
ll pw[1000005];
ll hash[1000005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> s >> t;
	TRAV(ch, s){
		if(ch == '0') zer++;
		else one++;
	}
	int minsame = 0;
	FOR(i, SZ(t)){
		int x = i;
		if(1ll*i * zer > SZ(t)) continue;
		int y = SZ(t) - zer*x;
		if(y < 1 || y % one != 0) continue;
		y /= one;
		if(y == x) minsame++;
		if(y*one > 0 && y*one < SZ(t) && x*zer > 0 && x*zer < SZ(t)) gp.push_back(MP(x, y));
	}
	char same = t[0];
	TRAV(ch, t)	if(ch != same) same = '$';
	if(same != '$'){
		std::cout << SZ(gp)-minsame << "\n";
		return 0;
	}
	pw[0] = 1;
	REP(i, 1, 1000005) pw[i] = (pw[i-1]*_pw)%MOD;
	hash[0] = t[0]-'a';
	REP(i, 1, SZ(t)) hash[i] = (hash[i-1]+(pw[i]*(t[i]-'a'))%MOD)%MOD;
	int ans = 0;
	TRAV(pr, gp){
		ll hash_zer = -1;
		ll pw_zer = 0;
		ll hash_one = -1;
		ll pw_one = 0;
		int pos = 0;
		bool good = true;
		TRAV(ch, s){
			if(ch == '0'){
				int end = pos + pr.X - 1;
				ll hs = hash[end]-(pos > 0 ? hash[pos-1] : 0);
				if(hs < 0) hs += MOD;
				if(hash_zer == -1){
					hash_zer = hs;
					pw_zer = end;
				}else{
					if(hs != (hash_zer*pw[end-pw_zer])%MOD){
						good = false;
						break;
					}
				}
				pos += pr.X;
			}else{
				int end = pos + pr.Y - 1;
				ll hs = hash[end]-(pos > 0 ? hash[pos-1] : 0);
				if(hs < 0) hs += MOD;
				if(hash_one == -1){
					hash_one = hs;
					pw_one = end;
				}else{
					if(hs != (hash_one*pw[end-pw_one])%MOD){
						good = false;
						break;
					}
				}
				pos += pr.Y;
			}
		}
		ll dif;
		if(pw_one > pw_zer) dif = (hash_one - (hash_zer*pw[pw_one-pw_zer])%MOD);
		else dif = (hash_zer - (hash_one*pw[pw_zer-pw_one])%MOD);
		if(good && dif != 0) ans++;
	}
	std::cout << ans << "\n";
	return 0;
}