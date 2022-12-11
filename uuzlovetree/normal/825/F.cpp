#include<bits/stdc++.h>
#define maxn 8005
using namespace std;
const int inf = 1000000000;
int get_dig(int x)
{
	if(x<=9)return 1;
	else if(x<=99)return 2;
	else if(x<=999)return 3;
	else return 4;
}
int n;
char s[maxn],t[maxn];
int dig[maxn],dp[maxn];
int w[maxn][maxn],nxt[maxn];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)dig[i]=get_dig(i);
	for(int i=1;i<=n;++i)
	{
		memset(t,0,sizeof(t));
		memset(nxt,0,sizeof(nxt));
		for(int j=i;j<=n;++j)t[j-i+1]=s[j];
		int len=n-i+1;
		w[i][1]=2;
		for(int j=2;j<=len;++j)
		{
			nxt[j]=nxt[j-1];
			while(nxt[j]&&t[j]!=t[nxt[j]+1])nxt[j]=nxt[nxt[j]];
			nxt[j]+=(t[j]==t[nxt[j]+1]);
			if(j%(j-nxt[j])==0)
			{
				w[i][j]=dig[j/(j-nxt[j])]+(j-nxt[j]);
			}
			else w[i][j]=j+1;
		}
	}
	dp[0]=0;
	for(int i=1;i<=n;++i)dp[i]=inf;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
		{
			dp[i]=min(dp[i],dp[j-1]+w[j][i-j+1]);
		}
	}
	printf("%d\n",dp[n]);
}