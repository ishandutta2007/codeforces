#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n;
ll a[300005];

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint();
	for(int i=1;i<=n+n;i++) a[i]=readint();
	sort(a+1,a+n+n+1);
	ll ans=0,tmp1=1,tmp2=1;
	for(int i=n+1;i<=n+n;i++) tmp1=tmp1*i%cys;
	for(int i=1;i<=n;i++) tmp2=tmp2*i%cys;
	tmp1=tmp1*qpow(tmp2,cys-2)%cys;
	for(int i=1;i<=n;i++) ans=(ans+cys-a[i])%cys;
	for(int i=n+1;i<=n+n;i++) ans=(ans+a[i])%cys;
	printf("%lld\n",ans*tmp1%cys);
	return 0;
}