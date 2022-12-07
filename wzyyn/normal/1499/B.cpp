#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

bool f[105][2][2];
char s[105];
void solve(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	memset(f,0,sizeof(f));
	f[0][0][0]=1;
	f[0][1][0]=1;
	For(i,1,n) For(j,0,1) For(k,0,1){
		if (s[i]=='0'+j) f[i][j][0]|=f[i-1][j][k];
		if (!k) f[i][j][1]|=f[i-1][j][k];
		if (j) f[i][j][k]|=f[i][j-1][k];
	}
	puts(f[n][1][0]||f[n][1][1]?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}