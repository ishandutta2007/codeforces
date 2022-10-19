#include<iostream>
#include<cstdio>
#include<map>
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
map<int,int>ma;
int b[2001];
signed main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ma.clear();
		for(int i=1;i<=n;i++)b[i]=read();
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(ma[b[i]]>0)
			{
				printf("YES\n");
				flag=true;
				break;
			}
			ma[b[i]]++;
		}
		if(flag==false)printf("NO\n");
	} 
	return 0;
}