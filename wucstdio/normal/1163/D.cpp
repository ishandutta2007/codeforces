#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
char s[1005],s1[1005],s2[1005];
int n,l1,l2,f[1005][55][55],nxt1[1005],nxt2[1005];
int to1[55][26],to2[55][26];
int main()
{
	scanf("%s%s%s",s+1,s1+1,s2+1);
	n=strlen(s+1);
	l1=strlen(s1+1);
	l2=strlen(s2+1);
	for(int i=1;i<l1;i++)
	{
		int j=nxt1[i];
		while(j&&s1[i+1]!=s1[j+1])j=nxt1[j];
		if(s1[i+1]==s1[j+1])nxt1[i+1]=j+1;
		else nxt1[i+1]=0;
	}
	for(int i=1;i<l2;i++)
	{
		int j=nxt2[i];
		while(j&&s2[i+1]!=s2[j+1])j=nxt2[j];
		if(s2[i+1]==s2[j+1])nxt2[i+1]=j+1;
		else nxt2[i+1]=0;
	}
	for(int i=0;i<=l1;i++)
	{
		for(int c=0;c<26;c++)
		{
			int j=i;
			while(j&&s1[j+1]!=c+'a')j=nxt1[j];
			to1[i][c]=(s1[j+1]==c+'a')?j+1:0;
		}
	}
	for(int i=0;i<=l2;i++)
	{
		for(int c=0;c<26;c++)
		{
			int j=i;
			while(j&&s2[j+1]!=c+'a')j=nxt2[j];
			to2[i][c]=(s2[j+1]==c+'a')?j+1:0;
		}
	}
	for(int i=0;i<=n;i++)
	  for(int j=0;j<=l1;j++)
		for(int k=0;k<=l2;k++)
		  f[i][j][k]=-1000000000;
	f[0][0][0]=0;
	for(int i=0;i<n;i++)
	for(int x=0;x<=l1;x++)
	for(int y=0;y<=l2;y++)
	{
		if(f[i][x][y]==-1000000000)continue;
		if(s[i+1]=='*')
		for(int c=0;c<26;c++)
		{
			int xx=to1[x][c],yy=to2[y][c];
			if(xx==l1&&yy==l2)f[i+1][xx][yy]=max(f[i+1][xx][yy],f[i][x][y]);
			else if(xx==l1)f[i+1][xx][yy]=max(f[i+1][xx][yy],f[i][x][y]+1);
			else if(yy==l2)f[i+1][xx][yy]=max(f[i+1][xx][yy],f[i][x][y]-1);
			else f[i+1][xx][yy]=max(f[i+1][xx][yy],f[i][x][y]);
		}
		else
		{
			int c=s[i+1]-'a';
			int xx=to1[x][c],yy=to2[y][c];
			if(xx==l1&&yy==l2)f[i+1][xx][yy]=max(f[i+1][xx][yy],f[i][x][y]);
			else if(xx==l1)f[i+1][xx][yy]=max(f[i+1][xx][yy],f[i][x][y]+1);
			else if(yy==l2)f[i+1][xx][yy]=max(f[i+1][xx][yy],f[i][x][y]-1);
			else f[i+1][xx][yy]=max(f[i+1][xx][yy],f[i][x][y]);
		}
	}
	int maxx=-1000000000;
	for(int i=0;i<=l1;i++)
	  for(int j=0;j<=l2;j++)
	    maxx=max(maxx,f[n][i][j]);
	printf("%d\n",maxx);
	return 0;
}