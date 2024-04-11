#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=131080,P=998244353;
int add(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int sub(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mul(int k1,int k2){return 1LL*k1*k2%P;}
int fpow(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mul(k1,k1))if(k2&1)k3=mul(k3,k1);
	return k3;
}
const int I4=fpow(4,P-2),I2=(P+1)/2;
int n,K,x,y,z,sum,a[N],b[N],c[N],f[N],B[N],C[N],D[N];
void fwt(int*f,int o=1){
	for(int i=1;i<(1<<K);i<<=1)for(int j=0;j<(1<<K);j+=i<<1)for(int k=0;k<i;++k){
		int x=f[j+k],y=f[i+j+k];
		f[j+k]=add(x,y),f[i+j+k]=sub(x,y);
	}
	if(o==-1){
		int I=fpow(1<<K,P-2);
		rep(i,0,(1<<K)-1)f[i]=mul(f[i],I);
	}
}
int main(){
	scanf("%d%d%d%d%d",&n,&K,&x,&y,&z);
	rep(i,1,n)scanf("%d%d%d",&a[i],&b[i],&c[i]),b[i]^=a[i],c[i]^=a[i],sum^=a[i];
	memset(f,0,sizeof(f));
	rep(i,1,n)++f[b[i]];
	fwt(f);
	rep(i,0,(1<<K)-1)B[i]=f[i];
	
	memset(f,0,sizeof(f));
	rep(i,1,n)++f[c[i]];
	fwt(f);
	rep(i,0,(1<<K)-1)C[i]=f[i];
	
	memset(f,0,sizeof(f));
	rep(i,1,n)++f[b[i]^c[i]];
	fwt(f);
	rep(i,0,(1<<K)-1)D[i]=f[i];
	auto sol=[&](int i){
		int wa=n,wb=B[i],wc=C[i],wd=D[i];
		int c1=mul(add(add(add(wa,wb),wc),wd),I4);
		int c2=mul(sub(add(wa,wb),add(c1,c1)),I2);
		int c3=mul(sub(add(wa,wc),add(c1,c1)),I2);
		int c4=mul(sub(add(wa,wd),add(c1,c1)),I2);
		return mul(
			mul(
				fpow(add(add(x,y),z),c1),
				fpow(sub(add(x,y),z),c2)
			),
			mul(
				fpow(add(sub(x,y),z),c3),
				fpow(sub(sub(x,y),z),c4)
			)
		);
	};
	rep(i,0,(1<<K)-1)f[i]=sol(i);
	fwt(f,-1);
	rep(i,0,(1<<K)-1)printf("%d ",f[i^sum]);
	return 0;
}