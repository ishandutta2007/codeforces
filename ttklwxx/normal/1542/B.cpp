#include<iostream>
#include<cstdio>
#define int long long
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
signed main()
{
	int t,n,a,b,sth;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		a=read();
		b=read();
		sth=1;
		flag=false;
		if(a==1)
		{
			if((n-1)%b==0)printf("Yes\n");
			else printf("No\n");
			continue;
		}
		while(n>=sth)
		{
			if((n-sth)%b==0)
			{
				flag=true;
				break;
			}
			sth*=a;
		}
		if(flag==true)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}