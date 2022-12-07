#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 100;

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

int t,n;
char s[N+5];

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	
	t = read();
	while(t--){
		scanf("%s",s + 1);
		int n0 = 0,n1 = 0;
		n = strlen(s + 1);
		for(rg int i = 1;i <= n;i++)if(s[i] == '0')n0++;else n1++;
		if(min(n0,n1) & 1)puts("DA");
		else puts("NET");
	}
	
	return 0;
}