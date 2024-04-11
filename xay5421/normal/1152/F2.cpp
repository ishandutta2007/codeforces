#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int P=1e9+7;
const LL PP=1LL*P*P;
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
const int N=215;
int n,K,m,sz;
struct mat{
	int a[N][N];
	mat operator*(const mat&b)const{
		mat c;
		rep(i,0,sz-1){
			rep(j,0,sz-1){
				LL t=0;
				rep(k,0,sz-1){
					t+=1LL*a[i][k]*b.a[k][j];
					if(t>=PP)t-=PP;
				}
				c.a[i][j]=t%P;
			}
		}
		return c;
	}
}A,B;
int zip(int x,int y){
	return (x<<m)+y;
}
int norm(int x){
	return x&((1<<m)-1);
}
mat power(mat k1,int k2){
	mat k3;
	rep(i,0,sz-1)rep(j,0,sz-1){
		k3.a[i][j]=i==j;
	}
	while(k2){
		if(k2&1)k3=k3*k1;
		k2>>=1;
		k1=k1*k1;
	}
	return k3;
}
int main(){
	scanf("%d%d%d",&n,&K,&m);
	sz=(K+1)<<m;
	rep(i,0,K){
		rep(j,0,(1<<m)-1){
			if(i<K){
				A.a[zip(i,j)][zip(i+1,norm(j<<1|1))]+=__builtin_popcount(j)+1;
			}
			A.a[zip(i,j)][zip(i,norm(j<<1))]+=1;
		}
	}
	B=power(A,n);
	int ans=0;
	rep(i,0,(1<<m)-1){
		uad(ans,B.a[zip(0,0)][zip(K,i)]);
	}
	printf("%d\n",ans);
	return 0;
}