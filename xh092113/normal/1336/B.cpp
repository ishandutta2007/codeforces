#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e5;
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

In ll sqr(ll x){return x * x;}

In ll calc(ll x,ll y,ll z){
//cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl;
	return sqr(x - y) + sqr(y - z) + sqr(z - x);
}

In void chkmin(ll &x,ll y){
	if(y < x)x = y;
}

ll r[N+5],g[N+5],b[N+5];
ll rn,gn,bn;
ll ans;

void solve(ll r[],ll g[],ll b[],ll rn,ll gn,ll bn){
	for(rg int i = 1;i <= rn;i++){
		int gl = upper_bound(g + 1,g + gn + 1,r[i]) - g - 1;
		int gr = lower_bound(g + 1,g + gn + 1,r[i]) - g;
		int bl = upper_bound(b + 1,b + bn + 1,r[i]) - b - 1;
		int br = lower_bound(b + 1,b + bn + 1,r[i]) - b;
//cout<<gl<<" "<<gr<<" "<<bl<<" "<<br<<endl;
		if(1 <= gl && gl <= gn && 1 <= br && br <= bn)chkmin(ans,calc(r[i],g[gl],b[br]));
		if(1 <= gr && gr <= gn && 1 <= bl && bl <= bn)chkmin(ans,calc(r[i],g[gr],b[bl]));
	}	
}

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);	
	int T = read();
	while(T--){
		ans = inf;
		int rn = read(),gn = read(),bn = read();
		for(rg int i = 1;i <= rn;i++)r[i] = read();
		for(rg int i = 1;i <= gn;i++)g[i] = read();
		for(rg int i = 1;i <= bn;i++)b[i] = read();
		sort(r + 1,r + rn + 1);
		sort(g + 1,g + gn + 1);
		sort(b + 1,b + bn + 1);
		solve(r,g,b,rn,gn,bn);
		solve(g,b,r,gn,bn,rn);
		solve(b,r,g,bn,rn,gn);
		write(ans),putchar('\n');
	}
	return 0;
}