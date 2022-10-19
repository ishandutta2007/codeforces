#include<bits/stdc++.h>
using namespace std;
const int N=55;
int a[N];
long long dp[N][10];
int main()
{
	int n=0;
	while(1)
	{
		char c=getchar();
		if(c=='\n')
			break;
		a[++n]=c-'0';
	}
	for(int i=0;i<=9;i++)
		dp[1][i]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=9;j++)
		{
			if(j*2-1-a[i]>=0&&j*2-1-a[i]<=9)
				dp[i][j]+=dp[i-1][j*2-1-a[i]];
			if(j*2-a[i]>=0&&j*2-a[i]<=9)
				dp[i][j]+=dp[i-1][j*2-a[i]];
			if(j*2+1-a[i]>=0&&j*2+1-a[i]<=9)
				dp[i][j]+=dp[i-1][j*2+1-a[i]];
		}
	}
	long long sum=0;
	for(int i=0;i<=9;i++)
		sum+=dp[n][i];
	int i,d=a[1];
	for(i=2;i<=n;i++)
	{
		if(abs(a[i]-d)<=1)
			d=a[i];
		else
			break;
	}
	if(i==n+1)
		sum--;
	printf("%I64d\n",sum);
	return 0;
}