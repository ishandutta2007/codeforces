#include<iostream>
#include<cstdio>
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
char s[10005];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		for(int i=2;i<=n;i++)
		{
			if(s[i]=='?'&&s[i-1]!='?')
			{
				s[i]='R'+'B'-s[i-1];
			}
		}
		for(int i=n-1;i>=1;i--)
		{
			if(s[i]=='?'&&s[i+1]!='?')
			{
				s[i]='R'+'B'-s[i+1];
			}
		}
		if(s[1]=='?')
		{
			for(int i=1;i<=n;i++)
			{
				if(i%2==1)s[i]='R';
				else s[i]='B';
			}
		}
		printf("%s\n",s+1);
	}
	return 0;
}