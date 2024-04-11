#include"bits/stdc++.h"
typedef long long ll;
using namespace std;
const int N=1005,M=100005;
int n,m,k,c[N],u[M],v[M],fa[N],sz[N],ans,mark[N],mx,tmp;
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy)fa[fx]=fy,sz[fy]+=sz[fx];
}
int main(){
	scanf("%d%d%d",&n,&m,&k);ans=-m;tmp=mx=0;
	for(int i=1;i<=k;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		merge(u[i],v[i]);
	}
	for(int i=1;i<=k;i++)mark[find(c[i])]=1;
	for(int i=1;i<=k;i++)mx=max(mx,sz[find(c[i])]);
	for(int i=1;i<=n;i++)if(fa[i]==i&&mark[i])
		ans+=sz[i]*(sz[i]-1)/2;
	for(int i=1;i<=n;i++)if(fa[i]==i&&!mark[i])
		tmp+=sz[i];
	ans+=(mx+mx+tmp-1)*tmp/2;
	printf("%d\n",ans);
	return 0;
}