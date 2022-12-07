#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const ll mod = 998244353;
const ll SN = 32e6;
const ll PN = 32e5;

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

bool isp[SN+5];
ll pri[PN+5],pn;
ll D;

void Eular(){
	for(rg int i = 2;i <= SN;i++)isp[i] = 1;
	for(rg int i = 2;i <= SN;i++){
		if(isp[i])pri[++pn] = i;
		for(rg int j = 1;1ll * i * pri[j] <= SN;j++){
			isp[i*pri[j]] = 0;
			if(i % pri[j] == 0)break;
		}
	}
}

ll jc[120+5],iv[120+5];

ll power(ll a,ll n){
	ll x = a,s = 1;
	while(n){
		if(n & 1)s = s * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return s;
}

void prepro(){
	jc[0] = 1;
	for(rg int i = 1;i <= 120;i++)jc[i] = jc[i-1] * i % mod;
//cout<<"anju"<<endl;
 	iv[120] = power(jc[120],mod - 2);
//cout<<"sks"<<endl;
 	for(rg int i = 119;i >= 0;i--)iv[i] = iv[i+1] * (i + 1) % mod;
}

ll v(ll n,ll p){
	ll x = 0;
	while(n % p == 0)x++,n /= p;
	return x;
}

ll f[120+5];
vector<ll>fac;

int main(){
//	freopen("E.in","r",stdin);
//cout<<1ll*998244353*19709<<endl;
	D = read();
	Eular();
//cout<<pn<<endl;
//for(rg int i = pn - 99;i <= pn;i++)cout<<pri[i]<<" ";cout<<endl;
//for(rg int i = 1;i <= 25;i++)cout<<pri[i]<<" ";cout<<endl;
	for(rg int i = 1;i <= pn;i++)if(D % pri[i] == 0){
		fac.push_back(pri[i]);
		while(D % pri[i] == 0)D /= pri[i];
	}
	if(D != 1)fac.push_back(D);
//for(auto x : fac)cout<<x<<" ";cout<<endl;
	prepro();
	ll q = read();
	while(q--){
//cout<<q<<endl;
		ll x = read(),y = read();
		for(rg int i = 0;i < fac.size();i++)f[i] = v(x,fac[i]) - v(y,fac[i]);
//for(rg int i = 0;i < fac.size();i++)cout<<f[i]<<" ";cout<<endl;
		ll pos = 0,neg = 0;
		for(rg int i = 0;i < fac.size();i++)if(f[i] > 0)pos += f[i];else neg -= f[i];
		pos = jc[pos];
		neg = jc[neg];
		for(rg int i = 0;i < fac.size();i++)if(f[i] > 0)pos = pos * iv[f[i]] % mod;
			else neg = neg * iv[-f[i]] % mod;
		write(pos * neg % mod),putchar('\n');
	}	
	return 0;
}