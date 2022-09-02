#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=200005,INF=0X3F3F3F3F;
int n,w[N],sz[N],f[N],all,rt;
bool ban[N];
int nd=-1;double ans=1e100;
int pp,lnk[N],nxt[N*2],to[N*2],we[N*2];
void ae(int k1,int k2,int k3){
	to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;
}
void getrt(int k1,int k2){
	sz[k1]=1,f[k1]=0;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2&&!ban[to[i]]){
		getrt(to[i],k1);
		sz[k1]+=sz[to[i]];
		if(sz[to[i]]>f[k1])f[k1]=sz[to[i]];
	}
	if(all-sz[k1]>f[k1])f[k1]=all-sz[k1];
	if(f[k1]<f[rt])rt=k1;
}
double work(int k1,int k2,LL k3){
	double cur=w[k1]*pow(k3,1.5);
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2)cur+=work(to[i],k1,k3+we[i]);
	return cur;
}
double getdao(int k1,int k2,LL k3){
	double cur=w[k1]*sqrt(k3);
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2)cur+=getdao(to[i],k1,k3+we[i]);
	return cur;
}
void sol(int k1){
	ban[k1]=1;
	double now=work(k1,0,0);
	if(now<ans){
		ans=now,nd=k1;
	}
	int k2=0;
	double mx=-1e100;
	for(int i=lnk[k1];i;i=nxt[i])if(!ban[to[i]]){
		double cur=getdao(to[i],k1,we[i]);
		if(cur>mx)mx=cur,k2=to[i];
	}
	if(k2){
		if(sz[k2]>sz[k1]){
			all=all-sz[k1];
		}else{
			all=sz[k2];
		}
		getrt(k2,0);
		sol(rt);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&w[i]);
	rep(i,2,n){
		int k1,k2,k3;scanf("%d%d%d",&k1,&k2,&k3);
		ae(k1,k2,k3),ae(k2,k1,k3);
	}
	f[rt=0]=INF;
	all=n;
	getrt(1,0);
	sol(rt);
	printf("%d %.20f\n",nd,ans);
	return 0;
}