#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N=2005;
int n,f[N][N];
int tg[N];
char s[N];
int main(){
	scanf("%d",&n);
	if (n&1){
		puts("NONE");
		return 0;
	}
	for (int i=1;i<=n;i++){
		f[1][i]=f[i][1]=(i+1)/2;
		f[i][n]=f[n][i]=(n-i+1+1)/2;
	}
	for (int i=2;i<n;i++)
		for (int j=2;j<n;j++)
			if ((i+j)&1) f[i][j]=-f[i-1][j-1];
			else f[i][j]=-f[i-1][j+1];
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=n;j++)
			if (s[j]!='.'){
				int idx=abs(f[i][j]);
				int val=(s[j]=='S'?1:-1)*(f[i][j]>0?1:-1);
				if (!tg[idx]) tg[idx]=val;
				else if (tg[idx]!=val){
					puts("NONE");
					return 0;
				}
			}
	}
	for (int i=1;i<=n/2;i++)
		if (!tg[i]){
			puts("MULTIPLE");
			return 0;
		}
	puts("UNIQUE");
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			int v=tg[abs(f[i][j])]*(f[i][j]>0?1:-1);
			putchar(v==1?'S':'G');
		}
		puts("");
	}
}