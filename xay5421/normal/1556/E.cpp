// author: xay5421
// created: Mon Aug 30 00:38:44 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=100005;
int n,Q,a[N],b[N];
LL mx[N*4],mn[N*4],sum[N*4];
void upd(int k1){
	mx[k1]=max(mx[k1*2],sum[k1*2]+mx[k1*2+1]);
	mn[k1]=min(mn[k1*2],sum[k1*2]+mn[k1*2+1]);
	sum[k1]=sum[k1*2]+sum[k1*2+1];
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		mn[k1]=mx[k1]=sum[k1]=b[k2]-a[k2];
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
LL w1,w2,w3;
void ask(int k1,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		w1=max(mx[k1],sum[k1]+w1);
		w2=min(mn[k1],sum[k1]+w2);
		w3+=sum[k1];
		return;
	}
	int mid=(k2+k3)>>1;
	ask(k1*2+1,mid+1,k3,k4,k5);
	ask(k1*2,k2,mid,k4,k5);
	upd(k1);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&Q);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	bud(1,1,n);
	rep(i,1,Q){
		int l,r;
		scanf("%d%d",&l,&r);
		w1=-0X3F3F3F3F3F3F3F3FLL,w2=0X3F3F3F3F3F3F3F3FLL,w3=0;
		ask(1,1,n,l,r);
		if(w3!=0)puts("-1");
		else if(w2<0)puts("-1");
		else printf("%lld\n",w1);
	}
	return 0;
}