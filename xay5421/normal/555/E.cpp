#include<bits/stdc++.h>
#define PB push_back
#define D(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef vector<int>VI;
const int N=200005,K=20;
int n,m,q,ind,cnt,num,low[N],dfn[N],st[N],top,bel[N],dep[N],val[N],f[N][K],s1[N],s2[N];bool ins[N];
int pp=1,lnk[N],nxt[N*2],to[N*2];
VI G[N];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void tarjan(int k1,int k2){
	low[k1]=dfn[k1]=++ind,ins[st[++top]=k1]=1;
	for(int i=lnk[k1];i;i=nxt[i])if(i/2!=k2){
		if(!dfn[to[i]])tarjan(to[i],i/2),low[k1]=min(low[k1],low[to[i]]);
		else if(ins[to[i]])low[k1]=min(low[k1],dfn[to[i]]);
	}
	if(low[k1]==dfn[k1]){
		++cnt;
		do ins[st[top]]=0,bel[st[top]]=cnt;while(st[top--]!=k1);
	}
}
void dfs(int k1,int k2,int k3){
	dep[k1]=dep[k2]+1,f[k1][0]=k2,val[k1]=k3;
	rep(i,1,K-1)f[k1][i]=f[f[k1][i-1]][i-1];
	for(auto j:G[k1])if(j!=k2)dfs(j,k1,k3);
}
int LCA(int k1,int k2){
	if(dep[k1]<dep[k2])swap(k1,k2);int ret=dep[k1]-dep[k2];
	per(i,K-1,0)if(ret>>i&1)k1=f[k1][i];if(k1==k2)return k1;
	per(i,K-1,0)if(f[k1][i]!=f[k2][i])k1=f[k1][i],k2=f[k2][i];return f[k1][0];
}
void chk(int k1,int k2){
	for(auto j:G[k1])if(j!=k2)chk(j,k1),s1[k1]+=s1[j],s2[k1]+=s2[j];
	if(s1[k1]&&s2[k1])puts("No"),exit(0);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,m){
		int k1,k2;scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
	}
	rep(i,1,n)if(!dfn[i])tarjan(i,0);
//	rep(i,1,n)D("bel[%d]=%d\n",i,bel[i]);
	for(int i=2;i<=pp;++i)if(bel[to[i]]!=bel[to[i^1]])G[bel[to[i]]].PB(bel[to[i^1]]);
	rep(i,1,cnt)if(!dep[i])dfs(i,0,++num);
//	rep(i,1,cnt)D("%d%c",dep[i],i==cnt?'\n':' ');
	while(q--){
		int k1,k2;scanf("%d%d",&k1,&k2);
		k1=bel[k1],k2=bel[k2];
		if(k1==k2)continue;
		if(val[k1]!=val[k2])puts("No"),exit(0);
		int k3=LCA(k1,k2);
		++s1[k3],--s1[k1],++s2[k3],--s2[k2];
	}
	rep(i,1,cnt)if(!f[i][0])chk(i,0);
	puts("Yes");
	return 0;
}