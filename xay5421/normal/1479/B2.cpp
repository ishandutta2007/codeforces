// author: xay5421
// created: Sun Feb  7 22:57:55 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005;
int n,ans,a[N],t[N*4],tg[N*4];
void pst(int k1,int k2){
	t[k1]+=k2;
	tg[k1]+=k2;
}
void psd(int k1){
	if(tg[k1]){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1]);
		tg[k1]=0;
	}
}
void upd(int k1){
	t[k1]=min(t[k1*2],t[k1*2+1]);
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
int qry(int k1,int k2,int k3,int k4){
	if(k2==k3)return t[k1];
	psd(k1);
	int mid=(k2+k3)>>1;
	if(k4<=mid)return qry(k1*2,k2,mid,k4);else return qry(k1*2+1,mid+1,k3,k4);
}
int res;
void ask(int k1,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		res=min(res,t[k1]);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	ask(k1*2,k2,mid,k4,k5),ask(k1*2+1,mid+1,k3,k4,k5);
}
int ask(int l,int r){
	res=1e9;
	if(l<=r)ask(1,0,n,l,r);
	return res;
}
void mdf(int k1,int k2,int k3,int k4,int k5){
	if(k2==k3){
		t[k1]=min(t[k1],k5);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	if(k4<=mid)mdf(k1*2,k2,mid,k4,k5);else mdf(k1*2+1,mid+1,k3,k4,k5);
	upd(k1);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	memset(t,63,sizeof(t));
	mdf(1,0,n,0,0);
	rep(i,1,n){
		int x=qry(1,0,n,a[i]),y=ask(0,a[i]-1),z=ask(a[i]+1,n);
		if(a[i]!=a[i-1]){
			add(1,0,n,0,n,1);
		}
		mdf(1,0,n,a[i-1],min(min(y,z)+1,x));
	}
	printf("%d\n",t[1]);
	return 0;
}