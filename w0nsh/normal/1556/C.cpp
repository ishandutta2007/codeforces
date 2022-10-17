#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n){
		std::cin >> A[i];
	}

	std::map<ll, int> map;

	map[0] = 1;
	map[1] = -1;

	ll have = 0;
	ll ans = 0;
	FOR(i, n){
		if(i%2 == 0){
			map[have+1]++;
			map[have+A[i]+1]--;

			have += A[i];
		}else{

			// add (have-A[i], have-1)
			ll from = have-A[i];

			auto it = map.begin();
			ll ile = 0;
			while(it != map.end() && it->X <= from){
				ile += it->Y;
				it++;
			}

			while(it != map.end() && it->X < have){
				ll now = it->X;
				ans += 1ll * (now - from) * ile;
				// std::cout << "dodaje " << 1ll * (now - from) * ile <<  " z " << from << " " << now-1 << std::endl;
				ile += it->Y;
				from = now;
				it++;
			}

			// std::cout << "dodaje " << 1ll * (have - from) * ile <<  " z " << from << " " << have-1 << std::endl;
			ans += 1ll * (have - from) * ile;

			// std::cout << "tera ans " << ans << std::endl;

			// map[have]--;
			// map[have-A[i]]++;

			have -= A[i];

			if(!map.empty()){
				auto jt = std::prev(map.end());
				while(jt != map.end()){
					if(jt->X > have){
						auto next = (jt == map.begin() ? map.end() : std::prev(jt));
						// std::cout << "wywalam " << jt->X << " " << jt->Y << std::endl;
						map.erase(jt);
						jt = next;
					}else{
						break;
					}
				}
				ll sum = 0;
				TRAV(pr, map) sum += pr.Y;
				map[have+1] -= sum;
			}

			map[have]++;
			map[have+1]--;
		}

	}

	std::cout << ans << "\n";

	return 0;
}