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

int n, d, rank[200005], temp;
std::multiset<int> points;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> d;
	d--;
	FOR(i, n) std::cin >> rank[i];
	int have;
	std::cin >> have;
	have += rank[d];
	FOR(i, n-1) (std::cin >> temp), points.insert(temp);
	int cnt = 0;
	FOR(i, n) if(i != d){
		auto it = points.upper_bound(have - rank[i]);
		if(it == points.begin()) it = std::next(points.end(), -1);
		else{
			--it;
			cnt++;
		}
		points.erase(it);
	}
	std::cout << n-cnt << "\n";
	return 0;
}