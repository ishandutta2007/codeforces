#include<iostream>
#include<cstdio>
#include<cstring>
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
int a[200005],b[200005];
int ad[200005],as[200005],cnta;
int bd[200005],bs[200005],cntb;
int nexa[200005];
map<int,int>ma; 
int main()
{
	int t,n,sl,l,r;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		for(int i=1;i<=n;i++)
		{
			b[i]=read();
		}
		cnta=0;
		cntb=0;
		for(int i=1;i<=n;i++)
		{
			if(i==1||a[i]!=a[i-1])
			{
				ad[++cnta]=a[i];
				as[cnta]=1;
			}
			else as[cnta]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(i==1||b[i]!=b[i-1])
			{
				bd[++cntb]=b[i];
				bs[cntb]=1;
			}
			else bs[cntb]++;
		}
		ma.clear();
		for(int i=cnta;i>=1;i--)
		{
			nexa[i]=ma[ad[i]];
			ma[ad[i]]=i;
		}
		int now=1;
		bool flag=true;
		for(int i=1;i<=cnta;i++)
		{
			if(now>cntb)
			{
				flag=false;
				break;
			}
			if(ad[i]!=bd[now])
			{
				if(nexa[i]==0)
				{
					flag=false;
					break;
				}
				as[nexa[i]]+=as[i];
				continue;
			}
			if(as[i]>=bs[now])
			{
				if(as[i]==bs[now])
				{
					now++;
					continue;
				}
				if(nexa[i]==0)
				{
					flag=false;
					break;
				}
				as[i]-=bs[now];
				as[nexa[i]]+=as[i];
				now++;
				continue;
			}
			if(nexa[i]==0)
			{
				flag=false;
				break;
			}
			as[nexa[i]]+=as[i];
			continue;
		}
		if(flag==false)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}