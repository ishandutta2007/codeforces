#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n,m;
vector<pair<int,int> > adj[100013];
vector<vector<int> > ops;
vector<int> hason[200013];

int on(int x) { return x*2-2; }
int off(int x) { return x*2-1; }
int p[200013];
int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) { p[find(a)] = find(b); }

void solve() {
	iota(p,p+2*n+1,0);
	for (int i=1;i<=n;i++) {
		for (auto p: adj[i]) {
			int j = p.A;
			if (p.B) {
				merge(on(i),off(j));
				merge(off(i),on(j));
			} else {
				merge(on(i),on(j));
				merge(off(i),off(j));
			}
		}
	}
	for (int i=1;i<=n;i++) if (find(on(i))==find(off(i))) {
		ops.push_back(vector<int>(n+1));
		return;
	}
	for (int i=1;i<=2*n;i++) hason[i].clear();
	for (int i=1;i<=n;i++) {
		hason[find(on(i))].push_back(i);
	}
	ops.push_back(vector<int>());
	for (int i=1;i<=2*n;i+=2) if (find(i)==i) {
		int j = i;
		if (hason[i^1].size()<hason[i].size()) j = i^1;
		for (int k: hason[j]) ops.back().push_back(k);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		char c;
		scanf("%d%d %c",&a,&b,&c);
		adj[a].push_back(MP(b,(c=='R')));
		adj[b].push_back(MP(a,(c=='R')));
	}
	solve();
	for (int i=1;i<=n;i++) {
		for (auto& j: adj[i]) j.B^=1;
	}
	solve();
	int ans = min(ops[0].size(),ops[1].size());
	if (ans>n) printf("-1\n");
	else {
		printf("%d\n",ans);
		for (int d=0;d<2;d++) if (ops[d].size()==ans) {
			for (int i: ops[d]) printf("%d ",i);
			printf("\n");
			break;
		}
	}

	return 0;
}