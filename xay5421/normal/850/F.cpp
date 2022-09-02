// author: xay5421
// created: Fri Dec 11 08:28:27 2020
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=2505,MAXA=100005,P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
int mu(int k1,int k2,int k3){return 1LL*k1*k2%P*k3%P;}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
int n,m,a[N],f[MAXA],inv[MAXA];
int calc(int x){
	int k1=0,k2=0;
	rep(j,1,x-1){
		k1=ad(k1,inv[j]);
		k2=ad(k2,mu(inv[j],j));
	}
	return su(mu(k1,su(1,m),x),mu(k2,su(1,m)));
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	inv[0]=inv[1]=1;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),m+=a[i];
	rep(i,0,MAXA-1){
		inv[i]=po(m-i,P-2);
	}
	int cur=0;
	rep(i,1,n){
		cur=ad(cur,calc(a[i]));
	}
	int endval=mu(su(1,m),m-1);
	printf("%d\n",su(cur,endval));
	return 0;
}