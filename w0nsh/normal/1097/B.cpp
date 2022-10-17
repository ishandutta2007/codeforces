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
VI A;
bool here[20][370];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	here[0][0] = true;
	REP(i, 1, n+1){
		FOR(a, 360){
			if(here[i-1][a]){
				here[i][(a+A[i-1])%360] = true;
				int back = a-A[i-1];
				if(back < 0) back += 360;
				here[i][back] = true;
			}
		}
	}
	if(here[n][0]) std::cout << "YES\n";
	else std::cout << "NO\n";
	return 0;
}