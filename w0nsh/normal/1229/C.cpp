#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

struct Edge{
	int a, b, ka;
	Edge(){}
	Edge(int x, int y, int z) : a(x), b(y), ka(z) {}
};

std::vector<Edge> edges;
ll ans;
int n, m;
std::vector<VI> in, out;

void get(int v){
	ans -= 1ll*SZ(in[v])*SZ(out[v]);
	while(SZ(in[v])){
		int i = in[v].back();
		auto &ed = edges[in[v].back()];
		in[v].pop_back();	
		int ch = ed.a;
		ans -= 1ll*SZ(in[ch])*SZ(out[ch]);

		std::swap(out[ch].back(), out[ch][ed.ka]);
		edges[out[ch][ed.ka]].ka = ed.ka;
		out[ch].pop_back();

		in[ch].push_back(i);
		out[v].push_back(i);
		std::swap(ed.a, ed.b);
		ed.ka = SZ(out[v])-1;
		ans += 1ll*SZ(in[ch])*SZ(out[ch]);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	in.resize(n);
	out.resize(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		if(a > b) std::swap(a, b);
		edges.push_back(Edge(b, a, SZ(out[b])));
		in[a].push_back(SZ(edges)-1);
		out[b].push_back(SZ(edges)-1);
	}
	FOR(i, n) ans += 1ll*SZ(in[i])*SZ(out[i]);
	std::cout << ans << "\n";
	int q;
	std::cin >> q;
	FOR(i, q){
		int a;
		std::cin >> a;
		a--;
		get(a);
		std::cout << ans << "\n";
	}

	return 0;
}