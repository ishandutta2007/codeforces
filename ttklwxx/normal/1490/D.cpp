#include<iostream>
#include<cstdio>
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
int a[200005],dep[200005];
void dfs(int l,int r,int d)
{
	if(l>r)return;
	if(l==r)
	{
		dep[l]=d;
		return;
	}
	int mpos=l;
	for(int i=l+1;i<=r;i++)if(a[i]>a[mpos])mpos=i;
	dep[mpos]=d;
	dfs(l,mpos-1,d+1);
	dfs(mpos+1,r,d+1);
}
signed main()
{
	int t,n,sth,x;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		dfs(1,n,0);
		for(int i=1;i<=n;i++)printf("%d ",dep[i]);
		printf("\n"); 
	}
	return 0;
}