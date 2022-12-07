#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

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
}
using namespace IO;

int neg,pos;
int a[N+5],b[N+5];

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	int t = read();
	while(t--){
		int n = read();
		for(rg int i = 1;i <= n;i++)a[i] = read();
		for(rg int i = 1;i <= n;i++)b[i] = read();
		neg = pos = n + 1;
		for(rg int i = 1;i <= n;i++)if(a[i] == 1){pos = i;break;}
		for(rg int i = 1;i <= n;i++)if(a[i] == -1){neg = i;break;}
		bool f = 1;
		for(rg int i = 1;i <= n;i++){
			if(a[i] == b[i])continue;
			if(a[i] < b[i] && i <= pos)f = 0;
			if(a[i] > b[i] && i <= neg)f = 0;
		}
		puts(f ? "YES" : "NO");
	}
	return 0;
}