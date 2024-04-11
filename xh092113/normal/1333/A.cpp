#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 100;

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

int clr[N+5][N+5];

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int t = read();
	while(t--){
		int n = read(),m = read();
		for(rg int i = 1;i <= n;i++)
			for(rg int j = 1;j <= m;j++)clr[i][j] = (i + j - 1) % 2;
		if(n % 2 == 0 || m % 2 == 0){
			if(m >= 2)clr[1][2] = 1;
			else clr[2][1] = 1;
		}
		for(rg int i = 1;i <= n;i++){
			for(rg int j = 1;j <= m;j++)putchar(clr[i][j] ? 'B' : 'W');
			putchar('\n');
		}
	}
	return 0;
}