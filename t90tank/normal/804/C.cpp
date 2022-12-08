#include <bits/stdc++.h>

using namespace std;

const int maxn = 300006; 

int n, m; 
vector<int> p[maxn]; 
vector<int> q[maxn]; 
vector<int> e[maxn]; 
int d[maxn]; 
int dc[maxn]; 
int col[maxn]; 

struct CMP2 {
	bool operator()(int a, int b) const {
		return tie(dc[a],a) > tie(dc[b],b); 
	}
}; 
set<int, CMP2> pc[maxn]; 

struct CMP {
	bool operator()(int a, int b) const {
		return make_pair(make_pair(pc[a].size(), -d[a]),a) > make_pair(make_pair(pc[b].size(), -d[b]),b); 
	}
}; 
set<int, CMP> S; 


bool cmp(int x, int y) {
	return dc[x] < dc[y]; 
}

void Delcolor(int c) {
	for (auto i : q[c]) {
		assert(S.find(i) != S.end()); 
		S.erase( S.find( i ) ); 
		assert(pc[i].find(c) != pc[i].end()); 
		pc[i].erase( pc[i].find(c) ); 
		S.insert( i ); 
	}
}

void dfs(int x, int f) {
	for (auto i : e[x]) 
		if ( i != f ) {
			d[i] = d[x] + 1;
			dfs(i, x); 
		}
}

int main() {
	scanf( "%d%d", &n, &m ); 
	//int D = 300000; 
	//n = D, m = D; 
	for (int i = 1; i <= n; ++i) {
		int s; 
		scanf( "%d", &s ); 
		//s = 2; 
		for (int j = 1; j <= s; ++j) {
			int x; 
			scanf( "%d", &x ); 
			//x = rand() % m + 1; 
			p[i].push_back(x); 
			q[x].push_back(i); 
		}
	}
	for (int i = 1; i < n; ++i) {
		int a, b; 
		scanf( "%d%d", &a, &b ); 
		//a = i, b = i+1; 
		e[a].push_back( b ); 
		e[b].push_back( a ); 
	}
	d[1] = 1; 
	dfs( 1, 0 ); 
	for (int i = 1; i <= m; ++i) {
		dc[i] = n+1; 
		for (auto j : q[i]) 
			dc[i] = min(dc[i], d[j]); 
	}
	for (int i = 1; i <= n; ++i) 
		for (auto j : p[i]) 
			pc[i].insert(j); 
	for (int i = 1; i <= n; ++i) S.insert(i); 
	for (int i = 1; i <= m; ++i) col[i] = 1; 
	while (1) {
		int x = *S.begin(); 
		//cout<<x<<endl; 
		if (pc[x].size() == 0) break; 
		int u = *pc[x].begin(); 
		col[u] = pc[x].size(); 
		Delcolor(u);
	}
	int CC = 0;
	for (int i = 1; i <= m; ++i) CC = max( CC, col[i] ); 
	cout<<CC<<endl; 
	for (int i = 1; i <= m; ++i) printf( "%d ", col[i] ); 
	printf( "\n" ); 
}