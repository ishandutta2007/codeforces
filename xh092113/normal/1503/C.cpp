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

int n;
pair<ll,ll> p[N+5]; // <h,c>

In void chkmax(ll &x,ll y){if(y > x)x = y;}

void solve(){
	ll maxn = 0; // max{ci + hi}
	ll ans = 0;
	maxn = p[1].fi + p[1].se;
	rep(i,2,n){
		if(maxn < p[i].fi)ans += p[i].fi - maxn;
		chkmax(maxn,p[i].fi + p[i].se);
	}
	rep(i,1,n)ans += p[i].se;
	write(ans),putchar('\n');
}

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
// USE LONG LONG
	n = read();
	rep(i,1,n){p[i].fi = read();p[i].se = read();}
	sort(p + 1,p + n + 1);
	solve();
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