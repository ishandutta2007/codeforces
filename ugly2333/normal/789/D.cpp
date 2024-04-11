//CF 789D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
vector<int> v[1000005];
int a[1000005],vis[1000005];
void dfs(int u)
{
	vis[u]=2;
	int i,s;
	s=v[u].size();
	for(i=0;i<s;i=i+1)
		if(vis[v[u][i]]==1)
			dfs(v[u][i]);
}
int main()
{
	long long s;
	int n,m,i,x,y,p;
	cin>>n>>m;
	p=0;
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		a[x]++;
		a[y]++;
		vis[x]=1;
		vis[y]=1;
		if(x==y){
			a[x]-=2;
			p++;
		}
		else{
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}
	for(i=1;i<=n;i=i+1)
		if(vis[i]==1){
			dfs(i);
			break;
		}
	for(i=1;i<=n;i=i+1)
		if(vis[i]==1){
			cout<<0<<endl;
			return 0;
		}
	s=0;
	for(i=1;i<=n;i=i+1)
		s+=(long long)a[i]*(a[i]-1);
	s+=(long long)p*(p-1);
	s/=(long long)2;
	s+=(long long)p*(m-p);
	cout<<s<<endl;
	return 0;
}