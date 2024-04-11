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
const int MAXN=1e6;
const int MOD=998244353;
int qpow(int x,ll e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1ll) ret=1ll*ret*x%MOD;
	return ret;
}
int n,ans=0,fac[MAXN+5],ifac[MAXN+5];
int binom(int x,int y){return 1ll*fac[x]*ifac[y]%MOD*ifac[x-y]%MOD;}
//int calcf(int x,int y){
//	if(!x) return qpow(3,1ll*n*(n-y)+y);
//	if(!y) return qpow(3,1ll*n*(n-x)+x);
//	return qpow(3,1ll*(n-x)*(n-y)+1);
//}
int main(){
	scanf("%d",&n);
	fac[0]=1;for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[n]=qpow(fac[n],MOD-2);for(int i=n-1;~i;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%MOD;
//	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++){
//		if((i+j)&1) ans=(ans-1ll*calcf(i,j)*binom(n,i)%MOD*binom(n,j)%MOD+MOD)%MOD;
//		else ans=(ans+1ll*calcf(i,j)*binom(n,i)%MOD*binom(n,j)%MOD)%MOD;
//	}
	for(int i=1;i<=n;i++){
		if(i&1) ans=(ans-1ll*qpow(3,1ll*n*(n-i)+i)*binom(n,i)%MOD+MOD)%MOD;
		else ans=(ans+1ll*qpow(3,1ll*n*(n-i)+i)*binom(n,i)%MOD)%MOD;
	} (ans*=2)%=MOD;(ans+=qpow(3,1ll*n*n))%=MOD;
	int pw3=1;
	for(int i=0;i<n;i++){
		int val=1ll*(qpow((1-pw3+MOD)%MOD,n)-qpow(MOD-pw3,n)+MOD)%MOD*3%MOD;
		if(i&1) ans=(ans-1ll*binom(n,i)*val%MOD+MOD)%MOD;
		else ans=(ans+1ll*binom(n,i)*val%MOD)%MOD;
		pw3=3ll*pw3%MOD;
	} ans=(qpow(3,1ll*n*n)-ans+MOD)%MOD;
	printf("%d\n",ans);
	return 0;
}