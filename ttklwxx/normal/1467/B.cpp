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
int a[300005];
int t,n,ans,mans,nans,sth;
bool check(int x)
{
	if(x<=1)return false;
	if(x>=n)return false;
	if(a[x]>a[x-1]&&a[x]>a[x+1])return true;
	if(a[x]<a[x-1]&&a[x]<a[x+1])return true;
	return false;
}
int main()
{
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ans=0;
		for(int i=2;i<=n-1;i++)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1])ans++;
			if(a[i]<a[i-1]&&a[i]<a[i+1])ans++;
		}
		mans=ans;
		for(int i=1;i<=n;i++)
		{
			if(i!=1)
			{
				nans=ans;
				if(check(i-1))nans--;
				if(check(i))nans--;
				if(check(i+1))nans--;
				sth=a[i];
				a[i]=a[i-1];
				if(check(i))nans++;
				if(check(i+1))nans++;
				mans=min(mans,nans);
				a[i]=sth;
			}
			if(i!=n)
			{
				nans=ans;
				if(check(i-1))nans--;
				if(check(i))nans--;
				if(check(i+1))nans--;
				sth=a[i];
				a[i]=a[i+1];
				if(check(i))nans++;
				if(check(i-1))nans++;
				mans=min(mans,nans);
				a[i]=sth;
			}
		}
		printf("%d\n",mans); 
	}
	return 0;
}