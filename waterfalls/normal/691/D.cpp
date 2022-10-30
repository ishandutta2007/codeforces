#include <bits/stdc++.h>
using namespace std;

int p[1000013];
int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) { p[find(a)] = find(b); }

int n,m;
int x[1000013];
vector<int> has[1000013], vals[1000013];

int main() {
	scanf("%d%d",&n,&m);
	iota(p,p+n+1,0);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	while (m--) {
		int a,b;
		scanf("%d%d",&a,&b);
		merge(a,b);
	}
	for (int i=1;i<=n;i++) {
		has[find(i)].push_back(i);
		vals[find(i)].push_back(x[i]);
	}
	for (int i=1;i<=n;i++) {
		sort(vals[i].begin(),vals[i].end(),greater<int>());
		for (int j=0;j<vals[i].size();j++) x[has[i][j]] = vals[i][j];
	}
	for (int i=1;i<=n;i++) printf("%d ",x[i]);
	printf("\n");

	return 0;
}