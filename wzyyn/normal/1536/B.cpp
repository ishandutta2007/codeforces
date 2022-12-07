#include<bits/stdc++.h>

using namespace std;
int n;
char s[2005];
int vis[4][30000];

void solve(){
	static int clk=0; ++clk;
	scanf("%d%s",&n,s+1);
	for (int i=1;i<=n;i++) s[i]-='a';
	for (int i=1;i<=n;i++) vis[1][s[i]]=clk;
	for (int i=1;i<=n-1;i++) vis[2][s[i]*26+s[i+1]]=clk;
	for (int i=1;i<=n-2;i++) vis[3][s[i]*26*26+s[i+1]*26+s[i+2]]=clk;
	for (int i=0;i<26;i++) if (vis[1][i]!=clk){
		putchar('a'+i);
		puts("");
		return; 
	}
	for (int i=0;i<26*26;i++) if (vis[2][i]!=clk){
		putchar('a'+i/26);
		putchar('a'+i%26);
		puts("");
		return; 
	}
	for (int i=0;i<26*26*26;i++) if (vis[3][i]!=clk){
		putchar('a'+i/26/26);
		putchar('a'+i/26%26);
		putchar('a'+i%26);
		puts("");
		return; 
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}