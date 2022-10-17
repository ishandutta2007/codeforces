#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
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
		std::string s;
		int n;
		std::cin >> n;
		std::cin >> s;
		std::vector<PII> A;
		FOR(i, n) A.push_back(MP(s[i]-'0', i));
		std::sort(A.begin(), A.end());
		int last = -1;
		VI col(n);
		VI vec;
		int skip = 100;
		FOR(i, n){
			if(A[i].X > skip) continue;
			if(A[i].Y > last){
				last++;
				while(last < A[i].Y){
					skip = std::min(skip, s[last]-'0');
					last++;
				}
				if(A[i].X > skip) continue;
				col[A[i].Y] = 1, last = A[i].Y, vec.push_back(A[i].X);
			}
		}
		//FOR(i, n) std::cout << col[i] << " ";
	//	std::cout << "\n";
		FOR(i, n) if(col[i] == 0) col[i] = 2, vec.push_back(s[i]-'0');
		bool good = true;
		FOR(i, n-1) if(vec[i] > vec[i+1]) good = false;
		if(good){
			FOR(i, n) std::cout << col[i];
			std::cout << "\n";
		}else{
			std::cout << "-\n";
		}


	}

	return 0;
}