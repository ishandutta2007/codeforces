#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int T,n,m,f[405][405],nxt[405][26];
char s[405],t[405];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",s+1,t+1);
		n=(int)strlen(s+1);
		m=(int)strlen(t+1);
		for(int i=0;i<26;i++)nxt[n][i]=n+1;
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;j<26;j++)nxt[i][j]=nxt[i+1][j];
			nxt[i][s[i+1]-'a']=i+1;
		}
		bool flag=0;
		for(int st=1;st<=m;st++)
		{
			for(int i=0;i<=m;i++)
			  for(int j=0;j<=m;j++)
			    f[i][j]=n+1;
			f[0][st-1]=0;
			for(int i=0;i<st;i++)
			for(int j=st-1;j<=m;j++)
			{
				if(f[i][j]==n+1)continue;
				if(i!=st-1)f[i+1][j]=min(f[i+1][j],nxt[f[i][j]][t[i+1]-'a']);
				if(j!=m)f[i][j+1]=min(f[i][j+1],nxt[f[i][j]][t[j+1]-'a']);
			}
			if(f[st-1][m]<=n)
			{
				flag=1;
				break;
			}
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}