#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
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
		VI A(n);
		FOR(i, n){
			std::cin >> A[i];
		}

		VI ans;

		auto mex = [&](){
			VI hehe(n+1);
			FOR(i, n){
				if(A[i] < n) hehe[A[i]] = 1;
			}
			FOR(i, n+1) if(hehe[i] == 0) return i;
		};

		std::set<int> todo;
		FOR(i, n) if(A[i] != i) todo.insert(i);
		while(SZ(todo)){
			int m = mex();
			if(m == n){
				int v = *todo.begin();
				ans.push_back(v);
				A[v] = m;
				m = mex();
			}

			assert(m < n && todo.count(m));
			A[m] = m;
			ans.push_back(m);
			todo.erase(m);
		}

		FOR(i, n-1) assert(A[i] <= A[i+1]);

		std::cout << SZ(ans) << "\n";
		TRAV(i, ans) std::cout << i+1 << " ";
		std::cout << "\n";

	}

	return 0;
}