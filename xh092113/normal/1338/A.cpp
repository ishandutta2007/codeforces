#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const ll N = 1e5;

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

ll a[N+5];
/*
ll calc(ll ans,ll goal){
	ll s = ans;
	for(rg int i = 31;i >= 0;i--){
		if(ans & (1ll<<i))continue;
		if((s|((1ll<<i)-1)) < goal)s ^= (1ll<<i);
	}
	return s;
}*/

ll lg(ll x){
	ll rt = 0;
	for(rg int i = 0;i <= 31;i++)if(x & (1ll<<i))rt = i + 1;
	return rt;	
}

int main(){
//	freopen("A.in","r",stdin);
	int T = read();
	while(T--){
		int n = read();
		for(rg int i = 1;i <= n;i++)a[i] = read();
		ll ans = 0;
		for(rg int i = 2;i <= n;i++){
			if(a[i-1] <= a[i])continue;
			ll dt = a[i-1] - a[i];
//cout<<"dt="<<dt<<endl;
			ans = max(ans,lg(dt));
			a[i] = a[i-1];
//cout<<ans<<endl;
		}
		write(ans),putchar('\n');
	}
	return 0;
}