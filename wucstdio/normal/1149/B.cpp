#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,q,len[5];
char s[100005],t[5][255];
int nxt[100005][26],f[255][255][255];
inline int read()
{
	char c=getchar();
	while(c!='+'&&c!='-')c=getchar();
	return c=='+';
}
int main()
{
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(int c=0;c<26;c++)
	{
		nxt[n][c]=n+1;
		nxt[n+1][c]=n+1;
		for(int i=n;i>=1;i--)
		{
			if(s[i]==c+'a')nxt[i-1][c]=i;
			else nxt[i-1][c]=nxt[i][c];
		}
	}
	for(int i=0;i<=250;i++)
	  for(int j=0;j<=250;j++)
	    for(int k=0;k<=250;k++)
	      f[i][j][k]=n+1;
	f[0][0][0]=0;
	while(q--)
	{
		int type=read(),x;
		char c;
		if(type==1)
		{
			scanf("%d",&x);
			c=getchar();
			while(c>'z'||c<'a')c=getchar();
			t[x][++len[x]]=c;
			if(x==1)
			{
				for(int i=0;i<=len[2];i++)
				for(int j=0;j<=len[3];j++)
				{
					f[len[1]][i][j]=nxt[f[len[1]-1][i][j]][c-'a'];
					if(i)f[len[1]][i][j]=min(f[len[1]][i][j],nxt[f[len[1]][i-1][j]][t[2][i]-'a']);
					if(j)f[len[1]][i][j]=min(f[len[1]][i][j],nxt[f[len[1]][i][j-1]][t[3][j]-'a']);
				}
			}
			if(x==2)
			{
				for(int i=0;i<=len[1];i++)
				for(int j=0;j<=len[3];j++)
				{
					f[i][len[2]][j]=nxt[f[i][len[2]-1][j]][c-'a'];
					if(i)f[i][len[2]][j]=min(f[i][len[2]][j],nxt[f[i-1][len[2]][j]][t[1][i]-'a']);
					if(j)f[i][len[2]][j]=min(f[i][len[2]][j],nxt[f[i][len[2]][j-1]][t[3][j]-'a']);
				}
			}
			if(x==3)
			{
				for(int i=0;i<=len[1];i++)
				for(int j=0;j<=len[2];j++)
				{
					f[i][j][len[3]]=nxt[f[i][j][len[3]-1]][c-'a'];
					if(i)f[i][j][len[3]]=min(f[i][j][len[3]],nxt[f[i-1][j][len[3]]][t[1][i]-'a']);
					if(j)f[i][j][len[3]]=min(f[i][j][len[3]],nxt[f[i][j-1][len[3]]][t[2][j]-'a']);
				}
			}
		}
		else
		{
			scanf("%d",&x);
			len[x]--;
		}
		if(f[len[1]][len[2]][len[3]]>n)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}