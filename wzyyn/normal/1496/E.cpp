#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

int n,m;
char s[505][505];
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",s[i]+1);
	int fir=(n%3==0?2:1);
	for (int i=fir;i<=n;i+=3)
		For(j,1,m) s[i][j]='X';
	for (int i=fir;i+3<=n;i+=3)
		if (s[i+1][2]=='X'||s[i+2][2]=='X')
			s[i+1][2]=s[i+2][2]='X';
		else s[i+1][1]=s[i+2][1]='X';
	For(i,1,n)
		printf("%s\n",s[i]+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}