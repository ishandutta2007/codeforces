#include<iostream>
#include<cstdio>
#include<cmath>
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
char s[114514];
int sl[114514];
int main()
{
	int t,n,q,l,r;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		q=read();
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')sl[i]=sl[i-1]+1;
			else sl[i]=sl[i-1];
		}
		for(int i=1;i<=q;i++)
		{
			l=read();
			r=read();
			if(s[l]=='0'&&sl[l-1]!=l-1)
			{
				printf("YES\n");
				continue;
			}
			if(s[l]=='1'&&sl[l-1]!=0)
			{
				printf("YES\n");
				continue;
			}
			if(s[r]=='0'&&sl[n]-sl[r]!=n-r)
			{
				printf("YES\n");
				continue;
			}
			if(s[r]=='1'&&sl[n]-sl[r]!=0)
			{
				printf("YES\n");
				continue;
			}
			printf("NO\n");
		}
	}
	return 0;
}