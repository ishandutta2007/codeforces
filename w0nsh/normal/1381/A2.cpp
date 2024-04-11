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
		VI A, B;
		FOR(i, n){
			char a;
			std::cin >> a;
			A.push_back(a-'0');
		}
		FOR(i, n){
			char a;
			std::cin >> a;
			B.push_back(a-'0');
		}

		VI ans;
		int l = 0, r = n-1;
		int cur = 0;
		while(SZ(B)){
			
			if(cur == 0){
				// r
				if((A[l]^cur) == B.back()){
					ans.push_back(1);
					A[l] = 1-A[l];
				}
				ans.push_back(SZ(B));
				l++;

			}else{
			
				if((A[r]^cur) == B.back()){
					ans.push_back(1);
					A[r] = 1-A[r];
				}
				ans.push_back(SZ(B));
				r--;
			}
			
			B.pop_back();
			cur = (cur+1)%2;
		}

		std::cout << SZ(ans) << " ";
		TRAV(i, ans) std::cout << i << " ";
		std::cout << "\n";
	}

	return 0;
}