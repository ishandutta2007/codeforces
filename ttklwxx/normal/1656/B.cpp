#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
int a[200005],pos[200005];
map<int,int>ma;
int main()
{
	int t,n,k;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		ma.clear();
		for(int i=1;i<=n;i++)a[i]=read(),ma[a[i]]=1;
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(ma[a[i]+k]==1)
			{
				flag=true;
				break;
			}
		}
		if(flag==false)printf("NO\n");
		else printf("YES\n");
	} 
	return 0;
}