#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXK=1e6;
const int MOD=1e9+7;
int n,k,pre[MAXK+5],suf[MAXK+5],fac[MAXK+5],ifac[MAXK+5];
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int main(){
	scanf("%d%d",&n,&k);
	if(k==0) return printf("%d\n",n),0;
	pre[0]=n;for(int i=1;i<=k+1;i++) pre[i]=1ll*pre[i-1]*(n-i+MOD)%MOD;
	suf[k+2]=1;for(int i=k+1;~i;i--) suf[i]=1ll*suf[i+1]*(n-i+MOD)%MOD;
	fac[0]=1;for(int i=1;i<=k+1;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[k+1]=qpow(fac[k+1],MOD-2);for(int i=k;~i;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%MOD;
	int sum=0,ans=0;for(int i=0;i<=k+1;i++){
		sum=(sum+qpow(i,k))%MOD;int mul=1;
		if(i!=0) mul=1ll*mul*pre[i-1]%MOD;if(i!=k+1) mul=1ll*mul*suf[i+1]%MOD;
		mul=1ll*mul*ifac[i]%MOD;mul=1ll*mul*ifac[k+1-i]%MOD;mul=1ll*mul*sum%MOD;
		if((k+1-i)&1) ans=(ans-mul+MOD)%MOD;else ans=(ans+mul)%MOD;
	} printf("%d\n",ans);
	return 0;
}
/*
n(n+1)(2n+1)(3n^2+3n-1)/30
*/