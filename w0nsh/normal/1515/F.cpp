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

struct UF{
	VI repr;
	UF(int n){
		repr = VI(n);
		FOR(i, n) repr[i] = i;
	}

	int Find(int a){
		if(a == repr[a]) return a;
		return repr[a] = Find(repr[a]);
	}

	int Union(int a, int b){
		a = Find(a);
		b = Find(b);
		if(a == b) return 0;
		repr[a] = b;
		return 1;
	}
};

struct UFV{
	VI repr;
	std::vector<ll> value;
	std::vector<std::priority_queue<PII, std::vector<PII>, std::greater<PII>>> wait;

	UFV(int n){
		repr = VI(n);
		value = std::vector<ll>(n);
		wait = std::vector<std::priority_queue<PII, std::vector<PII>, std::greater<PII>>>(n);
		FOR(i, n) repr[i] = i, value[i] = 0;
	}

	int Find(int a){
		if(a == repr[a]) return a;
		return repr[a] = Find(repr[a]);
	}

	ll& Val(int a){
		return value[Find(a)];
	}

	std::priority_queue<PII, std::vector<PII>, std::greater<PII>>& Wait(int a){
		return wait[Find(a)];
	}

	int Union(int a, int b){
		a = Find(a);
		b = Find(b);
		if(a == b) return 0;
		if(SZ(wait[a]) > SZ(wait[b])) std::swap(a, b);
		while(SZ(wait[a])){
			wait[b].push(wait[a].top());
			wait[a].pop();
		}
		value[b] += value[a];
		repr[a] = b;
		return 1;
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, x;
	std::cin >> n >> m >> x;
	VI A(n);
	ll sum = 0;
	FOR(i, n) std::cin >> A[i], sum += A[i];
	if(sum < 1ll*(n-1)*x){
		std::cout << "NO\n";
		return 0;
	}

	std::cout << "YES\n";
	std::vector<VI> g(n);
	std::vector<PII> edges;
	std::vector<int> edges_ind;
	{
		UF uf(n);
		FOR(i, m){
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			if(uf.Union(a, b)){
				g[a].push_back(b);
				g[b].push_back(a);
				edges.push_back(MP(a, b));
				edges_ind.push_back(i);
			}
		}
	}

	std::vector<std::priority_queue<PII>> wait(n);
	std::queue<int> ready;
	std::vector<bool> done(n-1);
	UFV uf(n);
	FOR(i, n) uf.Val(i) = A[i];
	assert(SZ(edges) == n-1);
	FOR(i, n-1){
		int a = edges[i].X;
		int b = edges[i].Y;
		ll vals = uf.Val(a) + uf.Val(b);
		if(vals < x){
			ll need = x - vals;
			ll cl = (need + 1) / 2;
			uf.Wait(a).push(MP(uf.Val(a) + cl, i));
			uf.Wait(b).push(MP(uf.Val(b) + cl, i));
		}else{
			ready.push(i);
			done[i] = true;
		}
	}

	VI ans;

	while(SZ(ans) < n-1){
		assert(SZ(ready));

		int ind = ready.front();
		ready.pop();
		{

			int a = edges[ind].X;
			int b = edges[ind].Y;
			ll vals = uf.Val(a) + uf.Val(b);
			if(vals < x) {
				ll need = x - vals;
				ll cl = (need + 1) / 2;
				uf.Wait(a).push(MP(uf.Val(a) + cl, ind));
				uf.Wait(b).push(MP(uf.Val(b) + cl, ind));
				done[ind] = false;
				continue;
			}
		}

		uf.Union(edges[ind].X, edges[ind].Y);
		int rep = uf.Find(edges[ind].X);
		uf.Val(rep) -= x;

		ans.push_back(edges_ind[ind]);

		auto &qq = uf.Wait(rep);
		while(SZ(qq) && qq.top().X <= uf.Val(rep)){
			int ed = qq.top().Y;
			qq.pop();

			if(done[ed]) continue;

			int a = edges[ed].X;
			int b = edges[ed].Y;
			ll vals = uf.Val(a) + uf.Val(b);

			if(vals < x){
				ll need = x - vals;
				ll cl = (need + 1) / 2;
				uf.Wait(a).push(MP(uf.Val(a) + cl, ed));
				uf.Wait(b).push(MP(uf.Val(b) + cl, ed));
			}else{
				ready.push(ed);
				done[ed] = true;
			}
		}
	}

	assert(SZ(ans) == n-1);
	FOR(i, n-1) std::cout << ans[i]+1 << " ";

	return 0;
}