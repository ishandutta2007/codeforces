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
const int MAXK=2e5;
const int MOD=1e9+7;
int qpow(int x,int e){
	if(e<0) return 0;int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int fac[MAXK+5],ifac[MAXK+5];
void init_fac(int n){
	fac[0]=1;for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[n]=qpow(fac[n],MOD-2);for(int i=n-1;~i;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%MOD;
}
int n,k,sum=0,ans=0;
int main(){
	scanf("%d%d",&n,&k);init_fac(k);
	for(int i=1;i<=n;i++){int x;scanf("%d",&x);(sum+=x)%=MOD;}
	for(int i=0;i<k;i++){
		if((k-1-i)&1) ans=(ans-1ll*ifac[i]%MOD*ifac[k-1-i]%MOD*(qpow(i+1,n-1)+1ll*(n-1)*qpow(i+1,n-2)%MOD)%MOD+MOD)%MOD;
		else ans=(ans+1ll*ifac[i]%MOD*ifac[k-1-i]%MOD*(qpow(i+1,n-1)+1ll*(n-1)*qpow(i+1,n-2)%MOD)%MOD)%MOD;
	} printf("%d\n",1ll*sum*ans%MOD);
	return 0;
}