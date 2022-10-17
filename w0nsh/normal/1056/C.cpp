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

std::vector<PII> A, pairs;
VI val;
VI pr;
std::vector<bool> dead;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	dead.resize(2*n);
	FOR(i, 2*n){
		int a;
		std::cin >> a;
		val.push_back(a);
		A.push_back(MP(a, i));
	}
	pr.resize(2*n, -1);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		pairs.push_back(MP(a, b));
		pr[a] = b;
		pr[b] = a;
	}
	std::sort(A.begin(), A.end());
	int t;
	std::cin >> t;
	t = t%2;
	int must = -1;
	FOR(i, 2*n){
		if(i%2 != t){
			if(must != -1){
				std::cout << must+1 << "\n" << std::flush;
				dead[must] = true;
			}else{
				bool done = false;
				FOR(j, m){
					if(!dead[pairs[j].X] && !dead[pairs[j].Y]){
						int mx = pairs[j].X;
						if(val[pairs[j].X] < val[pairs[j].Y]) mx = pairs[j].Y;
						std::cout << mx+1 << "\n" << std::flush;
						dead[mx] = true;
						done = true;
						break;
					}
				}
				if(!done){
					for(int j = SZ(A)-1; j >= 0; --j){
						if(!dead[A[j].Y]){
							dead[A[j].Y] = true;
							std::cout << A[j].Y+1 << "\n" << std::flush;
							break;
						}
					}
				}
			}
		}else{
			int his;
			std::cin >> his;
			his--;
			dead[his] = true;
			if(pr[his] != -1 && !dead[pr[his]]){
				must = pr[his];
			}else must = -1;
		}
	}
	return 0;
}