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
const int MOD=1e9+7;
const int INV2=5e8+4;
ll n,m;
int sum(ll x){x%=MOD;return x*(x+1)%MOD*INV2%MOD;}
int main(){
	scanf("%lld%lld",&n,&m);int ret=1ll*(n%MOD)*(m%MOD)%MOD;
	for(ll l=1,r;l<=min(n,m);l=r+1){
		r=min(n/(n/l),m);
		ret=(ret-1ll*(sum(r)-sum(l-1)+MOD)*((n/l)%MOD)%MOD+MOD)%MOD;
	} printf("%d\n",ret);
	return 0;
}