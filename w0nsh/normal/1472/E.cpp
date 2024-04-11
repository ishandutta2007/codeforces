#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
 
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::vector<PR<PII, int> > vec;
		std::vector<PR<PII, int> > good;
		std::vector<PII> A(n);
		FOR(i, n){
			std::cin >> A[i].X >> A[i].Y;
			vec.push_back(MP(MP(A[i].X, A[i].Y), i));
		}
		std::sort(vec.begin(), vec.end());
		FOR(i, SZ(vec)){
			if(SZ(good) == 0 || good.back().X.Y > vec[i].X.Y){
				good.push_back(vec[i]);
			}
		}

		auto check = [&](int a, int b) -> bool {
			auto it = std::lower_bound(good.begin(), good.end(), MP(MP(a, -1000), -100));
			if(it == good.begin()) return false;
			--it;
			if(it->X.Y < b){
				std::cout << it->Y + 1 << " ";
				return true;
			}
			return false;
		};

		auto hehe = [&]{
			std::cout << -1 << " ";
			return false;
		};

		FOR(i, n){
			check(A[i].X, A[i].Y) || check(A[i].Y, A[i].X) || hehe();
		}
		std::cout << "\n";
	}

	return 0;
}