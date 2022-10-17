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

int n;
char temp;
bool t[5205][5205];

bool check(int xd){
	FOR(i, n){
		int dv = (i/xd)*xd;
		int add = 0;
		int ps = 0;
		FOR(j, n){
			if(t[dv][add] != t[i][j]) return false;
			ps++;
			if(ps == xd) ps = 0, add += xd;
		}
	}
	return true;	
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n){
		std::string str;
		std::cin >> str;
		FOR(j, SZ(str)){
			int cr = 0;
			if(str[j] >= 'A') cr = str[j]-'A'+10; 
			else cr = str[j]-'0';
			t[i][j<<2] = cr&8;
			t[i][(j<<2)+1] = cr&4;
			t[i][(j<<2)+2] = cr&2;
			t[i][(j<<2)+3] = cr&1;
		}
	}
	// FOR(i, n){
		// FOR(j, n) std::cout << t[i][j] << " ";
		// std::cout << "\n";
	// }
	std::set<int> cant;
	int best = 1;
	REP(i, 1, n+1){
		if(n % i != 0) continue;
		TRAV(j, cant) if(i % j == 0) continue;
		if(check(i)) best = i;
		else cant.insert(i); 
	}
	std::cout << best;
	return 0;
}