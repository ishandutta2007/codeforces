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
};
using namespace IO;

int n,top;
ll h[N+5],b[N+5],f[N+5];
multiset<ll> S;

struct node{
	int l,r;ll maxf;
	node(){l = r = maxf = 0;}
	node(int _l,int _r,ll _maxf){l = _l,r = _r,maxf = _maxf;}
}st[N+5];

In void chkmax(ll &x,ll y){if(y > x)x = y;}
In void chkmin(ll &x,ll y){if(y < x)x = y;}
In ll getw(node x){return x.maxf + b[x.r];}
void solve(){
	f[1] = b[1];
	st[top=1] = node(0,1,0);
	S.insert(getw(st[top]));
	for(rg int i = 1;i <= n;i++){
		ll curmaxf = f[i-1];
		while(top && h[st[top].r] >= h[i]){
			chkmax(curmaxf,st[top].maxf);
			S.erase(S.lower_bound(getw(st[top])));
			top--;			
		}
		st[top+1] = node(st[top].r,i,curmaxf);
		top++;
		S.insert(getw(st[top]));
		f[i] = *(--S.end());
//cout<<"i="<<i<<" f="<<f[i]<<endl;
//for(rg int j = 1;j <= top;j++)cout<<"l="<<st[j].l<<" r="<<st[j].r<<" maxf="<<st[j].maxf<<endl;
//for(auto x : S)cout<<"x="<<x<<endl;
	}
	write(f[n]),putchar('\n');
}

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
// USE LONG LONG
	n = read();
	h[0] = -inf,b[0] = 0;
	for(rg int i = 1;i <= n;i++)h[i] = read();
	for(rg int i = 1;i <= n;i++)b[i] = read();
	solve();
	return 0;
}