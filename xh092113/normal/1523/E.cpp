#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define rep(i,l,r) for(rg int i = (l);i <= (r);i++)
#define dwn(i,r,l) for(rg int i = (r);i >= (l);i--)
#define mp make_pair
#define fi first
#define se second

const ll mod = 1e9 + 7;
const int N = 1e5;

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
};
using namespace IO;

In void chkmin(ll &x,ll y){if(y < x)x = y;}
In void chkmax(ll &x,ll y){if(y > x)x = y;}

namespace ModCalc{
	In void Inc(ll &x,ll y){x += y;if(x >= mod)x -= mod;}
	In void Dec(ll &x,ll y){x -= y;if(x < 0)x += mod;}
	In ll Add(ll x,ll y){Inc(x,y);return x;}
	In ll Sub(ll x,ll y){Dec(x,y);return x;}
};
using namespace ModCalc;

ll jc[N+5],iv[N+5];

In ll power(ll a,ll n){
	ll s = 1,x = a;
	while(n){
		if(n & 1)s = s * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return s;
}

void prepro(){
	jc[0] = 1;rep(i,1,N)jc[i] = jc[i-1] * i % mod;
	iv[N] = power(jc[N],mod - 2);
	dwn(i,N - 1,0)iv[i] = iv[i+1] * (i + 1) % mod;
}
In ll C(ll n,ll m){
	if(n < m || m < 0)return 0;
	return jc[n] * iv[m] % mod * iv[n-m] % mod;
}

ll n,k,p[N+5];

void solve(){
	memset(p,0,sizeof(p));
	n = read(),k = read();
	p[1] = 1;
	rep(i,1,n){
		int m = n - (i - 1) * (k - 1);
		if(m < i)break;
		// C(m,i) * i! * n! / (n-i)!
		p[i+1] = jc[m] * iv[m-i] % mod * iv[n] % mod * jc[n-i] % mod;
	}
//rep(i,1,n)cout<<"i="<<i<<" p="<<p[i]<<endl;
	rep(i,1,n - 1)Dec(p[i],p[i+1]);
	ll ans = 0;
//rep(i,1,n)cout<<"i="<<i<<" p="<<p[i]<<endl;
	rep(i,1,n)Inc(ans,p[i] * i % mod);
	write(ans),putchar('\n');
}

int main(){
//	freopen("E.in","r",stdin);
//	freopen("E.out","w",stdout);
	
	prepro();
	int Tc = read();
	while(Tc--)solve();
	
	return 0;
}
// T: Think
// E: Enough array size
// M: Memory limit
// P: Precision
// B: Boundary
// O: Overflow
// T: Time limit
// M: Mod
// F: File