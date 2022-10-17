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

constexpr int MOD = 998244353;
constexpr int INF = 1000000666;

struct S{
	std::vector<PII> prze;
	int last;

	S(){
		last = 0;
	}

	S(int a){
		last = 0;
		if(a){
			prze.push_back(MP(0, a-1));
		}
	}

	void add(const S& s){
		auto& p1 = prze;
		auto& p2 = s.prze;
		auto it = p1.begin();
		auto jt = p2.begin();

		int pos = -5;
		std::vector<PII> ret;

		while(it != p1.end() || jt != p2.end()){
			if(it == p1.end() || (jt != p2.end() && jt->X + 1 <= it->X)){
				if(jt->X+1 > pos){
					ret.push_back(MP(jt->X + 1, jt->Y + 1));
					pos = jt->Y + 2;
				}else{
					ret.back().Y += jt->Y - jt->X + 1;
				}
				++jt;
			}else{
				if(it->X > pos){
					ret.push_back(MP(it->X, it->Y));
					pos = it->Y + 1;
				}else{
					ret.back().Y += it->Y - it->X + 1;
				}
				++it;
			}
		}
		last = (last + s.last) % MOD;
		prze = std::move(ret);

		while(SZ(prze) && prze.back().Y > INF){
			int pcz = std::max(prze.back().X, INF);
			int ile = (prze.back().Y - pcz + 1) % MOD;
			last = (last + ile) % MOD;
			prze.back().Y = pcz - 1;
			if(prze.back().Y < prze.back().X) prze.pop_back();
		}
	}

	int ans(){
		if(prze.empty()) return 0;
		return (prze.back().Y + last + 1)%MOD;
	}
};

void solve(){
	int n, m;
	std::cin >> n >> m;
	VI A(n);
	FOR(i, n){
		std::cin >> A[i];
	}
	std::vector<VI> g(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
	}
	VI topo;
	std::vector<bool> vis(n);
	std::function<void(int)> dfs = [&](int v){
		vis[v] = true;
		TRAV(ch, g[v]) if(!vis[ch]) dfs(ch);
		topo.push_back(v);
	};
	FOR(i, n) if(!vis[i]) dfs(i);
	std::reverse(topo.begin(), topo.end());

	std::vector<S> sk(n);
	FOR(i, n) sk[i] = S(A[i]);
	TRAV(v, topo){
		TRAV(ch, g[v]){
			sk[ch].add(sk[v]);
		}
	}

	std::cout << sk[topo.back()].ans() << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}