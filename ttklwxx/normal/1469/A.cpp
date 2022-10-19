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
char s[200005];
int main()
{
	int t,n,x,sth,ws;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		x=0;
		sth=0;
		ws=0;
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='(')sth++;
			else if(s[i]==')')sth--;
			if(s[i]=='?')ws++;
		}
		if((sth+ws)%2!=0)
		{
			printf("No\n");
			continue;
		}
		sth=(ws-sth)/2;
		if(sth>ws)
		{
			printf("No\n");
			continue;
		}
		x=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='?')
			{
				if(sth>0)s[i]='(',sth--;
				else s[i]=')';
			}
			if(s[i]=='(')x++;
			else x--;
			if(x<0)
			{
				flag=true;
				printf("No\n");
				break;
			}
		}
		if(flag==false)printf("Yes\n");
	}
	return 0;
}