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
int qs[1000001],las[1000001];
signed main()
{
	int n,x1,x,l,q;
	bool flag;
	n=read();
	for(int i=1;i<=n;i++)
	{
		x1=1000000000;
		l=read();
		flag=true;
		for(int j=1;j<=l;j++)
		{
			x=read();
			if(j==1)q=x;
			if(x>x1)
			{
				flag=false;
			}
			x1=x;
		}
		if(flag==true)qs[q]++,las[x]++;
	}
	x=0;
	int ans=0;
	for(int i=0;i<=1000000;i++)
	{
		x+=qs[i];
		ans+=x*las[i];
	}
	printf("%lld\n",n*n-ans);
	return 0;
}