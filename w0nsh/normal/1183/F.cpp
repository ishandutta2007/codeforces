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

std::unordered_set<int> divs[200005];

int best;
VI A;

// void rec(int pos, VI vec, int left){
// 	int sum = 0;
// 	TRAV(i, vec) sum += i;
// 	best = std::max(sum, best);
// 	if(pos < 0) return;
// 	if(SZ(vec) == 3) return;
// 	if(left == 0) return;
// 	rec(pos-1, vec, left-1);
// 	bool good = true;
// 	TRAV(i, vec) if(i%A[pos] == 0) good = false;
// 	vec.push_back(A[pos]);
// 	if(good) rec(pos-1, vec, left-1);
// }

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	for(int i = 2; i <= 200005; ++i){
		for(int j = i; j < 200005; j += i){
			divs[j].insert(i);
		}
	}
	int q;
	std::cin >> q;
	while(q--){
		int n;
		std::cin >> n;
		std::set<int> set;
		int a;
		FOR(i, n) std::cin >> a, set.insert(a);
		A.clear();
		TRAV(i, set) A.push_back(i);
		n = SZ(A);
		best = A.back();
		for(int start = n-1; start >= n-4 && start >= 0; --start){
			std::unordered_set<int> &cant = divs[A[start]];
			FOR(next, start){
				if(cant.count(A[next])) continue;
				best = std::max(best, A[start]+A[next]);
				std::unordered_set<int> &cant2 = divs[A[next]];
				int pos = next-1;
				while(pos >= 0){
					if(cant.count(A[pos]) == 0 && cant2.count(A[pos]) == 0){
						best = std::max(best, A[pos]+A[next]+A[start]);
						break;
					}
					pos--;
				}
			}
		}
		std::cout << best << "\n";
	}
	return 0;
}