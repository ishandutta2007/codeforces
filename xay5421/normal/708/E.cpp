#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=1505,M=100005,P=1e9+7;
int n,m,p,K,w[N],sw[N],f[N][N],s[N][N];
int fac[M],ifac[M],inv[M];
int fpow(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=1LL*k1*k1%P)if(k2&1)k3=1LL*k3*k1%P;
	return k3;
}
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*ifac[k2]%P*ifac[k1-k2]%P;
}
int main(){
	fac[0]=fac[1]=ifac[0]=ifac[1]=inv[0]=inv[1]=1;
	rep(i,2,M-1)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	scanf("%d%d",&n,&m);
	int a,b;scanf("%d%d",&a,&b);
	p=1LL*a*fpow(b,P-2)%P;
	scanf("%d",&K);
	rep(i,0,min(m,K)){
		w[i]=1LL*C(K,i)*fpow(p,i)%P*fpow(P+1-p,K-i)%P;
		sw[i]=((i?sw[i-1]:0)+w[i])%P;
	}
	rep(i,K+1,m)sw[i]=sw[i-1];
	f[0][m]=s[0][m]=1;
	rep(i,1,n){
		int sum=0;
		rep(j,1,m){
			(sum+=1LL*s[i-1][j-1]*w[j-1]%P)%=P;
			f[i][j]=1LL*w[m-j]*(1LL*(s[i-1][m]+P-s[i-1][m-j])*sw[j-1]%P+P-sum)%P;
			s[i][j]=(s[i][j-1]+f[i][j])%P;
		}
	}
	printf("%d\n",s[n][m]);
	return 0;
}