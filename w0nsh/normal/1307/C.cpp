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

int pref[26][100005];
ll ans[26][26];
int ile[26];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string s;
	std::cin >> s;
	s = "#" + s;
	REP(i, 1, SZ(s)) ile[s[i]-'a']++;
	FOR(c, 26){
		REP(i, 1, SZ(s)){
			pref[c][i] = pref[c][i-1] + (s[i]-'a' == c ? 1 : 0);
		}
	}
	REP(i, 1, SZ(s)){
		int  my = s[i]-'a';
		FOR(c, 26){
			ans[my][c] += ile[c]-pref[c][i];
		}
	}
	ll mx = 0;
	FOR(c, 26) FOR(j, 26) mx = std::max(mx, ans[c][j]);
	FOR(i, 26) mx = std::max(mx, 1ll*ile[i]);
	std::cout << mx << "\n";
	return 0;
}