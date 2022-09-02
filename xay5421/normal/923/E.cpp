#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef vector<int>VI;
typedef long long LL;
const int P=998244353;
int fpow(int k1,LL k2){
	k2%=P-1;
	if(k2<0)k2+=P-1;
	int k3=1;
	for(;k2;k2>>=1,k1=1LL*k1*k1%P)if(k2&1)k3=1LL*k3*k1%P;
	return k3;
}
int getlim(int n){int x=1;while(x<=n)x<<=1;return x;}
void ntt(VI&a,int g,int lim){
	a.resize(lim);
	for(int i=0,j=0;i<lim;++i){
		if(i<j)swap(a[i],a[j]);
		for(int k=lim>>1;(j^=k)<k;k>>=1);
	}
	VI w(lim>>1);w[0]=1;
	for(int i=1;i<lim;i<<=1){
		for(int j=1,wn=fpow(g,(P-1)/(i<<1));j<i;++j)w[j]=1ll*w[j-1]*wn%P;
		for(int j=0;j<lim;j+=i<<1)
			for(int k=0;k<i;++k){
				int x=a[j+k],y=1ll*a[i+j+k]*w[k]%P;
				a[j+k]=(x+y)%P,a[i+j+k]=(x-y+P)%P;
			}
	}
	if(g==332748118)for(int i=0,I=fpow(lim,P-2);i<(int)a.size();++i)a[i]=1ll*a[i]*I%P;
}
VI pmul(VI a,VI b){
	int need=(int)a.size()+b.size()-1,lim=getlim(need);
	ntt(a,3,lim),ntt(b,3,lim);
	for(int i=0;i<lim;++i)a[i]=1ll*a[i]*b[i]%P;
	ntt(a,332748118,lim);
	return a.resize(need),a;
}
const int N=100005;
int n,p[N],fac[N],ifac[N],inv[N];LL m;
int main(){
	fac[0]=fac[1]=ifac[0]=ifac[1]=inv[0]=inv[1]=1;
	rep(i,2,N-1)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	cin>>n>>m;
	++n;
	vector<int>f;
	rep(i,1,n)cin>>p[i];
	{
		vector<int>g(n+1),h(ifac,ifac+n+1);
		rep(i,1,n)g[i]=1LL*p[i]*fac[i-1]%P;
		reverse(g.begin()+1,g.end());
		f=pmul(g,h);
		f.resize(n+1);
		reverse(f.begin()+1,f.end());
	}
	vector<int>h;
	{
		vector<int>g(n+1);
		rep(i,0,n)g[i]=(i&1?P-1LL:1LL)*ifac[i]%P;
		rep(i,1,n)f[i]=1LL*f[i]*fpow(i,-m)%P;
		reverse(f.begin()+1,f.end());
		h=pmul(f,g);
		h.resize(n+1);
		reverse(h.begin()+1,h.end());
	}
	rep(j,1,n){
		h[j]=1LL*h[j]*ifac[j-1]%P;
		printf("%d ",h[j]);
	}
	return 0;
}