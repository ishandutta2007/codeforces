#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=2005;
int T;
int pop10(LL x){
	int res=0;
	while(x){
		++res;
		x/=10;
	}
	return res;
}
LL mul(LL k1,LL k2,LL md){
	LL k3=0;
	for(;k2;k2>>=1,k1=(k1+k1)%md)if(k2&1)k3=(k3+k1)%md;
	return k3;
}
LL fpow(LL k1,LL k2,LL md){
	LL k3=1;
	for(;k2;k2>>=1,k1=mul(k1,k1,md))if(k2&1)k3=mul(k3,k1,md);
	return k3;
}
LL lg2(LL x,int k){ // log2(x) (mod 5^k)
	LL t=vector<LL>{-1,0,1,3,2}[x%5];
	LL md=5;
	for(int i=1;i<k;++i){
		while(fpow(2,t,md*5)!=x%(md*5))t+=md/5*4;
		md*=5;
	}
	return t;
}
int main(){
	scanf("%d",&T);
	while(T--){
		LL a;
		scanf("%lld",&a);
		int n=pop10(a);
		for(int m=0;;++m,a*=10){
			LL b=(-a)&((1LL<<(n+m))-1);
			if((a+b)%5==0)b+=1LL<<(n+m);
			if(pop10(b)<=m){
				LL x=a+b;
				LL y=x>>(n+m);
				printf("%lld\n",lg2(y,n+m)+n+m);
				break;
			}
		}
	}
	return 0;
}