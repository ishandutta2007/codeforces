// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=2000000,cys=1000000007;
int n,m,k;
ll fac[2000005],inv[2000005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

ll C(ll x,ll y){return x<y?0:fac[x]*inv[y]%cys*inv[x-y]%cys;}

int main(){
	int T=readint();
	fac[0]=inv[0]=1;
	for(int i=1;i<=N;i++) fac[i]=fac[i-1]*i%cys;
	inv[N]=qpow(fac[N],cys-2);
	for(int i=N-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	while(T--){
		n=readint(); m=readint(); k=readint();
		if(n==m){
			printf("%lld\n",1ll*n*k%cys);
			continue;
		}
		ll ans=0,now=1;
		for(int i=1;i<m;i++){
			ans=(ans+i*now%cys*C(n-i-1,m-i))%cys;
			now=now*2%cys;
		}
		ans=mod(ans+m*now%cys);
		printf("%lld\n",ans*k%cys*qpow((cys+1)/2,n-1)%cys);
	}
	return 0;
}