#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int c[100013];
vector<int> adj[100013];
ll ans[100013];
map<int,int> has[100013];
int high[100013];

void insert(int x, int num, int cnt) {
	has[x][num]+=cnt;
	int cur = has[x][num];
	if (cur>high[x]) high[x] = cur, ans[x] = 0;
	if (cur==high[x]) ans[x]+=num;
}

void dfs(int x, int p=0) {
	if (p) adj[x].erase(find(adj[x].begin(),adj[x].end(),p));
	for (int i: adj[x]) dfs(i,x);
	insert(x,c[x],1);
	if (adj[x].size()) {
		int large = adj[x][0];
		for (int i: adj[x]) if (has[i].size()>has[large].size()) large = i;
		swap(has[x],has[large]);
		high[x] = high[large];
		ans[x] = ans[large];
		insert(x,c[x],1);
		for (int i: adj[x]) if (i!=large) {
			for (auto j: has[i]) insert(x,j.first,j.second);
		}
	}
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	printf("\n");

	return 0;
}