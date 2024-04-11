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

int t;
int n, ans[100005];
std::vector<PR<PII, int> > events;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> t;
	while(t--){
		events.clear();
		std::cin >> n;
		FOR(i, n){
			int a, b;
			std::cin >> a >> b;
			events.push_back(MP(MP(a, 1), i));
			events.push_back(MP(MP(b+1, -1), i));
		}
		std::sort(events.begin(), events.end());
		auto it = events.begin();
		int open = 0;
		int curgp = 0;
		int cnt1 = 0, cnt2 = 0;
		bool fail = false;
		while(it != events.end()){
			if(it->X.Y == -1){
				open--;
				if(open == 0){
					curgp = (curgp+1)%2;
				}
			}else{
				open++;
				if(curgp == 0) cnt1++;
				else cnt2++;
				ans[it->Y] = curgp+1;
			}
			it++;
		}
		if(cnt1 == 0 || cnt2 == 0) std::cout << -1 << "\n";
		else{
			FOR(i, n) std::cout << ans[i] << " ";
			std::cout << "\n";
		}
	}
	return 0;
}