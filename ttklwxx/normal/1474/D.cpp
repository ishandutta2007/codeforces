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
int a[300005],p[300005],h[3000005];
bool check(int a,int b,int c,int d)
{
	if(b<a)return false;
	b=b-a;
	if(c<b)return false;
	c=c-b;
	if(d<c)return false;
	d=d-c;
	if(d!=0)return false;
	return true;
}
int main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		p[0]=0;
		for(int i=1;i<=n;i++)
		{
			if(p[i-1]==-1)p[i]=-1;
			else if(a[i]<p[i-1])p[i]=-1;
			else p[i]=a[i]-p[i-1];
		}
		h[n+1]=0;
		for(int i=n;i>=1;i--)
		{
			if(h[i+1]==-1)h[i]=-1;
			else if(a[i]<h[i+1])h[i]=-1;
			else h[i]=a[i]-h[i+1];
		}
		flag=false;
		if(p[n]==0)flag=true;
		for(int i=1;i<=n-1;i++)
		{
			if(p[i-1]==-1||h[i+2]==-1)continue;
			if(check(p[i-1],a[i+1],a[i],h[i+2])==true)
			{
				flag=true;
				break;
			}
		}
		if(flag==true)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}