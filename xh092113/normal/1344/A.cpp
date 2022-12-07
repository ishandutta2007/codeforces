#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 2e5;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)x = -x,putchar('-');
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

bool f[N+5];

In ll check(ll x,ll mod){
	return (x % mod + mod) % mod;
}

int main(){
////	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int t = read();
	while(t--){
		int n = read();
		for(rg int i = 0;i < n;i++)f[check(i+read(),n)] = 1;
		bool b = 1;
		for(rg int i = 0;i < n;i++)if(!f[i])b = 0;
		puts(b ? "YES" : "NO");
		for(rg int i = 0;i < n;i++)f[i] = 0;
	}
	return 0;
}