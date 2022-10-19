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
int a[200005];
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
int lfg(int x)
{
	int l=0,r=100000,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(mid*mid*mid<=x)l=mid+1;
		else r=mid-1;
	}
	return r;
}
signed main()
{
	int t,n,sth,x;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		flag=false;
		for(int i=1;i*i*i<n;i++)
		{
			sth=n-i*i*i;
			x=lfg(sth);
			if(x*x*x==sth)
			{
				flag=true;
				printf("YES\n");
				break;
			}
		}
		if(flag==false)printf("NO\n");
	}
	return 0;
}