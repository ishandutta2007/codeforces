#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

const int N = 1000;

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

int pri[12] = {0,2,3,5,7,11,13,17,19,23,29,31};
int n;
int a[N+5];
int clr[N+5],dir[N+5];
int num[12];

int main(){
//	freopen("B.in","r",stdin);
	int t = read();
	while(t--){
		n = read();
		for(rg int i = 1;i <= n;i++)a[i] = read();
		memset(clr,0,sizeof(int) * (n+1));
		for(rg int i = 1;i <= 11;i++){
			for(rg int j = 1;j <= n;j++)if(!clr[j] && (a[j] % pri[i] == 0))clr[j] = i;
		}
		memset(num,0,sizeof(num));
		for(rg int i = 1;i <= n;i++)num[clr[i]]++;
		int cnt = 0;
		for(rg int i = 1;i <= 11;i++)if(num[i])dir[i] = ++cnt;
		write(cnt),putchar('\n');
		for(rg int i = 1;i <= n;i++){
			write(dir[clr[i]]);
			putchar(i == n ? '\n' : ' ');
		}
	}
	return 0;
}