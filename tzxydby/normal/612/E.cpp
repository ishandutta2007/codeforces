#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int p[N],vis[N],ans[N],n;
vector<vector<int>>v1,v2;
bool cmp(vector<int>a,vector<int>b)
{
	return a.size()<b.size();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		vector<int>v;
		v.clear();
		v.push_back(i);
		int x=p[i];
		while(x!=i)
		{
			v.push_back(x);
			vis[x]=1;
			x=p[x];
		}
		if(v.size()%2)
			v1.push_back(v);
		else
			v2.push_back(v);
	}
	if(v2.size()%2)
	{
		puts("-1");
		return 0;
	}
	sort(v2.begin(),v2.end(),cmp);
	for(auto v:v1)
	{
		int n=(v.size()+1)/2;
		for(int i=0;i<v.size();i++)
			ans[p[v[i]]]=p[v[(i+n)%v.size()]]; 
	}
	for(int j=0;j<v2.size();j+=2)
	{
		if(v2[j].size()!=v2[j+1].size())
		{
			puts("-1");
			return 0;
		}
		for(int i=0;i<v2[j].size();i++)
			ans[p[v2[j][i]]]=p[v2[j+1][i]];
		for(int i=0;i<v2[j+1].size();i++)
			ans[p[v2[j+1][i]]]=p[v2[j][(i+1)%v2[j].size()]];
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}