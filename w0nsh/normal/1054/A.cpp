#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int x, y, z, t1, t2, t3;
	std::cin >> x >> y >> z >> t1 >> t2 >> t3;
	int stairs = std::abs(x-y)*t1;
	int elevator = std::abs(x-z)*t2+std::abs(x-y)*t2+3*t3;
	if(elevator <= stairs) std::cout << "YES\n";
	else std::cout << "NO\n";
	return 0;
}