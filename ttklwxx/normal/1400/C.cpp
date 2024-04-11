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
char s[200001],ans[200001];
int main()
{
	int t,n,x;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		x=read();
		for(int i=1;i<=n;i++)ans[i]='1';
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')continue;
			if(i-x>=1)ans[i-x]='0';
			if(i+x<=n)ans[i+x]='0';
		}
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				if(i-x>=1&&ans[i-x]=='1')continue;
				if(i+x<=n&&ans[i+x]=='1')continue;
				flag=true;
				break;
		    }
		}
		if(flag==true)printf("-1\n");
		else
		{
			for(int i=1;i<=n;i++)printf("%c",ans[i]);
			printf("\n");
		}
	}
	return 0;
}