// author: xay5421
// created: Mon Dec 21 21:43:28 2020
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=998244353;
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
int n,m,d[N],q[N],he,ta,vis[N],sg[N],a[N];
int pp,lnk[N],nxt[N],to[N];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		ae(k1,k2),++d[k2];
	}
	rep(i,1,n)if(!d[i])q[++ta]=i;
	while(he!=ta){
		int k1=q[++he];
		for(int i=lnk[k1];i;i=nxt[i])if(!--d[to[i]])q[++ta]=to[i];
	}
	per(_,n,1){
		int k1=q[_];
		for(int i=lnk[k1];i;i=nxt[i]){
			vis[sg[to[i]]]=1;
		}
		sg[k1]=0;
		while(vis[sg[k1]])++sg[k1];
		for(int i=lnk[k1];i;i=nxt[i]){
			vis[sg[to[i]]]=0;
		}
	}
	const int lim=1024;
	rep(i,1,n)uad(a[sg[i]],po(n,P-2));
	for(int i=1;i<lim;i<<=1)for(int j=0;j<lim;j+=i<<1)for(int k=0;k<i;++k){
		int x=a[j+k],y=a[i+j+k];
		a[j+k]=ad(x,y),a[i+j+k]=su(x,y);
	}
	int ans=0;
	const int t=mu(n,po(n+1,P-2));
	rep(i,0,lim-1){
		int x=mu(t,a[i]);
		uad(ans,po(su(1,x),P-2));
	}
	ans=mu(ans,po(lim,P-2),po(n+1,P-2));
	printf("%d\n",su(1,ans));
	return 0;
}