#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n;
vector<pair<int,int> > adj[200013];
vector<int> has[200013];

void dfs(int x, int p=0, int use=0) {
	int on = 0;
	for (auto i: adj[x]) if (i.A!=p) {
		while (++on==use);
		has[on].push_back(i.B);
		dfs(i.A,x,on);
	}
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(MP(b,i));
		adj[b].push_back(MP(a,i));
	}
	dfs(1);
	int ans = n;
	while (!has[ans].size()) ans-=1;
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++) {
		printf("%d ",has[i].size());
		for (int j: has[i]) printf("%d ",j);
		printf("\n");
	}

	return 0;
}