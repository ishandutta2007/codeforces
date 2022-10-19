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
int os[200005],js[200005],oc,jc,a[200005];
int main()
{
	int t,n,x;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		oc=jc=0;
		for(int i=1;i<=n;i++)
		{
			x=read();
			if(i%2==1)js[++jc]=x;
			else os[++oc]=x;
		}
		sort(os,os+oc+1);
		sort(js,js+jc+1);
		for(int i=1;i<=oc;i++)a[2*i]=os[i];
		for(int i=1;i<=jc;i++)a[2*i-1]=js[i];
		flag=false;
		for(int i=1;i<=n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				flag=true;
				break;
			}
		}
		if(flag==true)printf("NO\n");
		else printf("YES\n");
	} 
	return 0;
}