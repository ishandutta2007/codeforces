#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
char s[Maxn];
int ans[Maxn];
int nxt1[Maxn],nxt2[Maxn],tot1=0,tot2=0;
vector<int> p[Maxn];
int cnt=0;
int len;
int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	memset(ans,0,sizeof(ans));
	for (int i=1;i<=len;i++)
		if (s[i]=='0')
		{
			if (tot2!=0)
			{
				ans[i]=nxt2[tot2];
				--tot2;
				nxt1[++tot1]=ans[i];
			} else
			{
				ans[i]=++cnt;
				nxt1[++tot1]=cnt;
			}
			p[ans[i]].push_back(i);
		} else
		{
			if (tot1==0)
			{
				printf("%d\n",-1);
				return 0;
			}
			ans[i]=nxt1[tot1];
			--tot1;
			nxt2[++tot2]=ans[i];
			p[ans[i]].push_back(i);
		}
	if (tot2!=0)
	{
		printf("%d\n",-1);
		return 0;
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
	{
		printf("%d ",(int)p[i].size());
		for (int j=0;j<(int)p[i].size();j++)
			printf("%d ",p[i][j]);
		printf("\n");
	}
	return 0;
}