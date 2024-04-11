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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::string str;
		std::cin >> str;
		std::vector<PII> A;
		int cnt = 0;
		FOR(i, n-1){
			if(i != 0 && str[i] != str[i-1]){
				A.push_back(MP(cnt, str[i-1] == '<' ? 1 : -1));
				cnt = 1;
			}else cnt++;
		}
		A.push_back(MP(cnt, str.back() == '<' ? 1 : -1));
		{
			VI my;
			int mam = n;
			if(A[0].Y == -1) my.push_back(mam), mam--;
			TRAV(i, A){
				if(i.Y == -1){
					FOR(j, i.X-1) my.push_back(mam), mam--;
				}else{
					int od = mam-i.X;
					FOR(j, i.X+1) my.push_back(od), od++;
					assert(od == mam+1);
					mam = mam-i.X-1;
				}
			}
			if(A.back().Y == -1) my.push_back(mam);
			TRAV(i, my) std::cout << i << " ";
			std::cout << "\n";
		}
		{
			VI my;
			int mam = 1;
			if(A[0].Y == 1) my.push_back(mam), mam++;
			TRAV(i, A){
				if(i.Y == 1){
					FOR(j, i.X-1) my.push_back(mam), mam++;
				}else{
					int od = mam+i.X;
					FOR(j, i.X+1) my.push_back(od), od--;
					assert(od == mam-1);
					mam = mam+i.X+1;
				}
			}
			if(A.back().Y == 1) my.push_back(mam);
			TRAV(i, my) std::cout << i << " ";
			std::cout << "\n";
		}
	}
	return 0;
}