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

char s[10];

int main(){
	scanf("%s",s + 1);
	write((s[7] - '0') & 1);putchar('\n');
	return 0;
}