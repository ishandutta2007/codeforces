#include<bits/stdc++.h>
using namespace std;
const int N=5005,inf=1e9;
int n,m,a,b,c,d,ps[N][26],pt[N][26],dp[N][N];
char s[N],t[N];
inline void chmin(int &a,int b){if(a>b)a=b;}
int main()
{
	scanf("%d%d%d%d%s%s",&a,&b,&c,&d,s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
			ps[i][j]=ps[i-1][j];
		ps[i][s[i]-'a']=i;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<26;j++)
			pt[i][j]=pt[i-1][j];
		pt[i][t[i]-'a']=i;
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			dp[i][j]=inf;
	dp[0][0]=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(j) chmin(dp[i][j],dp[i][j-1]+a);
			if(i) chmin(dp[i][j],dp[i-1][j]+b);
			if(i&&j) chmin(dp[i][j],dp[i-1][j-1]+(s[i]==t[j]?0:c));
			if(i&&j)
			{
				int x=ps[i-1][t[j]-'a'],y=pt[j-1][s[i]-'a'];
				if(x&&y) chmin(dp[i][j],dp[x-1][y-1]+(i-x-1)*b+(j-y-1)*a+d);
			}
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}