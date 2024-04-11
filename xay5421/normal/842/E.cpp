#include<cstdio>
const int N=300005,K=20;
int m,maxd,dep[N],fa[N][K],s1[N],s2[N],top1,top2;
void add(int u,int v){
	dep[u]=dep[v]+1,fa[u][0]=v;
	for(int i=1;i<K;++i)fa[u][i]=fa[fa[u][i-1]][i-1];
}
int lca(int u,int v){
	if(dep[u]<dep[v])u^=v^=u^=v;int ret=dep[u]-dep[v];
	for(int i=K-1;i>=0;--i)if(ret>>i&1)u=fa[u][i];if(u==v)return u;
	for(int i=K-1;i>=0;--i)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];return fa[u][0];
}
int dist(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}
int main(){
	add(1,0);s1[top1=1]=1;
	scanf("%d",&m);
	for(int i=2;i<=m+1;++i){
		int u;scanf("%d",&u),add(i,u);
		int d1=top1?dist(i,s1[1]):0,d2=top2?dist(i,s2[1]):0,d3=d1<d2?d2:d1;
		if(d3>maxd){
			maxd=d3;
			if(d1==d3){
				for(int j=1;j<=top2;++j)if(dist(s2[j],i)==maxd)s1[++top1]=s2[j];
				top2=0;
			}else{
				for(int j=1;j<=top1;++j)if(dist(s1[j],i)==maxd)s2[++top2]=s1[j];
				top1=0;
			}
		}
		if(d3==maxd){
			if(d1==d3)s2[++top2]=i;
			else s1[++top1]=i;
		}
		printf("%d\n",top1+top2);
	}
	return 0;
}