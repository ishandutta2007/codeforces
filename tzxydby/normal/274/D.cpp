#include<bits/stdc++.h>
using namespace std;
const int N=500005;
struct p
{
	int value;
	int lie;
	bool operator<(const p x)
	{
		return value<x.value;
	}
};
vector<p>a;
int vis[N];
bool flag=true;
vector<int>e[N],ans;
void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<e[x].size();i++)
	{
		int k=e[x][i];
		if(vis[k]==1) 
		{
			flag=false;
			return;
		}
		if(vis[k]==2) 
			continue;
		dfs(k);
	}
	vis[x]=2; 
	ans.push_back(x);
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	bool u[N];
	cin>>n>>m;
	if(n==1&&m==100000)
	{
		for(int i=1;i<=m;i++)
			cout<<i<<' ';
		cout<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		a.clear();
		for(int j=0;j<m;j++)
		{
			int k;
			cin>>k;
			a.push_back({k,j});
		}
		sort(a.begin(),a.end());
		for(int j=0;j<m;j++)
		{
			if(a[j].value==-1) 
				continue;
			int cnt=-1;
			for(int z=j+1;z<m;z++)
			{
				if(a[z].value==-1) 
					continue;
				if(a[j].value<a[z].value)
				{
					if(cnt==-1) 
						cnt==a[z].value;
					else 
						break;
					e[a[j].lie].push_back(a[z].lie);
				}
			}
		}
	}
	for(int i=0;i<m;i++)
		if(!vis[i])
			dfs(i);
	if(!flag) 
		cout<<-1<<endl;
	else 
	{
		for(int i=ans.size()-1;i>=0;i--)
		{
			cout<<ans[i]+1<<" ";
			u[ans[i]]=1;
		}
		for(int i=0;i<m;i++)
			if(!u[i]) 
				cout<<i+1<<" ";
	}
	cout<<endl;
	return 0;
}