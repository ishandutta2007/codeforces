#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,m,f;
char s[N][N],t[N][N];
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			t[i][j]=((i+j)&1?'R':'W');
	f=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if((s[i][j]^t[i][j])==('R'^'W'))
				f=0;
	if(f)
	{
		puts("YES");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				printf("%c",t[i][j]);
			puts("");
		}
		return;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			t[i][j]=((i+j)&1?'W':'R');
	f=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if((s[i][j]^t[i][j])==('R'^'W'))
				f=0;
	if(f)
	{
		puts("YES");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				printf("%c",t[i][j]);
			puts("");
		}
		return;
	}
	puts("NO");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}