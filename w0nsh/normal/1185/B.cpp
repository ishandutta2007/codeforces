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
	std::cin >> n;
	FOR(_, n){
		std::string a, b;
		std::cin >> a >> b;
		int pos = 0;
		int have = 0;
		char last = a[0];
		bool bad = false;
		TRAV(i, a){
			if(i == last) have++;
			else{
				int cnt = 0;
				while(pos < SZ(b) && b[pos] == last) cnt++, pos++;
				if(cnt < have){
					bad = true;
					break;
				}
				have = 1;
				last = i;
			}
		}
		int cnt = 0;
		while(pos < SZ(b) && b[pos] == last) cnt++, pos++;
		if(cnt < have) bad = true;
		if(pos != SZ(b)){
			bad = true;
		}
		if(bad) std::cout << "NO\n";
		else std::cout << "YES\n";
	}
	return 0;
}