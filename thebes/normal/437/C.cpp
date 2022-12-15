#include <bits/stdc++.h>
using namespace std;

const int MN = 1003;
int n, m, val[MN], i, x, y, id[MN];
vector<int> adj[MN];
long long ans;

int main(){
	for(scanf("%d%d",&n,&m),i=1;i<=n;i++)
		scanf("%d",&val[i]),id[i]=i;
	for(i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	sort(id+1, id+n+1, [](int i,int j){return(val[i]>val[j]);});
	for(i=1;i<=n;i++){
		for(auto v : adj[id[i]])
			ans += val[v];
		val[id[i]]=0;
	}
	printf("%lld\n",ans);
	return 0;
}