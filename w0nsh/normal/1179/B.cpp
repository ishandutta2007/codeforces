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
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	std::vector<PII> ans;
	bool swp = false;
	if(m > n) std::swap(n, m), swp = true;
	int lo = 1;
	int hi = m;
	FOR(_, m/2){
		REP(i, 1, n+1){
			ans.push_back(MP(i, lo));
			ans.push_back(MP(n+1-i, hi));
		}
		lo++;
		hi--;
	}
	if(lo == hi){
		REP(i, 0, n){
			if(i%2 == 0){
				ans.push_back(MP(1+i/2, lo));
			}else{
				ans.push_back(MP(n-i/2, lo));
			}
		}
	}
	TRAV(i, ans){
		if(!swp) std::cout << i.X << " " << i.Y << "\n";
		else std::cout << i.Y << " " << i.X << "\n";
	}
	return 0;
}