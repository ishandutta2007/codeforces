#include <bits/stdc++.h>
using namespace std;

int h[100013];
int counter = 0;
int s[100013], e[100013];
int up[17][100013];
int in[100013];

int lca(int a, int b) {
	if (h[a]>h[b]) swap(a,b);
	for (int i=16;i>=0;i--) if ((h[b]-h[a])&(1<<i)) b = up[i][b];
	if (a==b) return a;
	for (int i=16;i>=0;i--) if (up[i][a]!=up[i][b]) a = up[i][a], b = up[i][b];
	return up[0][a];
}

int ans;
vector<int> vir[100013];
int dfs(int x) {
	int has = in[x];
	for (int i: vir[x]) {
		int res = dfs(i);
		if (in[x] && res) ans+=1;
		else has+=res;
	}
	if (!in[x] && has>1) {
		ans+=1;
		return 0;
	} else if (!in[x]) return has;
	else return 1;
}

bool comp(int a, int b) { return s[a]<s[b]; }
void solve(vector<int>& has) {
	int k = has.size();
	sort(has.begin(),has.end(),comp);
	for (int i=0;i<k-1;i++) {
		has.push_back(lca(has[i],has[i+1]));
	}
	sort(has.begin(),has.end(),comp);
	has.erase(unique(has.begin(),has.end()),has.end());
	stack<int> path;
	for (int i: has) {
		while (path.size() && e[path.top()]<s[i]) path.pop();
		if (path.size()) vir[path.top()].push_back(i);
		path.push(i);
	}
	ans = 0;
	dfs(has[0]);
	printf("%d\n",ans);
	for (int i: has) vir[i].clear();
}

int n,q;
vector<int> adj[100013];

void setup(int x, int p=0, int d=0) {
	s[x] = ++counter;
	h[x] = d;
	up[0][x] = p;
	for (int i: adj[x]) if (i!=p) setup(i,x,d+1);
	e[x] = counter;
}
void build() {
	setup(1);
	for (int i=1;i<17;i++) for (int j=1;j<=n;j++) {
		up[i][j] = up[i-1][up[i-1][j]];
	}
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n-1;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build();
	scanf("%d",&q);
	for (int i=0;i<q;i++) {
		vector<int> has;
		int k;
		scanf("%d",&k);
		for (int j=0;j<k;j++) {
			int x;
			scanf("%d",&x);
			has.push_back(x);
			in[x] = 1;
		}
		bool ok = 1;
		for (int j: has) if (in[up[0][j]]) ok = 0;
		if (!ok) printf("-1\n");
		else solve(has);
		for (int j: has) in[j] = 0;
	}

	return 0;
}