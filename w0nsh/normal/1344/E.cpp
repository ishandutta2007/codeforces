#pragma GCC optimize "O3"
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

int n, m;
std::vector<std::vector<PII> > g;
std::vector<ll> dist;
std::vector<std::vector<ll> > dest;
std::vector<std::vector<PR<ll, ll> > > swt;

void dfs1(int v){
	TRAV(ch, g[v]){
		dist[ch.X] = dist[v]+ch.Y;
		dfs1(ch.X);
	}
}

PR<std::set<ll>, ll> dfs2(int v){
	std::vector<std::set<ll> > sets;
	std::vector<ll> wei;
	int last = -1;
	PII big = MP(-1, -1);
	TRAV(ch, g[v]){
		auto pr = dfs2(ch.X);
		if(SZ(pr.X) > 0){
			sets.push_back(std::move(pr.X));
			wei.push_back(-ch.Y+pr.Y);
			big = std::max(big, MP(SZ(sets.back()), SZ(sets)-1));
			last = SZ(sets)-1;
		}else last = -1;
	}
	ll off = 0;
	if(big.Y != -1){
		std::swap(sets[0], sets[big.Y]);
		std::swap(wei[0], wei[big.Y]);
		if(last == big.Y) last = 0;

		off = wei[0];
		std::set<ll> other;
		REP(i, 1, SZ(sets)) TRAV(j, sets[i]) other.insert(j+wei[i]-off),
											 sets[0].insert(j+wei[i]-off);
		
		REP(i, 1, SZ(sets)) TRAV(j, sets[i]){
			ll val = j+wei[i]-off;
			
			auto it = sets[0].lower_bound(val);
			if(it != sets[0].begin() && sets[i].count(*std::prev(it)-wei[i]+off) == 0)
				swt[v].push_back(MP(*std::prev(it)+off+1, *it+off));
			if(std::next(it) != sets[0].end() && other.count(*std::next(it)) == 0)
				swt[v].push_back(MP(*it+off+1, *std::next(it)+off));
		}

		ll sma = *sets[0].begin();
		if(last == -1) swt[v].push_back(MP(1ll, sma+off));
		else if(last == 0){
			if(other.count(sma) != 0)
				swt[v].push_back(MP(1ll, sma+off));
		}else{
			if(sets[last].count(sma-wei[last]+off) == 0)
				swt[v].push_back(MP(1ll, sma+off));
		}

		std::sort(swt[v].begin(), swt[v].end());
	}else{
		assert(SZ(sets) == 0);
		sets.emplace_back();
	}
	TRAV(i, dest[v]) sets[0].insert(i-off);
	return MP(std::move(sets[0]), off);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	if(n == 1){
		std::cout << "-1 0\n";
		return 0;
	}
	g.resize(n);
	dist.resize(n);
	dest.resize(n);
	swt.resize(n);
	FOR(i, n-1){
		int a, b, c;
		std::cin >> a >> b >> c;
		a--;b--;
		g[a].push_back(MP(b, c));
	}
	dfs1(0);

	FOR(i, m){
		int s, t;
		std::cin >> s >> t;
		s--;
		dest[s].push_back(t+dist[s]);
	}

	dfs2(0);

	std::vector<PR<ll, ll> > prze;
	FOR(i, n){
		TRAV(j, swt[i]) prze.push_back(j);
	}
	std::sort(prze.begin(), prze.end());

	std::priority_queue<ll, std::vector<ll>, std::greater<ll>> up;

	ll ans = -1;

	auto it = prze.begin();
	ll time = it->X;
	while(it != prze.end() && it->X <= time){
		assert(it->X == time);
		up.push(it->Y);

		it++;
	}

	while(SZ(up)){
		ll cur = up.top();
		up.pop();
		if(cur < time){
			assert(cur == time-1);
			ans = cur;
			break;
		}

		time++;
		while(it != prze.end() && it->X <= time){
			assert(it->X == time);
			up.push(it->Y);

			it++;
		}

		if(SZ(up) == 0 && it != prze.end()){
			time = it->X;
			while(it != prze.end() && it->X <= time){
				assert(it->X == time);
				up.push(it->Y);

				it++;
			}
		}
	}

	if(ans == -1){
		std::cout << ans << " " << SZ(prze) << "\n";
	}else{
		std::cout << ans << " ";
		int cnt = 0;
		TRAV(i, prze) if(i.Y < ans) cnt++;
		std::cout << cnt << "\n";
	}

	return 0;
}