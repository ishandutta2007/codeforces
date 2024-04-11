#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[200013];
bool bad[200013];
int s[200013];
vector<int> dp[200013];
vector<int> far[200013];

void dfs(int x, int p=0) {
	for (int i=0;i<adj[x].size();i++) if (adj[x][i]==p) adj[x].erase(adj[x].begin()+i);
	if (x==1) dp[x].push_back(0), far[x].push_back(0);
	s[x] = bad[x];
	for (int j=0;j<adj[x].size();j++) {
		int i = adj[x][j];
		dfs(i,x);
		s[x]+=s[i];
		if (s[i]>0) {
			far[x][j] = far[i].back()+1;
			far[x].back() = max(far[x].back(),far[i].back()+1);
			dp[x][j] = 2+dp[i].back();
			dp[x].back()+=2+dp[i].back();
		}
	}
}

int best = 1e9, which = 0;
void dfs2(int x, int above=0, int abovefar=0) {
	int cur = above+dp[x].back()-max(far[x].back(),abovefar);
	if (cur<best || (cur==best && x<which)) {
		best = cur;
		which = x;
	}
	vector<int> pref(adj[x].size());
	for (int i=1;i<adj[x].size();i++) pref[i] = max(far[x][i-1],pref[i-1]);
	vector<int> suff(adj[x].size());
	if (adj[x].size()>=2) for (int i=adj[x].size()-2;i>=0;i--) suff[i] = max(far[x][i+1],suff[i+1]);
	for (int j=0;j<adj[x].size();j++) {
		int i = adj[x][j];
		if (s[i]==s[1]) dfs2(i,0,0);
		else dfs2(i,above+dp[x].back()-dp[x][j]+2,max(abovefar,max(pref[j],suff[j]))+1);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		dp[a].push_back(0);
		far[a].push_back(0);
		adj[b].push_back(a);
		dp[b].push_back(0);
		far[b].push_back(0);
	}
	for (int i=0;i<m;i++) {
		int x;
		scanf("%d",&x);
		bad[x] = 1;
	}
	dfs(1);
	dfs2(1);
	printf("%d\n%d\n",which,best);

	return 0;
}