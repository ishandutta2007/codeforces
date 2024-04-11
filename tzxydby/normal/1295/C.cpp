#include<bits/stdc++.h>
using namespace std;
const int N=100005;
char s[N],t[N];
int T,n,m,nxt[N][30];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		scanf("%s",t+1);
		m=strlen(t+1);
		for(int j=0;j<26;j++)
			nxt[n+1][j]=n+1;
		for(int i=n;i>=1;i--)
		{
			for(int j=0;j<26;j++)
			{
				if(s[i]-'a'==j)
					nxt[i][j]=i;
				else
					nxt[i][j]=nxt[i+1][j];
			}
		}
		int ans=1,las=1,flag=0;
		for(int i=1;i<=m;i++)
		{
			int k=t[i]-'a';
			if(nxt[las][k]==n+1)
			{
				if(nxt[1][k]==n+1)
				{
					flag=1;
					break;
				}
				ans++;
				las=nxt[1][k];
			}
			else
			{
				las=nxt[las][k];
			}
			las++;
		}
		if(flag)
			puts("-1");
		else
			printf("%d\n",ans);
	}
	return 0;
}