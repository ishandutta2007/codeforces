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
using namespace std;
int n,l,r,c[999999],t,x;
int C(int x)
{
	t=x;
	for(int i=n;i;i--)
		if(c[i])
			x-=max(1,c[i]-(--t));
	return x>=0&&t>=0;
}
int main()
{
	int t;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
			c[i]=0;
		c[0]=l=1,r=n;
		for(int i=1;i<n;i++)
			cin>>x,c[x]++;
		sort(c,c+n+1);
		while(l<r)
			C((l+r)/2)?r=(l+r)/2:l=(l+r)/2+1;
		cout<<l<<'\n';
	}
}