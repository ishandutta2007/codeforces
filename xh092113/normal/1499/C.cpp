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
};
using namespace IO;

ll n;
ll c[N+5];
ll sumo[N+5],mino[N+5],sume[N+5],mine[N+5];

In void chkmin(ll &x,ll y){if(y < x)x = y;}
ll calco(ll x){
	return sumo[x] + mino[x] * (n - x);	
}
ll calce(ll x){
	return sume[x] + mine[x] * (n - x);
}
ll solve(){
	n = read();
	for(rg int i = 1;i <= n;i++)c[i] = read();
	mino[0] = mine[0] = inf;
	for(rg int i = 1;i * 2 - 1 <= n;i++)sumo[i] = sumo[i-1] + c[i*2-1],mino[i] = min(mino[i-1],c[i*2-1]);
	for(rg int i = 1;i * 2     <= n;i++)sume[i] = sume[i-1] + c[i*2  ],mine[i] = min(mine[i-1],c[i*2  ]);
	ll ans = inf;
//for(rg int i = 1;i * 2 - 1 <= n;i++)cout<<sumo[i]<<" "<<mino[i]<<endl;
//cout<<endl;
//for(rg int i = 1;i * 2 <= n;i++)cout<<sume[i]<<" "<<mine[i]<<endl;
	for(rg int x = 1;2 * x <= n;x++){
		if(2 * x <= n)chkmin(ans,calco(x) + calce(x));
		if(2 * x + 1 <= n){
//			chkmin(ans,calco(x) + calce(x+1));
			chkmin(ans,calco(x+1) + calce(x));
		}
	}
	return ans;
}

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	int Tc = read();
	while(Tc--){
		write(solve()),putchar('\n');
	}
	
	return 0;
}