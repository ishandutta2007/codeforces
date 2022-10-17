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

const ll INF = 1000000000000000ll;
int n, m, k, q;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k >> q;
	std::vector<VI> tr(n);
	int maxr = 0;
	FOR(i, k){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		tr[a].push_back(b);
		maxr = std::max(maxr, a);
	}
	VI safe(q);
	FOR(i, q) std::cin >> safe[i], safe[i]--;
	std::sort(safe.begin(), safe.end());
	std::vector<PR<int, ll> > pos;
	pos.push_back(MP(0, 0));
	if(SZ(tr[0]) == 0){
		pos.clear();
		pos.push_back(MP(safe[0], safe[0]));
	}
	ll lastmin = INF;
	TRAV(t, tr) if(SZ(t) > 0){
		int min = *std::min_element(t.begin(), t.end());
		int max = *std::max_element(t.begin(), t.end());
		ll lef = INF;
		ll rig = INF;
		TRAV(p, pos){
			ll cr = p.Y + max - min + std::abs(min - p.X);
			ll cl = p.Y + max - min + std::abs(max - p.X);
			lef = std::min(lef, cl);
			rig = std::min(rig, cr);
		}
		lastmin = std::min(lef, rig);
		pos.clear();
		auto it = std::lower_bound(safe.begin(), safe.end(), min);
		if(it != safe.end()) pos.push_back(MP(*it, lef+std::abs(min-*it)));
		if(it != safe.begin()){
			it--;
			pos.push_back(MP(*it, lef+std::abs(min-*it)));
		}
		it = std::lower_bound(safe.begin(), safe.end(), max);
		if(it != safe.end()) pos.push_back(MP(*it, rig+std::abs(max-*it)));
		if(it != safe.begin()){
			it--;
			pos.push_back(MP(*it, rig+std::abs(max-*it)));
		}
	}
	std::cout << lastmin+maxr;
	return 0;
}