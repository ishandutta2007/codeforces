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

int n, m;
int much[100005];
int need[100005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	FOR(i, 100005) need[i] = n;
	int round = 1;
	FOR(i, m){
		int a;
		std::cin >> a;
		much[a]++;
		need[much[a]]--;
		if(need[round] == 0) (std::cout << 1), round++;
		else std::cout << 0;
	}
	return 0;
}