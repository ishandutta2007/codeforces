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
char str[1001];
int main()
{
    int t,n,ans=0;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	scanf("%s",str+1);
		n=strlen(str+1);
		ans=0;
		for(int j=1;j<=n;j++)
		{
			if(str[j]=='0')ans++;
		}
		for(int j=1;j<=n;j++)
		{
			if(str[j]=='0')ans--;
			else break;
		}
		for(int j=n;j>=1;j--)
		{
			if(str[j]=='0')ans--;
			else break;
		}
		printf("%d\n",max(ans,0));
	} 
    return 0;
}