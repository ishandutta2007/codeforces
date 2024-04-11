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

std::string read(){
	std::string a, b;
	std::cin >> a >> b;
	std::string ret = "";
	if(a[0] != 'X') ret.push_back(a[0]);
	if(a[1] != 'X') ret.push_back(a[1]);
	if(b[1] != 'X') ret.push_back(b[1]);
	if(b[0] != 'X') ret.push_back(b[0]);
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string a = read();
	std::string b = read();
	FOR(i, 3){
		if(a == b){
			std::cout << "YES\n";
			return 0;
		}
		std::swap(a[0], a[1]);
		std::swap(a[1], a[2]);
	}
	std::cout << "NO\n";
	return 0;
}