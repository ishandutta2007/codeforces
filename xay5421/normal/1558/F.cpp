// author: xay5421
// created: Thu Aug 26 19:26:42 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005,INF=0X3F3F3F3F;
int T,n,a[N],ia[N];
bool in[N];
int mx[N*4],tg[N*4];
void upd(int k1){
	mx[k1]=max(mx[k1*2],mx[k1*2+1]);
}
void bud(int k1,int k2,int k3){
	tg[k1]=0;
	if(k2==k3){
		mx[k1]=k2&1?(k2-1)*2-k2:(k2-1)*2-(k2-1);
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid);
	bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void pst(int k1,int k2){
	mx[k1]+=k2;
	tg[k1]+=k2;
}
void psd(int k1){
	if(tg[k1]){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1]);
		tg[k1]=0;
	}
}
void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		pst(k1,k6);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
int res;
void ask(int k1,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		res=max(res,mx[k1]);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	ask(k1*2,k2,mid,k4,k5),ask(k1*2+1,mid+1,k3,k4,k5);
}
int ask(int l,int r){
	res=-INF;
	ask(1,1,n,l,r);
	return res;
}
void out(int k1,int k2,int k3){
	if(k2==k3){D("%d ",mx[k1]);return;}
	psd(k1);
	int mid=(k2+k3)>>1;
	out(k1*2,k2,mid),out(k1*2+1,mid+1,k3);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n)scanf("%d",&a[i]),ia[a[i]]=i;
		rep(i,1,n)in[i]=1;
		bud(1,1,n);
		int ans=0,be=1,en=0;
		rep(_,1,n-1){
			in[ia[_]]=0,mdf(1,1,n,ia[_],ia[_],-INF);
			en=max(en,ia[_]);
			if(ia[_]<n)mdf(1,1,n,ia[_]+1,n,-2);
			while(!in[be])++be;
			if(be>en)continue;
			/*D("_=%d\n",_);
			out(1,1,n);
			D("\n");*/
			ans=max(ans,_+1+ask(be,en));
		}
		printf("%d\n",ans);
	}
	return 0;
}