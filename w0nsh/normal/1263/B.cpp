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
		std::vector<std::string> A;
		int ans = 0;
		std::set<std::string> have;
		std::vector<std::string> XD(n);
		std::set<std::string> bad;
		FOR(i, n){
			std::cin >> XD[i];
			bad.insert(XD[i]);
		}
		FOR(l, n){
			std::string a = XD[l];
			if(have.count(a)){
				ans++;
				bool good = false;
				FOR(i, 4){
					FOR(j, 10){
						std::string b = a;
						int xd = a[i]-'0';
						xd = (xd+j)%10;
						b[i] = '0'+xd;
						if(have.count(b) == 0 && bad.count(b) == 0){
							a = b;
							good = true;
							break;
						}
					}
					if(good) break;
				}
			}
			have.insert(a);
			A.push_back(a);
		}
		std::cout << ans << "\n";
		FOR(i, n){
			std::cout << A[i] << "\n";
		}

	}
	return 0;
}