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
int to[100000*305],a[100005],n,ans;
int main()
{
	n=read(); 
	for(int i=1;i<=n;i++)a[i]=read();
	for(int k=-100;k<=100;k++)
	{
		for(int i=1;i<=n;i++)
		{
			to[k*i-a[i]+100000*101]++;
			ans=max(ans,to[k*i-a[i]+100000*101]);
		}
		for(int i=1;i<=n;i++)to[k*i-a[i]+100000*101]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=min(n,i+1000);j++)
		{
			if((a[j]-a[i])%(j-i)==0)
			{
				to[(a[j]-a[i])/(j-i)+100000]++;
				ans=max(ans,to[(a[j]-a[i])/(j-i)+100000]+1);
			}
		}
		for(int j=i+1;j<=min(n,i+1000);j++)
		{
			if((a[j]-a[i])%(j-i)==0)
			{
				to[(a[j]-a[i])/(j-i)+100000]=0;
			}
		}
	}
	printf("%d",n-ans);
}