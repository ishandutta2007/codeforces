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

int n, m;
std::map<int, VI> spec;
VI sum;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	sum.resize(m);
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		a--;
		spec[a].push_back(b);
	}
	TRAV(pr, spec) std::sort(pr.Y.begin(), pr.Y.end());
	int max = 0;
	int cur = 0;
	while(!spec.empty()){
		std::vector<int> to_erase;
		TRAV(pr, spec){
			if(pr.Y.empty() || sum[pr.X] + pr.Y.back() <= 0){
				cur -= sum[pr.X];
				to_erase.push_back(pr.X);
			}else{
				cur += pr.Y.back();
				sum[pr.X] += pr.Y.back();
				pr.Y.pop_back();
			}
		}
		TRAV(i, to_erase) spec.erase(i);
		max = std::max(max, cur);
	}
	std::cout << max << "\n";
	return 0;
}