//Chapter II: Futures Trading
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
int a[200005];
bool check(int n,int x)
{
	int l=1,r=n;
	while(l<=r)
	{
		if(a[l]==a[r])
		{
			l++;
			r--;
			continue;
		}
		if(a[l]==x)l++;
		else if(a[r]==x)r--;
		else return false; 
	}
	return true;
}
int main()
{
	int t,n,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		x=-1;
		y=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[n+1-i])
			{
				x=a[i];
				y=a[n+1-i];
				break;
			}
		}
		if(x==-1)
		{
			printf("YES\n");
			continue;
		}
		if(check(n,x)==true||check(n,y)==true)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}