// author: xay5421
// created: Sun Apr 25 16:23:12 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=100005;
int n,m,Q,a[N],b[N],pre[N],suf[N];
struct BIT{
	int t[N];
	void clear(){
		memset(t,0,sizeof(t));
	}
	void upd(int k1,int k2){
		for(int i=k1;i<=m;i+=i&-i)t[i]+=k2;
	}
	int qry(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
}t;
const int M=N*20;
int ind,rt[N],lc[M],rc[M],B[M],C[M],D[M],BC[M],CD[M],BCD[M];
void upd(int k1){
	C[k1]=ad(C[lc[k1]],C[rc[k1]]);
	B[k1]=ad(B[lc[k1]],B[rc[k1]]);
	D[k1]=ad(D[lc[k1]],D[rc[k1]]);
	BC[k1]=ad(BC[lc[k1]],BC[rc[k1]],mu(B[lc[k1]],C[rc[k1]]));
	CD[k1]=ad(CD[lc[k1]],CD[rc[k1]],mu(C[lc[k1]],D[rc[k1]]));
	BCD[k1]=ad(BCD[lc[k1]],BCD[rc[k1]],mu(BC[lc[k1]],D[rc[k1]]),mu(B[lc[k1]],CD[rc[k1]]));
}
void mdf(int&k1,int k2,int k3,int k4,int k5,int k6,int k7){
	if(!k1)k1=++ind;
	if(k2==k3){
		B[k1]=k5;
		D[k1]=k6;
		C[k1]=k7;
		return;
	}
	int mid=(k2+k3)>>1;
	if(k4<=mid)mdf(lc[k1],k2,mid,k4,k5,k6,k7);else mdf(rc[k1],mid+1,k3,k4,k5,k6,k7);
	upd(k1);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	rep(i,1,n)a[i]=lower_bound(b+1,b+1+m,a[i])-b;
	t.clear();
	rep(i,1,n)pre[i]=t.qry(a[i]),t.upd(a[i],1);
	t.clear();
	per(i,n,1)suf[i]=t.qry(a[i]),t.upd(a[i],1);
	rep(i,1,n){
		mdf(rt[a[i]],1,n,i,pre[i],suf[i],1);
	}
	int ans=0;
	rep(i,1,m)uad(ans,BCD[rt[i]]);
	scanf("%d",&Q);
	rep(i,1,Q){
		int p,x;
		scanf("%d%d",&x,&p);
		usu(ans,BCD[rt[a[p]]]);
		if(x==2){
			mdf(rt[a[p]],1,n,p,pre[p],suf[p],1);
		}else{
			mdf(rt[a[p]],1,n,p,0,0,0);
		}
		uad(ans,BCD[rt[a[p]]]);
		printf("%d\n",ans);
	}
	return 0;
}