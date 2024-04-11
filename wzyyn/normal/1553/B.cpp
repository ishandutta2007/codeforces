#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=1005;
int f[N][N];
int g[N][N];
int clk;
char s[N],t[N];
void solve(){
	++clk;
	scanf("%s",s+1);
	scanf("%s",t+1);
	int n=strlen(s+1);
	int m=strlen(t+1);
	bool flg=0;
	for (int i=1;i<=n;i++)
		if (s[i]==t[1]){
			if (m==1) flg=1;
			f[i][1]=clk;
		}
	for (int j=2;j<=m;j++)
		for (int i=1;i<=n;i++)
			if (s[i]==t[j]){
				if (i!=1&&f[i-1][j-1]==clk) f[i][j]=clk;
				if (i!=n&&f[i+1][j-1]==clk) g[i][j]=clk;
				if (i!=n&&g[i+1][j-1]==clk) g[i][j]=clk;
				if (j==m&&f[i][j]==clk) flg=1;
				if (j==m&&g[i][j]==clk) flg=1;
			}
	puts(flg?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}