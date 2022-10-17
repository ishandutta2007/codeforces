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
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		VI have;
		std::vector<VI> mam;
		FOR(i, n){
			if(SZ(have) && have.back() == A[i]){
				mam.push_back(have);
				have = VI();
			}
			have.push_back(A[i]);
		}
		mam.push_back(have);

		std::map<int, int> cnt;
		int nn = SZ(mam)*2;
		int no = SZ(mam);
		FOR(i, SZ(mam)){
			cnt[mam[i][0]]++;
			cnt[mam[i].back()]++;
		}
		int most = -1;
		int need = 0;
		TRAV(pr, cnt){
			if(pr.Y > no+1){
				assert(most == -1);
				most = pr.X;
				need = pr.Y-(no+1);
			}
		}

		if(most == -1){
			std::cout << SZ(mam)-1 << "\n";
			continue;
		}

		int moge = 0;
		TRAV(vec, mam){
			FOR(i, SZ(vec)-1){
				if(vec[i] != most && vec[i+1] != most) moge++;
			}
		}
		if(moge < need){
			std::cout << -1 << "\n";
		}else{
			std::cout << SZ(mam)-1 + need << "\n";
		}

	}

	return 0;
}