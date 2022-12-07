#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e6;

namespace IO{
	In ll read(){
		int s = 0,ww = 1;
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

int n,t;
ll a[N+5],cnta;
ll b[N+5],cntb;
ll s[N+5];
ll sa[N+5];

ll solve(ll a[],int n){
	if(!n)return 0;	
	ll ans = 0;
	for(rg int i = 1;i <= n;i++)sa[i] = sa[i-1] + a[i];
	ll minn = 0;
	for(rg int i = 1;i <= n;i++){
		ans = max(ans,sa[i] - minn);
		minn = min(minn,sa[i]);
	}	
	return ans;
}

int main(){
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);

	t = read();
	while(t--){
		n = read();
		for(rg int i = 0;i < n;i++)s[i] = read();
		ll ans = 0;
		for(rg int i = 0;i < n;i += 2)ans += s[i];
		cnta = 0;
		for(rg int i = 0;i + 1 < n;i += 2)a[++cnta] = s[i+1] - s[i];
		cntb = 0;
		for(rg int i = 1;i + 1 < n;i += 2)b[++cntb] = s[i] - s[i+1];
		ans += max(solve(a,cnta),solve(b,cntb));
		write(ans),putchar('\n');
	}	

	return 0;
}