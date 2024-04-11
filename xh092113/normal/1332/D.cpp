#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

const int N = 1e5;

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

int n,m;
int lg[N+5];

int main(){
//	freopen("D.in","r",stdin);
	for(rg int i = 2;i <= N;i++)lg[i] = lg[i>>1] + 1;
	int k = read();
	puts("2 3");
	int x = (1<<(lg[k]+1)) - 1;
	int y = (x << 1) | 1;
	write(y),putchar(' '),write(y - k),putchar(' '),puts("0");
	write(x),putchar(' '),write(y),putchar(' '),write(x),putchar('\n');
	return 0;
}