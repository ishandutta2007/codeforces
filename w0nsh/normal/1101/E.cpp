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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	int s1 = 0;
	int s2 = 0;
	FOR(i, n){
		char what;
		int a, b;
		std::cin >> what >> a >> b;
		if(a > b) std::swap(a, b);
		if(what == '+'){
			if(b > s2) s2 = b;
			if(a > s1) s1 = a;
		}else{
			if(s1 <= a && s2 <= b) std::cout << "YES\n";
			else std::cout << "NO\n";
		}
	}
	return 0;
}