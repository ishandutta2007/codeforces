#include<iostream>
#include<cstdio>
#include<map>
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
map<int,int>ma;
char s[1000005];
int main()
{
	int t,n,ans;
	long long tans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		ma.clear();
		scanf("%s",s+1);
		n=strlen(s+1);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='+')ans++;
			else if(s[i]=='-')ans--;
		}
		for(int i=n;i>=1;i--)
		{
			ma[ans]=i;
			if(s[i]=='+')ans--;
			else if(s[i]=='-')ans++;
		}
		tans=0;
		for(int i=0;i<=n+1;i++)
		{
			if(ma[-(i+1)]==0)
			{
				tans+=n;
				break;
			}
			tans+=ma[-(i+1)];
		}
		printf("%lld\n",tans);
	}
	return 0;
}