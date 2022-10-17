#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;


int solve2(){
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	int ans = 0;


	FOR(start, n){
                if(start > 0 && A[start-1] == A[start]) continue;
		int pos = start;
		int cur = 1;
		while(true){
			int left = pos+1;
			int right = n;
			while(left < right){
				int mid = (left+right)/2;
				if(A[mid] - A[pos] >= A[pos] - A[start]){
					right = mid;
				}else{
					left = mid+1;
				}
			}
			if(left == n) break;
			cur++;
			pos = left;
		}

		ans = std::max(ans, cur);
	}


	return n-ans;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int t;
	std::cin >> t;
	while(t--){
		std::cout << solve2() << "\n";
	}

	return 0;
}