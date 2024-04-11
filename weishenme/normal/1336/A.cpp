#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int size[N],n,m,x,y,sd[N],f[N];
vector<int > G[N];
long long ans;
int cmp(int x,int y){
	return size[x]-sd[x]>size[y]-sd[y];
}
void dfs(int x,int y){
	size[x]=1;
	for (int i:G[x])if (i!=y){
		sd[i]=sd[x]+1;
		dfs(i,x);
		size[x]+=size[i];
	}
}
signed main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	m=n-m;
	for (int i=1;i<=n;i++)f[i]=i;
	sort(f+1,f+n+1,cmp);
	for (int i=1;i<=m;i++)ans+=size[f[i]]-sd[f[i]]-1;
	printf("%lld\n",ans);
}