#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll k,f[105][105][26],s[105][105],ans;
char t[105];
int main()
{
	scanf("%d%I64d",&n,&k);
	scanf("%s",t+1);
	for(int i=1;i<=n;i++)
	{
		f[i][1][t[i]-'a']=1;
		for(int j=1;j<=i;j++)
		{
			for(int c=0;c<26;c++)
			{
				if(c+'a'==t[i])f[i][j][c]+=s[i-1][j-1];
				else f[i][j][c]+=f[i-1][j][c];
				if(f[i][j][c]>k)f[i][j][c]=k;
				s[i][j]+=f[i][j][c];
			}
			if(s[i][j]>k)s[i][j]=k;
		}
	}
	s[n][0]=1;
	for(int i=n;i>=0;i--)
	{
		if(s[n][i]>k)
		{
			ans+=k*(n-i);
			k=0;
			break;
		}
		ans+=s[n][i]*(n-i);
		k-=s[n][i];
	}
	if(k)
	{
		printf("-1\n");
		return 0;
	}
	printf("%I64d\n",ans);
	return 0;
}