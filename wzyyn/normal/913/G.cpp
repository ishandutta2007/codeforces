#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
ll mul(ll x,ll y,ll mod){
	ll t=x*y-(ll)((long double)x/mod*y)*mod;
	return (t%mod+mod)%mod;
}
ll power(ll x,ll y,ll mod){
	ll s=1;
	for (;y;y/=2,x=mul(x,x,mod))
		if (y&1) s=mul(s,x,mod);
	return s;
}
void solve(){
	ll x;
	scanf("%lld",&x);
	x=x*1000000;
	for (;;x+=(1<<17)-x%(1<<17))
		if (x%(1<<17)==0&&x%(5<<17))
			break;
	x>>=17;
	ll P=1,ord=0;
	For(T,1,17){
		for (;power(2,ord,P*5)!=x%(P*5);ord+=(T==1?1:P/5*4));
		P*=5;
	}
	printf("%lld\n",ord+17);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
2^k mod 10^{n+m} = a*10^m+b

k>=n+m

2^{k-n-m} mod 5^{n+m} = (a*10^m+b)/2^{n+m}

b

bsgs( 
*/