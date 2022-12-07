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
//	freopen("A.out","w",stdout);
	
	int t = read();
	while(t--){
		ll a = read(),b = read(),c = read();
		ll x,y;
		if(a >= c)x = -1;else x = 1;
		if(a * b <= c)y = -1;else y = b;
		cout << x << " " << y << endl;
	}
	
	
	return 0;
}