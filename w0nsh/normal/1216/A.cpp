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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string s;
	int n;
	std::cin >> n >> s;
	int ans = 0;
	FOR(i, n/2){
		if(s[2*i] == s[2*i+1]){
			ans++;
			if(s[2*i] == 'a') s[2*i] = 'b';
			else s[2*i] = 'a';
		}
	}
	std::cout <<ans << "\n" << s;
	return 0;
}