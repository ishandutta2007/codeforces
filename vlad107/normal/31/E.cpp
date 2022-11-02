#include <stdio.h>
#include <memory.h>

#define MAXN 100

unsigned long long f[MAXN][MAXN][MAXN],st10[MAXN];
int g[MAXN][MAXN][MAXN];
int n;
char s[MAXN],res[MAXN];

int main(){
	scanf("%d%s",&n,s);
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	st10[0]=1;
	for (int i=1;i<=n;i++)st10[i]=st10[i-1]*10;
	g[0][n][n]=1;
	for (int i=0;i<n+n;i++)
		for (int x=n;x>=0;x--)
			for (int y=n;y>=0;y--){
				if (!g[i][x][y])continue;
				if (x>0&&f[i][x][y]+st10[x-1]*(s[i]-'0')>=f[i+1][x-1][y]){
					f[i+1][x-1][y]=f[i][x][y]+st10[x-1]*(s[i]-'0');
					g[i+1][x-1][y]=1;
				}
				if (y>0&&f[i][x][y]+st10[y-1]*(s[i]-'0')>=f[i+1][x][y-1]){
					f[i+1][x][y-1]=f[i][x][y]+st10[y-1]*(s[i]-'0');
					g[i+1][x][y-1]=2;
				}
			}
	int x=0,y=0;    
	for (int i=n+n;i>0;i--)
		if (g[i][x][y]==1){res[i-1]='H';x++;}
		else{res[i-1]='M';y++;}
	puts(res);
}