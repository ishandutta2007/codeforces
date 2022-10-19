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
int a[500005],pos[500005];
int f[500005];
int n;
void insert(int k,int x)
{
	while(k<=n)
	{
		f[k]+=x;
		k+=((k)&(-k));
	}
}
int query(int k)
{
	int ans=0;
	while(k>=1)
	{
		ans+=f[k];
		k-=((k)&(-k));
	}
	return ans;
}
bool bi(int x,int y)
{
	if(a[x]!=a[y])return a[x]<a[y];
	else return x<y;
}
signed main()
{
	int t,k,ans=0;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),pos[i]=i;
		for(int i=1;i<=n;i++)f[i]=0;
		sort(pos+1,pos+n+1,bi);
		flag=false;
		for(int i=1;i<=n-1;i++)
		{
			if(a[pos[i]]==a[pos[i+1]])
			{
				printf("YES\n");
				flag=true;
				break;
			}
		}
		if(flag==true)continue;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=i-1-query(pos[i]);
			insert(pos[i],1);
		}
		if(ans%2==0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}