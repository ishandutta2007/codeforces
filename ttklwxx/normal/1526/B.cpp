#include<iostream>
#include<cstdio>
#include<algorithm> 
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
int a[200005];
int main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		if(n>=2000)
		{
			printf("YES\n");
			continue;
		}
		flag=false;
		while(n>=0)
		{
			if(n%11==0)
			{
				flag=true;
				break;
			}
			n-=111;
		}
		if(flag==true)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}