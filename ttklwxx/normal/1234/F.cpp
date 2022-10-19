#include<iostream>
#include<cstdio>
#include<cstring>
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
int dp[2000050];
bool cx[25];
char s[1000001]; 
int main()
{
    int len,nown;
    scanf("%s",s+1);
    len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
    	nown=0;
    	for(int j=0;j<20;j++)cx[j]=false;
    	for(int j=i;j<=len;j++)
    	{
    		
    		if(cx[s[j]-'a']==1)break;
    		nown|=(1<<(s[j]-'a'));
    		dp[nown]=j-i+1;
    		cx[s[j]-'a']=1;
		}
	}
	for(int i=0;i<(1<<20);i++)
	{
		for(int j=0;j<20;j++)
		{
			if((i>>j)&1)
			{
				dp[i]=max(dp[i],dp[i^(1<<j)]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<(1<<20);i++)ans=max(dp[i]+dp[((1<<20)-1)^i],ans);
	printf("%d\n",ans);
    return 0;
}