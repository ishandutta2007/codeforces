#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int> > a;
vector<int> adj[1000013];

int p[1000013];
int get(int a, int b) { return a*m+b; }
int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) { p[find(a)] = find(b); }

int val[1000013];
void dfs(int x) {
	if (val[x]) return;
	int high = 0;
	for (int i: adj[x]) {
		dfs(i);
		high = max(high,val[i]);
	}
	val[x] = high+1;
}

int main() {
	scanf("%d%d",&n,&m);
	a = vector<vector<int> >(n,vector<int>(m));
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) scanf("%d",&a[i][j]);
	}
	iota(p,p+n*m,0);
	for (int i=0;i<n;i++) {
		map<int,int> ind;
		for (int j=0;j<m;j++) {
			auto it = ind.find(a[i][j]);
			if (it!=ind.end()) merge(get(i,j),it->second);
			else ind[a[i][j]] = get(i,j);
		}
	}
	for (int j=0;j<m;j++) {
		map<int,int> ind;
		for (int i=0;i<n;i++) {
			auto it = ind.find(a[i][j]);
			if (it!=ind.end()) merge(get(i,j),it->second);
			else ind[a[i][j]] = get(i,j);
		}
	}
	for (int i=0;i<n;i++) {
		map<int,int> ind;
		for (int j=0;j<m;j++) {
			ind[a[i][j]] = find(get(i,j));
		}
		while (ind.size()>1) {
			auto p = ind.begin();
			auto q = p;
			++q;
			adj[q->second].push_back(p->second);
			ind.erase(p);
		}
	}
	for (int j=0;j<m;j++) {
		map<int,int> ind;
		for (int i=0;i<n;i++) {
			ind[a[i][j]] = find(get(i,j));
		}
		while (ind.size()>1) {
			auto p = ind.begin();
			auto q = p;
			++q;
			adj[q->second].push_back(p->second);
			ind.erase(p);
		}
	}
	for (int i=0;i<n*m;i++) if (find(i)==i) {
		dfs(i);
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			printf("%d ",val[find(get(i,j))]);
		}
		printf("\n");
	}

	return 0;
}