#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

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
	int T = read();
	while(T--){
		int n = read();
		int prep = 0,prec = 0;
		bool b = 1;
		while(n--){
			int p = read(),c = read();
			if(p < prep || c < prec)b = 0;
			if(c - prec > p - prep)b = 0;
			prep = p,prec = c;
		}
		puts(b ? "YES" : "NO");
	}
	return 0;
}