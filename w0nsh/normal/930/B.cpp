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


int ans, n;
std::string str;
int tab[30][5005][30];
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> str;
	n = SZ(str);
	FOR(i, n){
		REP(j, 1, n){
			tab[str[i]-'a'][j][str[(i+j)%n]-'a']++;
		}
	}
	FOR(i, 26){
		int best = 0;
		REP(j, 1, n){
			int cur = 0;
			FOR(k, 26){
				if(tab[i][j][k] == 1) cur++;
			}
			best = std::max(best, cur);
		}
		ans += best;
	}
	std::cout << std::fixed << std::setprecision(60) << ((long double)ans) / n;
	return 0;
}