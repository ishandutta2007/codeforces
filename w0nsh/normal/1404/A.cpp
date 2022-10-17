#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
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
		int n, k;
		std::cin >> n >> k;
		std::string s;
		std::cin >> s;
		bool good = true;
		VI xd(k);
		FOR(i, k){
			int pos = i;
			int co = -1;
			while(pos < n){
				int now = s[pos]-'0';
				if(s[pos] != '?'){
					if(co == -1) co = now;
					else{
						if(co != now){
							good = false;
							break;
						}
					}
				}
				pos += k;
			}
			if(co == -1) xd[i] = 2;
			else xd[i] = co;
			if(!good) break;
		}
		if(good){
			int cnt[3];
			cnt[0] = cnt[1] = cnt[2] = 0;
			FOR(i, k){
				cnt[xd[i]]++;
			}
			int roz = std::abs(cnt[0]-cnt[1]);
			if(cnt[2] < roz) good = false;
		}
		if(!good) std::cout << "NO\n";
		else std::cout << "YES\n";
	}

	return 0;
}