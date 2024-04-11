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
	std::cin >>t;
	while(t--){
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		int base = 0;
		auto siema = [&](int a) -> bool{
			return a > 0 && a < n-1 && ((A[a] > A[a-1] && A[a] > A[a+1]) || (A[a] < A[a-1] && A[a] < A[a+1]));
		};

		FOR(i, n) base += siema(i);
		int ans = base;
		FOR(i, n){
			VI vals;
			if(i > 0){
				vals.push_back(A[i-1]-1);
				vals.push_back(A[i-1]);
				vals.push_back(A[i-1]+1);
			}
			if(i < n-1){
				vals.push_back(A[i+1]-1);
				vals.push_back(A[i+1]);
				vals.push_back(A[i+1]+1);
			}

			TRAV(x, vals){
				int cur = base;
				cur -= siema(i-1);
				cur -= siema(i);
				cur -= siema(i+1);
				int old = A[i];
				A[i] = x;
				cur += siema(i-1);
				cur += siema(i);
				cur += siema(i+1);
				ans = std::min(ans, cur);
				A[i] = old;

			}
		}
		std::cout << ans << "\n";
	}

	return 0;
}