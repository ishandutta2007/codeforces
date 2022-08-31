//CF 860D
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
const int N = 222222;
vector<pair<int,int> > v[N];
int vis[N],used[N],ans[N][3],anss;
int n,m;
void Ans(int x,int y,int z){
	anss++;
	ans[anss][0]=x;
	ans[anss][1]=y;
	ans[anss][2]=z;
}
void dfs(int u,int fa)
{
	int i,s,x,y,h,f;
	vis[u]=1;
	s=v[u].size();
	h=0;
	for(i=0;i<s;i=i+1){
		x=v[u][i].first;
		y=v[u][i].second;
		if(x==fa){
			f=y;
			continue;
		}
		if(used[y])
			continue;
		if(vis[x]){
			used[y]=1;
			if(!h)
				h=x;
			else{
				Ans(h,u,x);
				h=0;
			}
			continue;
		}
		dfs(x,u);
		if(!used[y]){
			used[y]=1;
			if(!h)
				h=x;
			else{
				Ans(h,u,x);
				h=0;
			}
			continue;
		}
	}
	if(h&&fa!=-1){
		used[f]=1;
		Ans(h,u,fa);
	}
}
int main()
{
	int i,j,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(make_pair(y,i));
		v[y].push_back(make_pair(x,i));
	}
	memset(vis,0,sizeof(vis));
	memset(used,0,sizeof(used));
	for(i=n;i>=1;i=i-1){
		if(!vis[i])
			dfs(i,-1);
	}
	cout<<anss<<endl;
	for(i=1;i<=anss;i=i+1){
		for(j=0;j<3;j=j+1)
			cout<<ans[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}