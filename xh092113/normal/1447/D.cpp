#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 5000;

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
};
using namespace IO;

int n,m;
int f[N+5][N+5];
char s[N+5],t[N+5];

In void chkmax(int &x,int y){if(y > x)x = y;}

int main(){
//	freopen("CF1447D.in","r",stdin);
//	freopen("CF1447D.out","w",stdout);
	n = read(),m = read();	
	scanf("%s",s + 1);
	scanf("%s",t + 1);
	for(rg int i = 0;i <= n;i++){
		for(rg int j = 0;j <= m;j++){
			if(i)chkmax(f[i][j],f[i-1][j] - 1);
			if(j)chkmax(f[i][j],f[i][j-1] - 1);
			if(i && j && s[i] == t[j])chkmax(f[i][j],f[i-1][j-1] + 2);
		}
	}
	int ans = 0;
	for(rg int i = 0;i <= n;i++)
		for(rg int j = 0;j <= m;j++)chkmax(ans,f[i][j]);
	write(ans),putchar('\n');
//for(rg int i = 0;i <= n;i++){
//	for(rg int j = 0;j <= m;j++)cout<<f[i][j]<<" ";cout<<endl;
//}
	return 0;
}