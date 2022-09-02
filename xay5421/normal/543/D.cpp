#include<bits/stdc++.h>
using namespace std;
const int N=200005,P=1e9+7;
int n,fa[N],f[N],f2[N],ans[N]; 
int fpow(int k1,int k2){int k3=1;for(;k2;k2>>=1,k1=1ll*k1*k1%P)if(k2&1)k3=1ll*k3*k1%P;return k3;}
struct ed{int nxt,to;}G[N];int lnk[N],pp;
void ae(int k1,int k2){G[++pp]=(ed){lnk[k1],k2},lnk[k1]=pp;}
void dfs(int k1){
	f[k1]=1;
	for(int i=lnk[k1];i;i=G[i].nxt){
		int j=G[i].to;
		dfs(j),f[k1]=1ll*f[k1]*(f[j]+1)%P;
	}
}
void dfs2(int k1){
	ans[k1]=1ll*f[k1]*(f2[k1]+1)%P;
	vector<int>pre,suf;
	pre.push_back(1);
	for(int i=lnk[k1];i;i=G[i].nxt){
		int j=G[i].to;
		pre.push_back(f[j]+1);
		suf.push_back(f[j]+1);
	}
	suf.push_back(1);
	for(int i=1;i<(int)pre.size();++i)pre[i]=1ll*pre[i-1]*pre[i]%P;
	for(int i=(int)suf.size()-2;i>=0;--i)suf[i]=1ll*suf[i+1]*suf[i]%P;
	for(int i=lnk[k1],k=0;i;i=G[i].nxt,++k){
		int j=G[i].to;
		f2[j]=1ll*(f2[k1]+1)*pre[k]%P*suf[k+1]%P;
		dfs2(j);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;++i)scanf("%d",&fa[i]),ae(fa[i],i);
	dfs(1);
	dfs2(1);
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}