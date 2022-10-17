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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n, d;
		std::cin >> n >> d;
		std::vector<int> ile;
		int left = n;
		ll dep = 0;
		FOR(i, n){
			ile.push_back(std::min(left, 1<<i));
			left -= ile.back();
			dep += i*ile.back();
			if(left == 0) break;
		}
		if(dep > d){
			std::cout << "NO\n";
			continue;
		}
		while(SZ(ile) < n+5) ile.push_back(0);
		std::set<int> can;
		FOR(i, n){
			int pos = i;
			if(2*ile[pos]-2 >= ile[pos+1]+1 && (pos > 18 || ile[pos+1] < (1<<(pos+1))))
				can.insert(pos);
		}
		while(dep < d && SZ(can)){
//			FOR(i, 5) std::cout << ile[i] << ", ";
//			std::cout <<  "  can ";
//			TRAV(i, can) std::cout << i << ", ";
//			std::cout << std::endl;
			auto pos = *can.begin();
			ile[pos]--;
			ile[pos+1]++;
//			std::cout << "tera ";
//			FOR(i, 5) std::cout << ile[i] << ", ";
//			std::cout << std::endl;
			dep++;
			can.erase(pos);
			if(2*ile[pos]-2 >= ile[pos+1]+1 && (pos > 18 || ile[pos+1] < (1<<(pos+1))))
				can.insert(pos);
			pos++;
			can.erase(pos);
			if(2*ile[pos]-2 >= ile[pos+1]+1 && (pos > 18 || ile[pos+1] < (1<<(pos+1))))
				can.insert(pos);
			pos -= 2;
			can.erase(pos);
			if(2*ile[pos]-2 >= ile[pos+1]+1 && (pos > 18 || ile[pos+1] < (1<<(pos+1))))
				can.insert(pos);
		}
		if(dep != d){
			std::cout << "NO\n";
			continue;
		}
		VI par;
		par.push_back(0);
		int cur = 1;
		int lev = 1;
		VI ans(n);
		while(ile[lev]){
			assert(2*ile[lev] >= ile[lev+1]);
			int left = ile[lev];
			while(left){
				if(left >= 2){
					ans[cur] = par.back();
					ans[cur+1] = par.back();
					par.pop_back();
					cur += 2;
					left -= 2;
				}else{
					ans[cur] = par.back();
					cur++;
					left--;
				}
			}
			par = VI();
			FOR(i, ile[lev]) par.push_back(cur-1-i);
			lev++;
		}
		std::cout << "YES\n";
		REP(i,1, n) std::cout << ans[i]+1 << " ";
		std::cout << "\n";
	}

	return 0;
}