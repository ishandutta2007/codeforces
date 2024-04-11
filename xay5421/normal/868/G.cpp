// author: xay5421
// created: Thu Nov  4 20:12:46 2021
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
struct line{
	int k,b; // this(x)=kx+b
	line operator()(const line&u)const{ // this(u(x))
		return(line){mu(k,u.k),ad(mu(k,u.b),b)};
	}
	line operator()(int t)const{ // this(this(this(...))) for t times
		line res=(line){1,0};
		line u=*this;
		while(t){
			if(t&1)res=res(u);
			t>>=1;
			if(t)u=u(u);
		}
		return res;
	}
	int operator[](int u)const{return ad(mu(k,u),b);}
	line operator+(const line&u)const{return(line){ad(k,u.k),ad(b,u.b)};}
	line inv(){ //  f(g(x))=x
		assert(k!=0);
		const int I=po(k,P-2);
		return(line){I,mu(su(0,b),I)};
	}
};
line get_sum(line A,int t){ // \sum_{i=1}^t A^i
	if(A.k==1){
		return (line){t,mu(A.b,t,t+1,(P+1)>>1)};
	}
	return (line){su(mu(su(1,po(A.k,t+1)),po(su(1,A.k),P-2)),1),mu(A.b,ad(po(A.k,t+1),mu(P-A.k,t+1),t),po(mu(su(A.k,1),su(A.k,1)),P-2))};
}
int sol(int n,int K,line A,line B,line S1,line S2){ // \sum_{i=0}^{k-1}S1(E(i))+\sum_{i=k}^{n-1}S2(E(i)) E(i+K)=A(E(i)) E(i+K-n)=B(E(i))
	if(!K){
		// E(i)=A(E(i))
		// A.b/(1-A.k)
		return mu(n/*n=1*/,S2[mu(A.b,po(su(1,A.k),P-2))]);
	}
	line s2=S1+S2(get_sum(A,n/K-1));
	line s1=s2+S2(A(n/K));
	line ia=A.inv(),ib=B.inv();
	line a=(ia(n/K-1))(ib);
	line b=(ia(n/K))(ib);
	int sum=ad(mu(n%K,s1.b),mu(K-n%K,s2.b)); // ??
	s1.b=0,s2.b=0;
	return ad(sum,sol(K,n%K,a,b,s1,s2));
}
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		int n,K;
		scanf("%d%d",&n,&K);
		int g=__gcd(n,K);
		n/=g,K/=g;
		printf("%d\n",mu(sol(n,K,(line){1,1},(line){(P+1)>>1,1},(line){1,0},(line){1,0}),po(n,P-2)));
	}
	return 0;
}