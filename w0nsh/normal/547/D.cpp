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

const int N = 200005;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<PII> edge;
	std::vector<std::vector<PII> > g(2*N);
	std::vector<bool> dead;
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		b += N;
		edge.push_back(MP(a, b));
		dead.push_back(false);
		g[a].push_back(MP(b, i));
		g[b].push_back(MP(a, i));
	}

	VI later;
	std::set<int> set;
	FOR(i, 2*N) if(SZ(g[i]) % 2 != 0) set.insert(i);

	while(SZ(set)){
		int v = *set.begin();
		set.erase(set.begin());

		while(dead[g[v].back().Y]) g[v].pop_back();
		int w = g[v].back().X;
		int ind = g[v].back().Y;
		dead[ind] = true;
		g[v].pop_back();

		if(set.count(w)) set.erase(w);
		else set.insert(w);

		later.push_back(ind);
	}

	VI eu;
	std::function<void(int)> euler = [&](int v){
		while(SZ(g[v])){
			int i = g[v].back().X;
			int ind = g[v].back().Y;
			g[v].pop_back();

			if(!dead[ind]){
				dead[ind] = true;
				euler(i);
				eu.push_back(ind);
			}
		}
	};

	FOR(i, 2*N) euler(i);
	VI ans(n);
	FOR(i, SZ(eu)) ans[eu[i]] = i%2;

	VI bilance(N*2);
	while(SZ(later)){
		int ind = later.back();
		later.pop_back();
		int a = edge[ind].X;
		int b = edge[ind].Y;

		if(bilance[b] == 0) std::swap(a, b);
		assert(bilance[a] == 0);
		if(bilance[b] == 1) ans[ind] = 0, bilance[b]--, bilance[a]--;
		else ans[ind] = 1, bilance[b]++, bilance[a]++;
	}

	FOR(i, SZ(ans)) std::cout << (ans[i] ? 'b' : 'r');

	return 0;
}