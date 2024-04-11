#include<bits/stdc++.h>
#define P 998244353
#define N 200005

inline int fmo(int x){
	return x+((x>>31)&P);
}
inline int fp(int x,int k=P-2){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}

int n,m,c[N],b[N];

int t[N];
inline int lb(int x){
	return x&-x;
}
inline void add(int x,int d){
	for(;x<=200000;x+=lb(x))
		t[x]+=d;
}
inline int sum(int x){
	int res=0;
	for(;x;x-=lb(x))
		res=fmo(res+t[x]-P);
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	int tmp=1;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		tmp=1ll*tmp*fp(++c[x])%P,add(x,1);
	}
	int fac=1;
	for(int i=1;i<=n;i++)
		fac=1ll*fac*i%P;
	int res=0;
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		if(i>n){
			res=fmo(res+1-P);
			break;
		}
		fac=1ll*fac*fp(n-i+1)%P;
		res=fmo(res+1ll*fac*tmp%P*sum(x-1)%P-P);
		if(!c[x])
			break;
		tmp=1ll*tmp*(c[x]--)%P,add(x,-1);
	}
	printf("%d\n",res);
}