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

int n, m, repr[2005];
VI g[2005];

int Find(int a){
	if(a == repr[a]) return a;
	return repr[a] = Find(repr[a]);
}

void Union(int a, int b){
	repr[Find(a)] = Find(b);
}

void fail(){
	std::cout << "No\n";
	std::exit(0);
}

int tab[1005][1005];

bool vis[2005];
int col[2005], num[2005];
int dfs(int v){
	vis[v] = true;
	col[v] = 1;
	int mxnum = 1;
	TRAV(ch, g[v]){
		if(col[ch] == 1) fail();
		if(col[ch] == 2){
			mxnum = std::max(mxnum, num[ch]+1);
			continue;
		}
		mxnum = std::max(mxnum, dfs(ch)+1);
	}
	col[v] = 2;
	num[v] = mxnum;
	return num[v];
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	FOR(i, n+m) repr[i] = i;
	FOR(i, n) FOR(j, m){
		char xd;
		std::cin >> xd;
		if(xd == '='){
			tab[i][j] = 0;
			Union(i, n+j);
		}else if(xd == '>'){
			tab[i][j] = 1;
		}else tab[i][j] = -1;
	}
	FOR(i, n) FOR(j, m){
		if(tab[i][j] == 1) g[Find(i)].push_back(Find(n+j));
		else if(tab[i][j] == -1) g[Find(n+j)].push_back(Find(i)); 
	}
	FOR(i, n+m){
		if(!vis[Find(i)]) dfs(Find(i));
	}
	std::cout << "Yes\n";
	FOR(i, n) std::cout << num[Find(i)] << " ";
	std::cout << "\n";
	FOR(i, m) std::cout << num[Find(i+n)] << " ";
	return 0;
}