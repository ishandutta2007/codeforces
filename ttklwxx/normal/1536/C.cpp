#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int dp[500005];
char s[500005];
map<double,int>ma;
int main()
{
	int t,n,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ma.clear();
		scanf("%s",s+1);
		k=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='K')k++;
			dp[i]=dp[ma[(double)k/i]]+1;
			ma[(double)k/i]=i;
			printf("%d ",dp[i]);
		}
		printf("\n");
	}
	return 0;
}