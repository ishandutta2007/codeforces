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
	std::string str;
	std::cin >> str;
	std::vector<PII> no;
	int n = SZ(str);
	FOR(i, n){
		int d[2];
		d[0] = d[1] = 0;
		int upto = -1;
		REP(j, i, n){
			if(str[j] == '0'){
				d[0]++;
				if(d[0] >= d[1]) upto = j-1;
			}else{
				if(d[0] >= d[1]){
					upto = j-1;
					d[1] = d[0]+1;
				}else d[1] = d[1]+1;
			}
		}
		if(upto >= i) no.push_back(MP(i, upto));
	}
	std::string ret;
	FOR(i, n){
		if(str[i] == '0') ret.push_back('0');
		else{
			bool bad = false;
			TRAV(x, no) if(x.X <= i && x.Y >= i) bad = true;
			if(bad) ret.push_back('1');
			else ret.push_back('0');
		}
	}
	std::cout << ret;
	return 0;
}