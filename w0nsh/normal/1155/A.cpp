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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::string str;
	std::cin >> n >> str;
	int mx = 0;
	REP(i, 1, n){
		if(str[i] < str[mx]){
			std::cout << "YES\n" << mx+1 << " " << i+1 << "\n";
			return 0;
		}else if(str[i] > str[mx]) mx = i;
	}
	std::cout << "NO\n";
	return 0;
}