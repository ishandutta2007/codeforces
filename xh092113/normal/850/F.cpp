#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e5;
const ll S = 2.5e8;
const ll mod = 1e9 + 7;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

namespace ModCalc{
	In void Inc(ll &x,ll y){
		x += y;if(x >= mod)x -= mod;
	}
	In void Dec(ll &x,ll y){
		x -= y;if(x < 0)x += mod;
	}
	In ll Add(ll x,ll y){
		Inc(x,y);return x;
	}
	In ll Sub(ll x,ll y){
		Dec(x,y);return x;
	}
}
using namespace ModCalc;

ll power(ll a,ll n){
	ll s = 1,x = a;
	while(n){
		if(n & 1)s = s * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return s;
}

ll f[N+5],a[N+5],inv[N+5];
ll n;

int main(){
//	freopen("CF850F.in","r",stdin);
//	freopen("CF850F.out","w",stdout);
	n = read();
	for(rg int i = 1;i <= n;i++)a[i] = read();
	for(rg int i = 1;i <= N;i++)inv[i] = power(i,mod - 2);
//cout << 1 << endl;
	ll sum = 0;
	for(rg int i = 1;i <= n;i++)Inc(sum,a[i]);
//cout << 2 << endl;
	f[1] = 1ll * Sub(sum,1) * Sub(sum,1) % mod * power(sum,mod-2) % mod;
	ll maxn = 0;
	for(rg int i = 1;i <= n;i++)maxn = max(maxn,a[i]); 
//cout<<maxn<<endl;
	for(rg int i = 1;i < maxn;i++)f[i+1] = Sub(2 * f[i] % mod,Add(f[i-1],Sub(sum,1)*power(Sub(sum,i),mod-2)%mod));
//cout << 3 << endl; 
	ll ans = 0;
	for(rg int i = 1;i <= n;i++)Inc(ans,f[a[i]]);
	write(ans),putchar('\n');
	return 0;	
}