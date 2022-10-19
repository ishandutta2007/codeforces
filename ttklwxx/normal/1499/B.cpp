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
	int t,n,x;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1); 
		flag=false;
		for(int i=0;i<=n;i++)
		{
			x=-1;
			flag=false;
			for(int j=1;j<=i;j++)
			{
				if(s[j]=='0')continue;
				if(j-x<=1)
				{
					flag=true;
					break;
				}
				x=j;
			}
			if(flag==true)continue;
			for(int j=i+1;j<=n;j++)
			{
				if(s[j]=='1')continue;
				if(j-x<=1)
				{
					flag=true;
					break;
				}
				x=j;
			}
			if(flag==false)
			{
				printf("YES\n");
				break;
			}
		}
		if(flag==true)printf("NO\n");
	} 
	return 0;
}