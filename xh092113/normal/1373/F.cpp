#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e6;

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

ll a[2*N+5],b[2*N+5];
ll t,n;

int main(){
//	freopen("F.in","r",stdin);
//	freopen("F_new.out","w",stdout);
	
	t = read();
	while(t--){
		n = read();
		ll w = 0;
		for(rg int i = 1;i <= n;i++)a[i] = read();
		for(rg int i = 1;i <= n;i++)b[i] = read();
		for(rg int i = 1;i <= n;i++)w += b[i] - a[i];
		if(w < 0){
			puts("NO");
			continue;
		}
		for(rg int i = 1;i <= n;i++)a[i+n] = a[i];
		for(rg int i = 1;i <= n;i++)b[i+n] = b[i];
		a[2*n+1] = b[2*n+1] = 0;
		ll maxn = -b[1],s = 0;
		bool minusloop = 0;
		for(rg int i = 1;i <= 2 * n;i++){
			ll cur = s - maxn;
//cout<<"i="<<i<<" cur="<<cur<<" s="<<s<<" maxn="<<maxn<<endl;
			if(cur < 0)minusloop = 1;
			maxn = max(maxn,s - b[i]);
			s += b[i+1] - a[i+1];
		}
		if(minusloop)puts("NO");
		else puts("YES");
	}	
	
	return 0;	
}