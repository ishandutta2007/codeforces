#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
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
int f[200001];
char s[200001];
int main()
{
    int n,sl=0,ans=1;
    scanf("%s",s+1);
    n=strlen(s+1);
    f[0]=1;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=n;i++)f[i]=(f[i-1]+f[i-2])%mod;
    for(int i=1;i<=n;i++)
    {
    	if(s[i]=='m'||s[i]=='w')
    	{
    		printf("0\n");
    		return 0;
		}
    	if(s[i]!='n'&&s[i]!='u')
    	{
    		ans=1LL*ans*f[sl]%mod;
    		sl=0;
		}
		else if(s[i]!=s[i-1])
		{
			ans=1LL*ans*f[sl]%mod;
    		sl=1;
		}
		else sl++;
	}
	ans=1LL*ans*f[sl]%mod;
	printf("%d\n",ans);
	return 0;
}