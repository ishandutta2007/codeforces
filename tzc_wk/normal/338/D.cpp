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
const int MAXK=1e4;
ll n,m,a[MAXK+5],lcm=1,ans=0;int k;
ll gcd(ll a,ll b){return (!b)?a:gcd(b,a%b);}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){x=1;y=0;return;}
	exgcd(b,a%b,x,y);ll tmp=x;x=y;y=tmp-(a/b)*y;
}
ll prod(ll a,ll b,ll mod){
	a=(a%mod+mod)%mod;b=(b%mod+mod)%mod;ll ret=0;
	for(;b;b>>=1,(a+=a)%=mod) if(b&1) (ret+=a)%=mod;
	return ret;
}
int main(){
	scanf("%lld%lld%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%lld",&a[i]);
		if(lcm/gcd(lcm,a[i])>n/a[i]) return puts("NO"),0;
		lcm=lcm/gcd(lcm,a[i])*a[i];
	} if(lcm>n) return puts("NO"),0;lcm=1;
	for(int i=1;i<=k;i++){
		ll rem=((1-i)%a[i]+a[i])%a[i];
		ll x,y,d=gcd(lcm,a[i]),new_m=lcm/d*a[i];
		if(abs(ans-rem)%d) return puts("NO"),0;
		exgcd(lcm,a[i],x,y);x=prod(x,(rem-ans)/d,new_m);
		ans=(prod(x,lcm,new_m)+ans)%new_m;lcm=new_m;
	} if(!ans) ans=lcm;if(ans>m-k+1) return puts("NO"),0;
	for(int i=1;i<=k;i++) if(gcd(lcm,ans+i-1)!=a[i]) return puts("NO"),0;
	puts("YES");
	return 0;
}