#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
char s[N];int n,Q,nxt[N][26],len[4],vis[N],d[256][256][256];char t[4][256],tmp[10];
int main()
{
	scanf("%d%d%s",&n,&Q,s+1);memset(nxt,-1,sizeof(nxt));
	for(int i=0;i<26;i++)
		for(int j=0;j<=n+1;j++)
			nxt[j][i]=n+1;
	for(int i=1;i<=n;i++)
	{
		int x=s[i]-'a';
		for(int j=i-1;~j;j--)
			if(s[i]!=s[j])nxt[j][x]=i;
			else {nxt[j][x]=i;break;}
	}
	int ans=0;
	while(Q--)
	{
		int x;
		scanf("%s%d",tmp,&x);
		if(tmp[0]=='+')
		{
			scanf("%s",tmp);
			len[x]++;t[x][len[x]]=tmp[0];
			if(x==1)
			{
				int i=len[x];
				for(int j=0;j<=len[2];j++)for(int k=0;k<=len[3];k++)
				{
					d[i][j][k]=n+1;
					if(i)d[i][j][k]=min(d[i][j][k],nxt[d[i-1][j][k]][t[1][i]-'a']);
					if(j)d[i][j][k]=min(d[i][j][k],nxt[d[i][j-1][k]][t[2][j]-'a']);
					if(k)d[i][j][k]=min(d[i][j][k],nxt[d[i][j][k-1]][t[3][k]-'a']);
				}
			}else if(x==2)
			{
				int j=len[x];
				for(int i=0;i<=len[1];i++)for(int k=0;k<=len[3];k++)
				{
					d[i][j][k]=n+1;
					if(i)d[i][j][k]=min(d[i][j][k],nxt[d[i-1][j][k]][t[1][i]-'a']);
					if(j)d[i][j][k]=min(d[i][j][k],nxt[d[i][j-1][k]][t[2][j]-'a']);
					if(k)d[i][j][k]=min(d[i][j][k],nxt[d[i][j][k-1]][t[3][k]-'a']);
				}
			}else
			{
				int k=len[x];
				for(int i=0;i<=len[1];i++)for(int j=0;j<=len[2];j++)
				{
					d[i][j][k]=n+1;
					if(i)d[i][j][k]=min(d[i][j][k],nxt[d[i-1][j][k]][t[1][i]-'a']);
					if(j)d[i][j][k]=min(d[i][j][k],nxt[d[i][j-1][k]][t[2][j]-'a']);
					if(k)d[i][j][k]=min(d[i][j][k],nxt[d[i][j][k-1]][t[3][k]-'a']);
				}
			}
		}else len[x]--;
		if(d[len[1]][len[2]][len[3]]<=n)puts("YES");else puts("NO");
	}
}