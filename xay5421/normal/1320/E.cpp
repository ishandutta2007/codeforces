#include<cstdio>
#include<cassert>
#include<cstring>
#include<algorithm>
#define D(...) fprintf(stderr,__VA_ARGS__) 
using namespace std;
const int N=200005,K=20;
int n,Q,k,m,ind,top,tin[N],v[N],s[N],u[N],num[N*2],dep[N],f[N][K],st[N],ans[N],tim[N],ord[N];
struct ed{int nxt,to;}G[N<<1];int lnk[N],pp;
void ae(int k1,int k2){
//	D(">>> ae %d %d\n",k1,k2);
	G[++pp]=(ed){lnk[k1],k2},lnk[k1]=pp;
}
void init(int k1,int k2){
	int i,j;tin[k1]=++ind;
	for(i=1;i<K;++i)f[k1][i]=f[f[k1][i-1]][i-1];
	for(i=lnk[k1];i;i=G[i].nxt)if((j=G[i].to)!=k2)f[j][0]=k1,dep[j]=dep[k1]+1,init(j,k1);
}
int lca(int k1,int k2){
	int i;
	if(dep[k1]<dep[k2])swap(k1,k2);int ret=dep[k1]-dep[k2];
	for(i=K-1;i>=0;--i)if(ret>>i&1)k1=f[k1][i];if(k1==k2)return k1;
	for(i=K-1;i>=0;--i)if(f[k1][i]!=f[k2][i])k1=f[k1][i],k2=f[k2][i];return f[k1][0];
}
int dist(int k1,int k2){return dep[k1]+dep[k2]-dep[lca(k1,k2)]*2;}
bool cmp(int k1,int k2){return tin[k1]<tin[k2];}
void up(int k1,int k2){
	if(k1){
		int len=(dist(k1,k2)+s[k1]-1)/s[k1];
		if(len<tim[k2]||(len==tim[k2]&&ord[k1]<ord[ans[k2]]))ans[k2]=k1,tim[k2]=len;
	}
}
void dfs(int k1){
	int i,j;
	for(i=lnk[k1];i;i=G[i].nxt){
		j=G[i].to;
		up(ans[k1],j);
		dfs(j);
	}
}
void dfs2(int k1){
//	D(">>> %d\n",k1);
	int i,j;
	for(i=lnk[k1];i;i=G[i].nxt){
		j=G[i].to;
		dfs2(j);
		up(ans[j],k1);
	}
}
void del(int k1){
	int i,j;
	for(i=lnk[k1];i;i=G[i].nxt){
		j=G[i].to;
		del(j);
	}
	lnk[k1]=0,ans[k1]=0,tim[k1]=0x3f3f3f3f,ord[k1]=0;
}
int main(){
	int i,k1,k2,tot;
	memset(tim,63,sizeof(tim));
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&k1,&k2),ae(k1,k2),ae(k2,k1);
	init(1,0);
	memset(lnk,0,sizeof(lnk)),pp=0;
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&k,&m);tot=top=0;
		for(i=1;i<=k;++i)scanf("%d",&v[i]),scanf("%d",&s[v[i]]),num[++tot]=v[i],ans[v[i]]=v[i],tim[v[i]]=0,ord[v[i]]=i;
		for(i=1;i<=m;++i)scanf("%d",&u[i]),num[++tot]=u[i];
		sort(num+1,num+1+tot,cmp);
		st[++top]=1;
		for(i=1;i<=tot;++i){
			int l=lca(st[top],num[i]);
			while(top>1&&dep[st[top-1]]>=dep[l])ae(st[top-1],st[top]),--top;
			if(st[top]!=l)ae(l,st[top]);
			st[top]=l;
			if(l!=num[i])st[++top]=num[i];
		}
		for(i=1;i<top;++i)ae(st[i],st[i+1]);
		dfs2(1);
		dfs(1);
		for(i=1;i<=m;++i)printf("%d%c",ord[ans[u[i]]],i==m?'\n':' ');
		del(1);
		pp=0;
	}
	return 0;
}