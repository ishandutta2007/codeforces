#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
const int MAXN=2e6;
const int MOD=998244353;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,m,x[MAXN+5],y[MAXN+5],f[MAXN+5];
int calc(int i,int j){return (x[j]+1ll*(n-i)*y[j]%MOD)%MOD;}
int main(){
	scanf("%d%d",&n,&m);int ivn=qpow(n+m,MOD-2),ivn1=qpow(n-1+m,MOD-2);
	f[0]=1;for(int i=1;i<=n;i++) f[i]=(1ll*i*qpow(i+m,MOD-2)%MOD*f[i-1]+1)%MOD;
	x[n]=f[n];y[n]=(f[n-1]-f[n]+MOD)%MOD;
	for(int j=n-1;j;j--){
		int a1=1ll*(n-j)*ivn%MOD;
		int b1=(MOD-1ll*j*ivn%MOD)%MOD;
		int c1=1ll*(n-j)*ivn%MOD*calc(n-1,j+1)%MOD;
		int a2=1ll*(n-j)*ivn1%MOD;
		int b2=(1-1ll*(j-1+MOD)*2*ivn1%MOD+MOD)%MOD;
		int c2=1ll*(n-j)*ivn1%MOD*calc(n-2,j+1)%MOD;
		(c1+=1)%=MOD;(c2+=1)%=MOD;
		y[j]=1ll*(1ll*c1*a2%MOD-1ll*c2*a1%MOD+MOD)*qpow((1ll*b1*a2%MOD-1ll*b2*a1%MOD+MOD)%MOD,MOD-2)%MOD;
		x[j]=1ll*(c1-1ll*y[j]*b1%MOD+MOD)*qpow(a1,MOD-2)%MOD;
	} printf("%d\n",1ll*(1ll*calc(n-1,1)*n%MOD*ivn%MOD+1ll*m*ivn%MOD)*qpow(n,MOD-2)%MOD*(n+m)%MOD+1);
	return 0;
}