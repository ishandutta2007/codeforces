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

int n;
VI A, B;
std::map<int, int> map;
int prze[200005];
int sub[200005];
std::vector<std::set<PII> > g;

std::vector<bool> vis;

void connected(int v){
	vis[v] = true;
	TRAV(ch, g[v]){
		if(!vis[ch.X]) connected(ch.X);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n-1);
	B.resize(n-1);
	std::set<int> have;
	FOR(i, n-1) std::cin >> A[i], have.insert(A[i]);
	FOR(i, n-1) std::cin >> B[i], have.insert(B[i]);
	FOR(i, n-1) if(A[i] > B[i]){
		std::cout << -1;
		return 0;
	}
	int cnt = 0;
	TRAV(i, have){
		map[i] = cnt;
		prze[cnt] = i;
		cnt++;
	}
	FOR(i, n-1) A[i] = map[A[i]];
	FOR(i, n-1) B[i] = map[B[i]];

	g.resize(SZ(have));
	FOR(i, n-1){
		if(A[i] == B[i]){
			g[A[i]].insert(MP(B[i], i));
			sub[A[i]]++;
		}
		else{

			g[A[i]].insert(MP(B[i], i));
			g[B[i]].insert(MP(A[i], i));
		}
	}
	int cntnot = 0;
	int start = 0;
	FOR(i, SZ(have)){
		if((SZ(g[i])-sub[i]) % 2 == 1){
			cntnot++;
			start = i;
		}
	}
	if(cntnot != 0 && cntnot != 2){
		std::cout << -1;
		return 0;
	}
	vis.resize(SZ(have));
	connected(0);
	FOR(i, SZ(have)) if(!vis[i]){
		std::cout << -1;
		return 0;
	}
	std::fill(vis.begin(), vis.end(), false);
	std::stack<PII> stack;
	PII cur = MP(start, -1);
	std::vector<PII> path;
	while(true){
		if(SZ(g[cur.X]) > 0){
			auto ed = *g[cur.X].begin();
			g[cur.X].erase(g[cur.X].begin());
			if(cur.X != ed.X) g[ed.X].erase(MP(cur.X, ed.Y));
			stack.push(cur);
			cur = ed;
		}else{
			// std::cout << "dodaje " << prze[cur.X] << std::endl;
			path.push_back(cur);
			if(stack.empty()) break;
			cur = stack.top();
			stack.pop();
		}
	}
	TRAV(i, path) std::cout << prze[i.X] << " ";
	return 0;
}