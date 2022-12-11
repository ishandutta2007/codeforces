#include<bits/stdc++.h>
using namespace std;
int n,a[505];
bool has[505][505];
int dp[505],stk[505];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		int top=0;
		for(int j=i;j<=n;++j)
		{
			stk[++top]=a[j];
			while(top>1)
			{
				int x=stk[top],y=stk[top-1];
				if(x==y)--top,stk[top]++;
				else break;
			}
			if(top==1)has[i][j]=1;
		}
	}
	for(int i=1;i<=n;++i)
	{
		dp[i]=i;
		for(int j=1;j<=i;++j)if(has[j][i])dp[i]=min(dp[i],dp[j-1]+1);
	}
	printf("%d\n",dp[n]);
}