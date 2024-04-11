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

int next[26][100005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int test;
	std::cin >> test;
	while(test--){
		std::string s, t;
		std::cin >> s >> t;
		FOR(c, 26){
			next[c][SZ(s)] = -1;
			for(int i = SZ(s)-1; i >= 0; --i){
				if(s[i] == 'a'+c) next[c][i] = i+1;
				else next[c][i] = next[c][i+1];
			}
		}
		int ans = 1;
		int pos = 0;
		TRAV(c, t){
			if(next[c-'a'][pos] == -1){
				ans++;
				pos = next[c-'a'][0];
				if(pos == -1){
					ans = -1;
					break;
				}
			}else pos = next[c-'a'][pos];
		}
		std::cout << ans <<"\n";
	}
	return 0;
}