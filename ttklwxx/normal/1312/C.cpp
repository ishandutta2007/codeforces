#include<iostream>
#include<cstdio>
#include<algorithm>
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
bool vis[200005];
signed main()
{
	int t,n,k,sl;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=0;i<=1000;i++)vis[i]=false;
		flag=false; 
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)continue;
			sl=0;
			while(a[i]!=0)
			{
				if(a[i]%k==0)
				{
					a[i]/=k;
					sl++;
					continue;
				}
				if(a[i]%k>1)
				{
					flag=true;
					printf("NO\n");
					break;
				}
				if(vis[sl]==true)
				{
					flag=true;
					printf("NO\n");
					break;
				}
				vis[sl]=true;
				sl++;
				a[i]/=k;
			}
			if(flag==true)break;
		}
		if(flag==false)printf("YES\n");
	} 
	return 0;
}