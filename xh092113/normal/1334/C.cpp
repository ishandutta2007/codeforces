#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 3e5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

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

ll a[N+5],b[N+5],f[N+5];
ll n;

In ll pred(ll x){return x == 1 ? n : x - 1;}
In ll succ(ll x){return x == n ? 1 : x + 1;}

int main(){
//	freopen("C.in","r",stdin);
	ll T = read();
	while(T--){
		n = read();
		for(rg int i = 1;i <= n;i++)a[i] = read(),b[i] = read();
		for(rg int i = 1;i <= n;i++)f[i] = max(0ll,a[i] - b[pred(i)]);
		ll ans = inf,sum = 0;
		for(rg int i = 1;i <= n;i++)sum += f[i];
		for(rg int i = 1;i <= n;i++)ans = min(ans,sum - f[i] + a[i]);
		write(ans),putchar('\n');
	}
	return 0;
}