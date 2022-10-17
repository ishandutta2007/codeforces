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

int max(int n){
	int have = 0;
	FOR(i, n) if(i%7 == 0 || i % 7 == 1) have++;
	return have;
}
int min(int n){
	int have = 0;
	FOR(i, n) if(i%7 == 5 || i % 7 == 6) have++;
	return have;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::cout << min(n) << " " << max(n) << std::endl;
	return 0;
}