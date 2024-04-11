#include <bits/stdc++.h>
using namespace std;
int n,m;
char str[1005][1005];
bool NO,vis[1005][1005];
int main()
{
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			str[i][j]=getchar();
		getchar();
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(str[i-1][j-1]=='#'&&str[i-1][j]=='#'&&str[i-1][j+1]=='#'&&str[i][j-1]=='#'&&str[i][j+1]=='#'&&str[i+1][j-1]=='#'&&str[i+1][j]=='#'&&str[i+1][j+1]=='#')
				 vis[i-1][j-1]=vis[i-1][j]=vis[i-1][j+1]=vis[i][j-1]=vis[i][j+1]=vis[i+1][j-1]=vis[i+1][j]=vis[i+1][j+1]=true;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(str[i][j]=='#'&&!vis[i][j]) NO=true;
	if(NO) printf("No");
	else printf("Yes");
	return 0;
}