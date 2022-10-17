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
		VI A;
		int last = -1;
		int cnt = 0;
		FOR(i, n){
			int a;
			std::cin >> a;
			if(a == last) cnt++;
			else{
				if(last != -1) A.push_back(cnt);	
				cnt = 1;
				last = a;
			}
		}
		A.push_back(cnt);
		int g = A[0];
		int pos = 1;
		int s = 0;
		int b = 0;
		while(pos < SZ(A)){
			if(s <= g) s += A[pos];
			else if((g+s+b+A[pos])*2 <= n) b += A[pos];
			else break;
			pos++;
		}
		if((g+s+b)*2 > n || g >= s || g >= b) std::cout << "0 0 0\n";
		else std::cout << g << " " << s << " " << b << "\n";
	}
	return 0;
}