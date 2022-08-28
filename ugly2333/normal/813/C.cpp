// CF 813C
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
typedef long long LL;
vector<int> v[222222];
int f[222222],dep[222222],h[222222],a[222222];
void dfs(int u,int fa)
{
	f[u]=fa;
	dep[u]=dep[fa]+1;
	h[u]=dep[u];
	int i;
	for(i=0;i<v[u].size();i=i+1){
		if(v[u][i]!=fa){
			dfs(v[u][i],u);
			h[u]=max(h[u],h[v[u][i]]);
		}
	}
}
int main()
{
	int n,k,i,x,y;
	cin>>n>>k;
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dep[0]=0;
	dfs(1,0);
	x=k;
	y=0;
	a[0]=k;
	while(x!=1){
		x=f[x];
		y++;
		a[y]=x;
	}
	y=(y-1)/2;
	x=a[y];
	cout<<(h[x]-1)*2<<endl;
	return 0;
}