#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
int n,a[15],cho[15],s;
bool yes;
void check()
{
	if(yes)return;
	int res=0,cnt=0;
	for(int i=1;i<=n;++i)if(cho[i])cnt++,res+=a[i];
	if(cnt==n||cnt==0)return;
	if(res!=s-res)
	{
		yes=1;
		printf("%d\n",cnt);
		for(int i=1;i<=n;++i)if(cho[i])printf("%d ",i);
	}
}
void dfs(int x)
{
	if(x==n+1)
	{
		check();
		return;
	}
	cho[x]=1;
	dfs(x+1);
	cho[x]=0;
	dfs(x+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),s+=a[i];
	dfs(1);
	if(!yes)puts("-1");
	return 0;
}