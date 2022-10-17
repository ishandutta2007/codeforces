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
		int n, s;
		std::cin >> n >> s;
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		PII max = MP(-1, -1);
		int have = 0;
		int pos = 0;
		FOR(i, n){
			have += A[i];
			max = std::max(max, MP(A[i], i));
			if(have > s){
				break;
			}
			pos++;
		}
		int ile = pos;
		if(have <= s) std::cout << 0 << "\n";
		else{
			A.erase(A.begin()+max.Y);
			have = 0;
			int cnt = 0;
			FOR(i, n){
				have += A[i];
				if(have > s){
					break;
				}
				cnt++;
			}
			if(cnt > ile) std::cout << max.Y+1 << "\n";
			else std::cout << 0 << "\n";
		}
	}
	return 0;
}