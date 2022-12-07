#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 500;

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

int f[N+5][N+5];
int n;

void print(){
	for(rg int i = 1;i <= n;i++){
		for(rg int j = 1;j <= n;j++)write(f[i][j]),putchar(' ');
		putchar('\n');
	}
}

int main(){
//	freopen("E.in","r",stdin);
//	freopen("E.out","w",stdout);
	n = read();
	if(n <= 2){
		puts("-1");
		return 0;
	}
if(n == 3){
puts("1 7 9"); 
puts("3 2 5"); 
puts("4 8 6");
return 0; 
}
	f[1][1] = 4,f[1][2] = 3,f[1][3] = 6,f[1][4] = 12; 
f[2][1] = 7,f[2][2] =  5,f[2][3] =  9,f[2][4] =  15; 
f[3][1] = 14,f[3][2] =  1,f[3][3] =  11,f[3][4] =  10; 
f[4][1] = 13,f[4][2] =  8,f[4][3] =  16,f[4][4] = 2;
	if(n == 4){
		print();
		return 0;
	}
	for(rg int i = 1;i <= 4;i++)
		for(rg int j = 1;j <= 4;j++)f[i][j] += n * n - 16;
	int cnt = 0;
	for(rg int i = 5;i <= n;i++){
		if((n - i) % 2 == 0)for(rg int j = 1;j <= n;j++)f[i][j] = ++cnt;
		else for(rg int j = n;j >= 1;j--)f[i][j] = ++cnt;
	}
	for(rg int i = n;i >= 6;i--){
		if((n - i) % 2 == 0)for(rg int j = 1;j <= 4;j++)f[j][i] = ++cnt;
		else for(rg int j = 4;j >= 1;j--)f[j][i] = ++cnt;
	}
	if((n - 5) % 2 == 0)f[1][5] = ++cnt,f[2][5] = ++cnt,f[4][5] = ++cnt,f[3][5] = ++cnt;
	else f[4][5] = ++cnt,f[1][5] = ++cnt,f[2][5] = ++cnt,f[3][5] = ++cnt;
	print();
	return 0;
}