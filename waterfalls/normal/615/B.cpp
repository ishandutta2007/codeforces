#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[100013];
long long ans[100013];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i=1;i<=n;i++) {
		ans[i] = 1;
		for (int j: adj[i]) {
			if (j<i) ans[i] = max(ans[i],ans[j]+1);
		}
	}
	for (int i=1;i<=n;i++) ans[i]*=adj[i].size();
	printf("%lld\n",*max_element(ans,ans+n+1));

	return 0;
}