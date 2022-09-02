// author: xay5421
// created: Tue Aug 24 22:43:26 2021
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
int P;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=4000005;
int n,f[N],sum[N],p[N/10],minp[N];
bool ban[N];
void sieve(){
	ban[0]=ban[1];
	for(int i=2;i<N;++i){
		if(!ban[i])p[++*p]=i,minp[i]=i;
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			minp[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
}
int st[100][2],top;
void del(int&t,int n,int x){
	usu(t,f[n/x]);
}
void ins(int&t,int n,int x){
	uad(t,f[n/x]);
}
void dfs(int k1,int&t,int n,int x){
	if(k1>top){
		if(x>1){
			del(t,n-1,x);
			ins(t,n,x);
		}
		return;
	}
	for(int i=0;i<=st[k1][1];++i){
		if(i)x=x*st[k1][0];
		dfs(k1+1,t,n,x);
	}
}
void work(int&t,int n){
	top=0;
	int n_=n;
	while(n_>1){
		int x=minp[n_],cnt=0;
		while(n_%x==0)n_/=x,++cnt;
		st[++top][0]=x,st[top][1]=cnt;
	}
	dfs(1,t,n,1);
}
int main(){
	sieve();
	scanf("%d%d",&n,&P);
	f[1]=1;
	sum[1]=1;
	int tmp=0;
	rep(i,2,n){
		/*for(int l=2,r;l<=i;l=r+1){
			r=i/(i/l);
			uad(f[i],mu(f[i/l],r-l+1));
		}*/
		work(tmp,i);
		ins(tmp,i,1);
		f[i]=ad(sum[i-1],tmp);
		sum[i]=ad(sum[i-1],f[i]);
	}
	printf("%d\n",f[n]);
	return 0;
}