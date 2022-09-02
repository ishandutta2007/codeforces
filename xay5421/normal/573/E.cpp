#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=1e5+5;
int n,rt,val[N],tg[N],sz[N],rnd[N],lc[N],rc[N];
void pst(int k1,int k2){
	val[k1]+=k2,tg[k1]+=k2;
}
void psd(int k1){
	if(tg[k1]){
		pst(lc[k1],tg[k1]);
		pst(rc[k1],tg[k1]);
		tg[k1]=0;
	}
}
void upd(int k1){sz[k1]=sz[lc[k1]]+sz[rc[k1]]+1;}
void split(int k1,int x,int&l,int&r,int siz){
	if(k1==0){l=r=0;return;}
	psd(k1);
	if(val[k1]>=1LL*(siz+sz[lc[k1]])*x)l=k1,split(rc[k1],x,rc[k1],r,siz+sz[lc[k1]]+1);
	else r=k1,split(lc[k1],x,l,lc[k1],siz);
	upd(k1);
}
int mer(int k1,int k2){
	if(!k1||!k2)return k1+k2;
	psd(k1),psd(k2);
	if(rnd[k1]<rnd[k2]){
		rc[k1]=mer(rc[k1],k2);
		upd(k1);
		return k1;
	}else{
		lc[k2]=mer(k1,lc[k2]);
		upd(k2);
		return k2;
	}
}
int ran(){return((rand()&0X7FFF)<<16)+((rand()&0X7FFF)<<1)+(rand()&1);}
int cur,ans;
void dfs(int k1){
	if(!k1)return;
	psd(k1);
	dfs(lc[k1]);
	cur+=val[k1];
	ans=max(cur,ans);
	dfs(rc[k1]);
}
signed main(){
	scanf("%lld",&n);
	rep(i,1,n){
		int x;scanf("%lld",&x);
		int l,r;
		split(rt,x,l,r,1);
		rnd[i]=ran();
		sz[i]=1;
		val[i]=(sz[l]+1)*x;
		pst(r,x);
		rt=mer(mer(l,i),r);
	}
	dfs(rt);
	printf("%lld\n",ans);
	return 0;
}