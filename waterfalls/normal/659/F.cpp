#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MP make_pair
#define A first
#define B second

int p[1000013];
int s[1000013];
int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) {
	if (find(a)==find(b)) return;
	s[find(b)]+=s[find(a)];
	p[find(a)] = find(b);
}

int n,m;
ll k;
vector<int> adj[1000013];
int a[1000013];
bool in[1000013];
vector<pair<int,int> > has;

int get(int i, int j) {
	return (i-1)*m+j-1;
}

int need;
bool mark[1000013];
void dfs(int x, int v) {
	mark[x] = 1;
	need-=1;
	for (int i: adj[x]) if (!mark[i] && a[i]>=v) {
		if (!need) return;
		dfs(i,v);
	}
}
void solve(int x, int v) {
	need = k/v;
	dfs(x,v);
	printf("YES\n");
	for (int i=1;i<=n/m;i++) {
		for (int j=1;j<=m;j++) {
			if (mark[get(i,j)]) printf("%d ",v);
			else printf("0 ");
		}
		printf("\n");
	}
	exit(0);
}

int main() {
	scanf("%d%d%lld",&n,&m,&k);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			scanf("%d",&a[get(i,j)]);
			has.push_back(MP(a[get(i,j)],get(i,j)));
			if (i>1) adj[get(i,j)].push_back(get(i-1,j));
			if (j>1) adj[get(i,j)].push_back(get(i,j-1));
			if (i<n) adj[get(i,j)].push_back(get(i+1,j));
			if (j<m) adj[get(i,j)].push_back(get(i,j+1));
		}
	}
	n*=m;
	iota(p,p+n+1,0);
	fill(s,s+n+1,1);
	sort(has.begin(),has.end());
	reverse(has.begin(),has.end());
	for (auto p: has) {
		int v = p.A;
		int i = p.B;
		in[i] = 1;
		for (int j: adj[i]) if (in[j]) merge(i,j);
		if (k%v==0) {
			if (s[find(i)]>=k/v) solve(i,v);
		}
	}
	printf("NO\n");

	return 0;
}