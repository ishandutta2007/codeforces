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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n, l, r;
		std::cin >> n >> l >> r;
		VI left(n);
		VI right(n);
		FOR(i, n){
			int a;
			std::cin >> a;
			a--;
			if(i < l){
				left[a]++;
			}else{
				right[a]++;
			}
			if(left[a] && right[a]){
				left[a]--;
				right[a]--;
			}
		}

		VI L, R;
		int sl = 0, sr = 0;
		FOR(i, n){
			if(left[i]) L.push_back(left[i]);
			if(right[i]) R.push_back(right[i]);
			sl += left[i];
			sr += right[i];
			assert(!left[i] || !right[i]);
		}

		std::sort(L.begin(), L.end());
		std::sort(R.begin(), R.end());

		if(sl > sr){
			std::swap(sl, sr);
			std::swap(L, R);
		}

		// sl <= sr
		int ans1 = (sl + sr) / 2;
		int nwsum = 0;
		int nwans = 0;
		FOR(i, SZ(R)) {
			if(R[i] > 1){
				nwans += R[i] / 2;
				R[i] = R[i] % 2;
			}
			nwsum += R[i];
		}

		if(sl >= nwsum){
			std::cout <<  ans1 << "\n";
			continue;
		}

		int more = nwsum - sl;
		nwans += sl;
		nwans += more;

		std::cout << nwans << "\n";

	}

	return 0;
}