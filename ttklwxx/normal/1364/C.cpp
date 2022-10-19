#include<iostream>
#include<cstdio>
#include<vector> 
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
bool cx[1000005];
vector<int>v;
int main()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		cx[a[i]]=true;
		if(a[i]>i)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=0;i<=1000000;i++)
	{
		if(!cx[i])
		{
			v.push_back(i);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i==1||a[i]==a[i-1])printf("%d ",v[cnt++]);
		else printf("%d ",a[i-1]);
	}
	return 0;
}