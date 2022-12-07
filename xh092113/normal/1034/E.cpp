#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define rg register
#define In inline

const ll N = 2097152;
const ll mod = 1ll << 44;

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
	In void Adjust(ll &x){
		x = (x % mod + mod) % mod;
	}
	In void Tms(ll &x,ll y){
		x = (ll)x * y - (ll)((ld)x * y / mod) * mod;
		Adjust(x);
	}
	In ll Mul(ll x,ll y){
		Tms(x,y);return x;
	}
};
using namespace ModCalc;

ll n,deg;
char s[N+5];
ll a[N+5],b[N+5];

In void calc(ll &x,ll &y,ll opt){
	if(opt == 1)Inc(y,x);
	else Dec(y,x);
}

In void FWT(ll a[],ll deg,ll opt){
	for(rg int n = 2;n <= deg;n <<= 1){
		int m = n >> 1;
		for(rg int i = 0;i < deg;i += n)
			for(rg int j = 0;j < m;j++)calc(a[i+j],a[i+j+m],opt);
	}
}

ll popc[N+5];

int main(){
//	freopen("CF1034E.in","r",stdin);
//	freopen("CF1034E.out","w",stdout);
//cout<<Mul(mod - 5,mod - 10)<<endl;
	scanf("%lld",&n);
	deg = 1ll << n;
	for(rg int i = 1;i < deg;i++)popc[i] = popc[i>>1] + (i&1);
//for(rg int i = 0;i < deg;i++)cout<<popc[i]<<" ";cout<<endl;
	scanf("%s",s);
	for(rg int i = 0;i < deg;i++)a[i] = Mul(s[i] - '0',1ll << (popc[i]<<1));
	scanf("%s",s);
	for(rg int i = 0;i < deg;i++)b[i] = Mul(s[i] - '0',1ll << (popc[i]<<1));
//for(rg int i = 0;i < deg;i++)cout<<a[i]<<" ";cout<<endl;
//for(rg int i = 0;i < deg;i++)cout<<b[i]<<" ";cout<<endl;
	FWT(a,deg,1);
	FWT(b,deg,1);
	for(rg int i = 0;i < deg;i++)Tms(a[i],b[i]);
//for(rg int i = 0;i < deg;i++)cout<<a[i]<<" ";cout<<endl;
	FWT(a,deg,-1);
//for(rg int i = 0;i < deg;i++)cout<<a[i]<<" ";cout<<endl;
	for(rg int i = 0;i < deg;i++)a[i] >>= (popc[i] << 1),a[i] &= 3;
	for(rg int i = 0;i < deg;i++)putchar(a[i] + '0');putchar('\n');
	return 0;
}