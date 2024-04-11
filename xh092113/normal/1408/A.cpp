#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 100;
const int inf = 0x3f3f3f3f;

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
};
using namespace IO;

int n;
int a[N+5][4],last[3*N+5];
int p[N+5];

In int id(int i,int j){
	return (i - 1) * 3 + j;
}
bool check(int g){
	memset(last,0x3f,sizeof(last));
	last[id(1,g)] = 0;
	for(rg int i = 2;i <= n;i++)
		for(rg int j = 1;j <= 3;j++)
			for(rg int k = 1;k <= 3;k++)if(last[id(i-1,k)] != inf && a[i-1][k] != a[i][j])last[id(i,j)] = id(i-1,k);
	int s = -1;
	for(rg int i = 1;i <= 3;i++)if(last[id(n,i)] != inf && a[1][g] != a[n][i])s = id(n,i);
	if(s == -1)return 0;
	int cnt = 0;
	for(rg int u = s;u != 0;u = last[u])p[++cnt] = a[(u-1)/3+1][(u-1)%3+1];
	for(rg int i = 1;i < n + 1 - i;i++)swap(p[i],p[n+1-i]);
	for(rg int i = 1;i <= n;i++)
		write(p[i]),putchar(i == n ? '\n' : ' ');
	return 1;
}
void solve(){
	n = read();
	for(rg int j = 1;j <= 3;j++)
		for(rg int i = 1;i <= n;i++)a[i][j] = read();
	if(check(1))return;
	if(check(2))return;
	if(check(3))return;
}

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	
	int T = read();
	while(T--)solve();		
	
	return 0;
}