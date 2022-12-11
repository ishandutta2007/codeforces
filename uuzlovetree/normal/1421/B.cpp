#include<bits/stdc++.h>
#define maxn 205
using namespace std;
int T,n;
char s[maxn][maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		if(s[1][2]=='0'&&s[2][1]=='0')
		{
			if(s[n][n-1]=='1'&&s[n-1][n]=='1')
			{
				printf("0\n");
			}
			else if(s[n][n-1]=='0'&&s[n-1][n]=='1')
			{
				printf("1\n");
				printf("%d %d\n",n,n-1);
			}
			else if(s[n][n-1]=='1'&&s[n-1][n]=='0')
			{
				printf("1\n");
				printf("%d %d\n",n-1,n);
			}
			else
			{
				printf("2\n");
				printf("%d %d\n",n,n-1);
				printf("%d %d\n",n-1,n);
			}
		}
		else if(s[1][2]=='1'&&s[2][1]=='0')
		{
			if(s[n][n-1]=='1'&&s[n-1][n]=='1')
			{
				printf("1\n");
				printf("1 2\n");
			}
			else if(s[n][n-1]=='0'&&s[n-1][n]=='1')
			{
				printf("2\n");
				printf("%d %d\n",2,1);
				printf("%d %d\n",n-1,n);
			}
			else if(s[n][n-1]=='1'&&s[n-1][n]=='0')
			{
				printf("2\n");
				printf("%d %d\n",2,1);
				printf("%d %d\n",n,n-1);
			}
			else
			{
				printf("1\n");
				printf("%d %d\n",2,1);
			}
		}
		else if(s[1][2]=='0'&&s[2][1]=='1')
		{
			if(s[n][n-1]=='1'&&s[n-1][n]=='1')
			{
				printf("1\n");
				printf("2 1\n");
			}
			else if(s[n][n-1]=='0'&&s[n-1][n]=='1')
			{
				printf("2\n");
				printf("1 2\n");
				printf("%d %d\n",n-1,n);
			}
			else if(s[n][n-1]=='1'&&s[n-1][n]=='0')
			{
				printf("2\n");
				printf("1 2\n");
				printf("%d %d\n",n,n-1);
			}
			else
			{
				printf("1\n");
				printf("1 2\n");
			}
		}
		else
		{
			if(s[n][n-1]=='1'&&s[n-1][n]=='1')
			{
				printf("2\n");
				printf("%d %d\n",n,n-1);
				printf("%d %d\n",n-1,n);
			}
			else if(s[n][n-1]=='0'&&s[n-1][n]=='1')
			{
				printf("1\n");
				printf("%d %d\n",n-1,n);
			}
			else if(s[n][n-1]=='1'&&s[n-1][n]=='0')
			{
				printf("1\n");
				printf("%d %d\n",n,n-1);
			}
			else
			{
				printf("0\n");
			}
		}
	}
}