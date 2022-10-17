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

ll ans[25];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	int xd = 0;
	std::vector<int> vec[2];
	FOR(b, 25){
		vec[0] = vec[1] = VI();
		TRAV(a, A){
			int prev = a&((1<<b)-1);
			if(a&(1<<b)) vec[1].push_back(prev);
			else vec[0].push_back(prev);
		}
		std::sort(vec[0].begin(), vec[0].end());
		std::sort(vec[1].begin(), vec[1].end());
		TRAV(a, A){
			int prev = a&((1<<b)-1);
			if((a& (1<<b))){
				ans[b] += std::lower_bound(vec[0].begin(),vec[0].end(),(1<<b)-prev)-vec[0].begin();
		//		ans[b] ^= (int)set[0].order_of_key((1<<b)-prev);
		//		ans[b] ^= (int)SZ(set[1])-set[1].order_of_key((1<<b)-prev);
				int aaa = std::lower_bound(vec[1].begin(), vec[1].end(), (1<<b)-prev)-vec[1].begin();
				ans[b] += SZ(vec[1])-aaa;
				if(prev+prev >= (1<<b)) ans[b]--;
			}else{
				ans[b] += std::lower_bound(vec[1].begin(),vec[1].end(),(1<<b)-prev)-vec[1].begin();
		//		ans[b] ^= (int)set[0].order_of_key((1<<b)-prev);
		//		ans[b] ^= (int)SZ(set[1])-set[1].order_of_key((1<<b)-prev);
				int aaa = std::lower_bound(vec[0].begin(), vec[0].end(), (1<<b)-prev)-vec[0].begin();
				ans[b] += SZ(vec[0])-aaa;
				if(prev+prev >= (1<<b)) ans[b]--;
			}
		}
		if((ans[b]/2) & 1ll) xd = xd|(1<<b);
	}
	std::cout << xd;
	return 0;
}