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

struct Edge{
	int v, c, ind;
	Edge(){}
	Edge(int _b, int _c, int _i) : v(_b), c(_c), ind(_i) {}
};

int n, m;
std::vector<std::vector<Edge> > g;
VI ans;
std::vector<int> col;
int th;
bool fail;
std::stack<int> stack;
void dfs(int v){
	col[v] = 1;
	TRAV(ed, g[v]){
		if(ed.c <= th) continue;
		int ch = ed.v;
		if(fail) return;
		if(col[ch] == 2) continue;
		if(col[ch] == 1){
			fail = true;
			return;
		}
		dfs(ch);
	}
	stack.push(v);
	col[v] = 2;
}

bool check(int thhh){
	fail = false;
	th = thhh;
	ans.clear();
	while(!stack.empty()) stack.pop();
	std::fill(col.begin(), col.end(), 0);
	FOR(i, n) if(col[i] == 0){
		dfs(i);
		if(fail) return false;
	}
	return true;
}

void getwrong(){
	VI ord(n);
	int cur = 0;
	while(!stack.empty()){
		ord[stack.top()] = cur++;
		stack.pop();
	}
	FOR(i, n){
		TRAV(ed, g[i]){
			if(ord[i] > ord[ed.v]) ans.push_back(ed.ind);
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	col.resize(n);
	g.resize(n);
	col.resize(n);
	FOR(i, m){
		int a, b, c;
		std::cin >> a >> b >> c;
		a--;b--;
		g[a].push_back(Edge(b, c, i));
	}
	int left = 0, right = 1000000002;
	while(left < right){
		int mid = (left+right)/2;
		if(check(mid)) right = mid;
		else left = mid+1;
	}
	check(left);
	getwrong();
	std::cout << left << " " << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << i+1 << " ";
	return 0;
}