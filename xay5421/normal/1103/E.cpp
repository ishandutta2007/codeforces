// author: xay5421
// created: Mon Dec 21 15:05:10 2020
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef unsigned long long ULL;
const int N=100005;
int n;
struct cp{
	ULL x[5]; // *this=x+yw
	void clear(){memset(x,0,sizeof(x));}
	cp operator+(const cp&k)const{
		cp t;
		rep(i,0,4)t.x[i]=x[i]+k.x[i];
		return t;
	}
	cp operator-(const cp&k)const{
		cp t;
		rep(i,0,4)t.x[i]=x[i]-k.x[i];
		return t;
	}
	cp operator*(const cp&k)const{
		static ULL tmp[10];
		memset(tmp,0,sizeof(tmp));
		rep(i,0,4)rep(j,0,4)tmp[i+j]+=x[i]*k.x[j];
		cp t;
		rep(i,0,4)t.x[i]=tmp[i]-tmp[i+5];
		return t;
	}
}w[10],a[N];
const static int lim=100000;
void fwt(cp*a,int o){
	for(int i=1;i<lim;i*=10){
		for(int j=0;j<lim;j+=i*10){
			for(int k=0;k<i;++k){
				static cp b[10];
				int top=0;
				rep(t,0,9){
					b[top++]=a[i*t+j+k];
				}
				rep(t,0,9){
					cp&c=a[i*t+j+k];
					c.clear();
					rep(q,0,9){
						c=c+b[q]*w[t*q*o%10];
					}
				}
			}
		}
	}
}
cp po(cp k1,int k2){
	cp k3; k3.clear();
	k3.x[0]=1;
	for(;k2;k2>>=1,k1=k1*k1)if(k2&1)k3=k3*k1;
	return k3;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	w[0].x[0]=1;
	{
		cp wn; wn.clear();
		wn.x[1]=1;
		rep(i,1,9)w[i]=w[i-1]*wn;
	}
	scanf("%d",&n);
	rep(i,1,n){
		int x;
		scanf("%d",&x);
		++a[x].x[0];
	}
	fwt(a,1);
	rep(i,0,lim-1)a[i]=po(a[i],n);
	fwt(a,9);
	const ULL I=6723469279985657373ULL;
	rep(i,0,n-1){
		ULL res=a[i].x[0]-a[i].x[2];
		printf("%llu\n",(res*I)>>5&((1ULL<<58)-1));
	}
	return 0;
}