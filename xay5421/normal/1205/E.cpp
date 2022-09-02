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
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=200005;
int n,K,pw[N],phi[N],sphi[N],p[N];
bool ban[N];
void sieve(){
	ban[0]=ban[1]=1,phi[1]=1;
	for(int i=2;i<N;++i){
		if(!ban[i]){
			p[++*p]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}else{
				phi[i*p[j]]=phi[i]*(p[j]-1);
			}
		}
	}
	for(int i=1;i<N;++i)sphi[i]=ad(sphi[i-1],phi[i]);
}
int main(){
	sieve();
	scanf("%d%d",&n,&K);
	pw[0]=1;
	rep(i,1,N-1)pw[i]=mu(pw[i-1],K);
	int w1=0;
	for(int i=1;i<=(n-1)*2;++i){
		int l=max(1,i-(n-1));
		int r=min(n-1,i-1);
		if(l<=r){
			uad(w1,mu(pw[i],r-l+1));
		}
	}
	w1=mu(w1,po(pw[n],P-2));
	int w2=0;
	rep(d,1,n-1){
		if(2<=(n-1)/d+1){
			uad(w2,mu(pw[d],su(sphi[(n-1)/d+1],sphi[1])));
		}
	}
	int w3=0;
	rep(d,1,n-1){
		rep(sum,2,(n-1)/d+1){
			uad(w3,mu(phi[sum],pw[sum*d]));
		}
	}
	w3=mu(w3,po(pw[n],P-2));
	int res=su(ad(w1,w2),w3);
	res=mu(res,po(pw[n],P-2));
	printf("%d\n",res);
	return 0;
}