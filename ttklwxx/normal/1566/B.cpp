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
char str[200005];
int main()
{
	int t,n,l,r;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",str+1);
		n=strlen(str+1);
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='0')
			{
				flag=true;
				break;
			}
		}
		if(flag==false)
		{
			printf("0\n");
			continue; 
		}
		l=n+1;
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='0')
			{
				l=i;
				break;
			}
		}
		r=0;
		for(int i=n;i>=1;i--)
		{
			if(str[i]=='0')
			{
				r=i;
				break;
			}
		}
		flag=false;
		for(int i=l;i<=r;i++)
		{
			if(str[i]=='1')
			{
				flag=true;
			}
		}
		if(flag==false)printf("1\n");
		else printf("2\n");
	}
	return 0;
}