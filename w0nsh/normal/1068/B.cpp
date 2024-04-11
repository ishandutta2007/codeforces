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

ll const xd = 1000000000ll*1000000000ll;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	ll b;
	std::cin >> b;
	int count = 0;
	REP(i, 1, 100006){
		if(1ll*i*i == b) count++;
		if(1ll*i*i >= b) break;
		if(b % i == 0){
			count += 2;
		}
	}
	std::cout << count << "\n";
	return 0;
}