#include<iostream>
#include<cstdio>
#include<vector> 
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
int ans[300001],a[300001],n;
bool vis[300001];
vector<int>vec[300001];
void dfs(int i)
{   
    if(i-a[i]>0)ans[i]=min(ans[i],ans[i-a[i]]+1);
    if(i+a[i]<=n)ans[i]=min(ans[i],ans[i+a[i]]+1);
    int siz=vec[i].size();
    for(int j=0;j<siz;j++)
    {
    	if(ans[vec[i][j]]>ans[i]+1)
    	{
    		dfs(vec[i][j]);
		}
	}
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		ans[i]=1000000000;
		vec[0].push_back(i);
		if(i+a[i]<=n)vec[i+a[i]].push_back(i);
		if(i-a[i]>=1)vec[i-a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(i-a[i]>0&&a[i-a[i]]%2!=a[i]%2)ans[i]=1;
		else if(i+a[i]<=n&&a[i+a[i]]%2!=a[i]%2)ans[i]=1;	
	}
	ans[0]=1;
	dfs(0);
	for(int i=1;i<=n;i++)
	{
		if(ans[i]==1000000000)printf("-1 ");
		else printf("%d ",ans[i]);
	}
	return 0;
}