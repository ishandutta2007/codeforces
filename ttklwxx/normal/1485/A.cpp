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
int main()
{
	int t,a,b,ans=0,nans=0,ta;
	bool flag=false;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a=read();
		b=read();
		ans=0;
		flag=false;
		if(b==1)
		{
			b=2;
			flag=true;
		}
		ta=a;
		while(a!=0)
		{
			a=a/b;
			ans++;
		}
		a=ta;
		for(int i=b+1;i<=b+ans;i++)
		{
			nans=i-b;
			ta=a;
			while(a!=0)
			{
				a=a/i;
				nans++;
			}
			ans=min(ans,nans);
			a=ta;
		}
		if(flag==true)ans++;
		printf("%d\n",ans);
	} 
	return 0;
}