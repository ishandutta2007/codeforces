#include <bits/stdc++.h>
#define Maxn 107
using namespace std;
int n,k;
char s[Maxn][Maxn];
int cnt[Maxn][Maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j+k-1<=n;j++)
		{
			bool check=true;
			for (int t=0;t<k;t++)
				if (s[i][j+t]=='#') check=false;
			if (check)
			{
				for (int t=0;t<k;t++)
					++cnt[i][j+t];
			}
		}
	for (int i=1;i+k-1<=n;i++)
		for (int j=1;j<=n;j++)
		{
			bool check=true;
			for (int t=0;t<k;t++)
				if (s[i+t][j]=='#') check=false;
			if (check)
			{
				for (int t=0;t<k;t++)
					++cnt[i+t][j];
			}
		}
	int ans=0,posx=1,posy=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (cnt[i][j]>ans)
			{
				ans=cnt[i][j];
				posx=i;
				posy=j;
			}
	printf("%d %d\n",posx,posy);
	return 0;
}