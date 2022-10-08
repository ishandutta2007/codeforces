#include"bits/stdc++.h"
using namespace std;
const int N=100005;
int h[N],nxt[2*N],c[2*N],to[2*N],a[N],n,m,k,tmp,ans=0x7fffffff;
bool mark[N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,l;scanf("%d%d%d",&u,&v,&l);
		c[++tmp]=l;nxt[tmp]=h[u];h[u]=tmp;to[tmp]=v;
		c[++tmp]=l;nxt[tmp]=h[v];h[v]=tmp;to[tmp]=u;
	}
	for(int i=1;i<=k;i++)scanf("%d",&a[i]),mark[a[i]]=1;
	for(int i=1;i<=k;i++)
		for(int j=h[a[i]];j;j=nxt[j])
			if(!mark[to[j]])ans=min(ans,c[j]);
	printf("%d\n",ans==0x7fffffff?-1:ans);
}