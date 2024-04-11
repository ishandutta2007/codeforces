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
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		if(s[n]%2==0)printf("0\n");
		else
		{
			if(s[1]%2==0)
			{
				printf("1\n");
				continue;
			}
			flag=false;
			for(int i=1;i<=n;i++)if((s[i]-'0')%2==0)
			{
				printf("2\n");
				flag=true;
				break;
			}
			if(flag==false)printf("-1\n");
		}
	}
	return 0;
}