#include <bits/stdc++.h>
using namespace std;
int n,m,cnt[105][105];
char a[105][105];
int main()
{
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			scanf("%c",&a[i][j]);
		getchar();
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]=='*')
			{
				cnt[i-1][j]++;
				cnt[i-1][j-1]++;
				cnt[i-1][j+1]++;
				cnt[i][j-1]++;
				cnt[i][j+1]++;
				cnt[i+1][j-1]++;
				cnt[i+1][j]++;
				cnt[i+1][j+1]++;
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='.'&&cnt[i][j]){printf("NO"); return 0;}
			if(a[i][j]!='*'&&a[i][j]!='.'&&cnt[i][j]!=a[i][j]-'0'){printf("NO");return 0;}
		}
	printf("YES");
	return 0;
}