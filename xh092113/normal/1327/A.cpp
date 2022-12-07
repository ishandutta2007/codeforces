#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

namespace IO{
	In int read(){
		int s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(int x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

int main(){
//	freopen("A.in","r",stdin);
	int t = read();
	while(t--){
		ll n = read(),k = read();
		n -= k;
		if(n % 2 != 0 || n < 0)puts("NO");
		else{
			n >>= 1;
			ll d = k * (k - 1) >> 1;
			if(n >= d)puts("YES");
			else puts("NO"); 
		}
	}
	return 0;
}