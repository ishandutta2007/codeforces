#include<iostream>
#include<cstdio>
#include<map>
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
int a[200005],qz[200005];
map<int,bool>ma;
void dfs(int l,int r)
{
	if(l>r)return;
	ma[qz[r]-qz[l-1]]=true;
	if(a[l]==a[r])return;
	int mid=(a[l]+a[r])/2;
	int ll=l,rr=r,tmid;
	while(ll<=rr)
	{
		tmid=(ll+rr)>>1;
		if(a[tmid]<=mid)ll=tmid+1;
		else rr=tmid-1;
	}
	dfs(l,rr);
	dfs(ll,r);
}
signed main()
{
	int t,n,q,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		q=read();
		qz[0]=0;
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)qz[i]=qz[i-1]+a[i];
		ma.clear();
		dfs(1,n);
		for(int i=1;i<=q;i++)
		{
			x=read();
			if(ma[x])printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}