#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=35005,INF=0X3F3F3F3F;
int n,K,a[N],lst[N],ll[N],f[N],old_f[N];
int mx[N*4],tg[N*4];
void upd(int k1){
	mx[k1]=max(mx[k1*2],mx[k1*2+1]);
}
void pst(int k1,int k2){
	tg[k1]+=k2,mx[k1]+=k2;
}
void psd(int k1){
	if(tg[k1]){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1]);
		tg[k1]=0;
	}
}
void bud(int k1,int k2,int k3){
	tg[k1]=0,mx[k1]=0;
	if(k2==k3){
		mx[k1]=old_f[k2-1];
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		pst(k1,k6);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	add(k1*2,k2,mid,k4,k5,k6),add(k1*2+1,mid+1,k3,k4,k5,k6);
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
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&K);
	if(K>=n){
		printf("%d\n",n);
		return 0;
	}
	rep(i,1,n){
		scanf("%d",&a[i]);
		old_f[i]=old_f[i-1]+(lst[a[i]]==0);
		ll[i]=lst[a[i]]+1;
		lst[a[i]]=i;
	}
	rep(_,2,K){
		bud(1,1,n);
		fill(f,f+n+1,~INF);
		rep(i,_,n){
			add(1,1,n,ll[i],i,1);
			res=~INF;
			ask(1,1,n,1,i);
			f[i]=res;
		}
		copy(f,f+n+1,old_f);
	}
	printf("%d\n",old_f[n]);
	return 0;
}