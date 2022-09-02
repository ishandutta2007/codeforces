// author: xay5421
// created: Mon Mar  1 12:55:06 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005,B=350;
int n,Q,a[N],bel[N],bl[N/B+5],br[N/B+5],go[N],tg[N/B+5];
int baba(int x){
	return max(1,a[x]-tg[bel[x]]);
}
int jump(int x){
	if(tg[bel[x]]<B)return go[x];
	return baba(x);
}
void rebud(int bb){
	int l=bl[bb],r=br[bb];
	rep(i,l,r){
		int x=baba(i);
		if(x<l)go[i]=x;
		else go[i]=go[x];
	}
}
void do1(int l,int r,int x){
	if(bel[l]==bel[r]){
		rep(i,l,r)a[i]=max(1,a[i]-x);
		rebud(bel[l]);
		return;
	}
	rep(i,l,br[bel[l]])a[i]=max(1,a[i]-x);
	rebud(bel[l]);
	rep(i,bel[l]+1,bel[r]-1){
		if(tg[i]<B){
			tg[i]+=x;
			rebud(i);
		}else tg[i]=min(tg[i]+x,N);
	}
	rep(i,bl[bel[r]],r)a[i]=max(1,a[i]-x);
	rebud(bel[r]);
}
int do2(int u,int v){
	D("do2 %d %d\n",u,v);
	int k1=u,k2=v;
	if(u==v)return u;
	while(u!=v){
		if(u>v)swap(u,v),swap(k1,k2);
		k2=v,v=jump(v);
	}
	while(k1!=k2){
		if(k1>k2)swap(k1,k2);
		k2=baba(k2);
	}
	return k1;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&Q);
	rep(i,2,n){
		bel[i]=(i-2)/B+1;
		if(!bl[bel[i]])bl[bel[i]]=i;
		br[bel[i]]=i;
	}
	rep(i,2,n)scanf("%d",&a[i]);
	rep(i,1,bel[n])rebud(i);
	rep(_,1,Q){
		int o;
		scanf("%d",&o);
		if(o==1){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			do1(l,r,x);
		}else{
			int u,v;
			scanf("%d%d",&u,&v);
			printf("%d\n",do2(u,v));
		}
	}
	return 0;
}