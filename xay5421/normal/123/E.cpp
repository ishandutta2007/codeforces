// author: xay5421
// created: Sat May  8 23:14:15 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005;
int n,p[N],q[N],sum[N],sz[N],sp,sq;
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void dfs(int k1,int k2){
	sum[k1]=p[k1],sz[k1]=1;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2)dfs(to[i],k1),sz[k1]+=sz[to[i]],sum[k1]+=sum[to[i]];
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
	}
	rep(i,1,n)scanf("%d%d",&p[i],&q[i]),sp+=p[i],sq+=q[i];
	dfs(1,0);
	double ans=0;
	rep(k1,1,n){
		for(int i=lnk[k1];i;i=nxt[i]){
			if(sz[k1]<sz[to[i]]){
				ans+=(n-sz[k1])*1.*q[k1]/sq*(1-1.*sum[k1]/sp);
			}else{
				ans+=sz[to[i]]*1.*q[k1]/sq*1.*sum[to[i]]/sp;
			}
		}
	}
	printf("%.20f\n",ans);
	return 0;
}