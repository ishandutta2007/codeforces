//CF 19E_2
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
const int N = 11111;
int n,m,cnt;
vector<pair<int,int> > v[N];
int vis[N],cl[N],s[N],f[N],ff[N];
void dfs(int u,int fa){
	int i,sz,x,y;
	vis[u]=1;
	cl[u]=cl[fa]^1;
	sz=v[u].size();
	for(i=0;i<sz;i=i+1){
		x=v[u][i].first;
		y=v[u][i].second;
		if(x==fa||ff[y])
			continue;
		if(vis[x]){
			ff[y]=1;
			if(cl[x]==cl[u]){
				cnt++;
				f[y]=1;
				s[u]++;
				s[x]--;
			}
			else{
				f[y]=0;
				s[u]--;
				s[x]++;
			}
		}
		else{
			dfs(x,u);
			f[y]=s[x];
			s[u]+=s[x];
		}
	}
}
int main()
{
	int i,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(make_pair(y,i));
		v[y].push_back(make_pair(x,i));
	}
	for(i=1;i<=n;i=i+1)
		if(!vis[i])
			dfs(i,0);
	if(!cnt)
		memset(f,0,sizeof(f));
	x=0;
	for(i=1;i<=m;i=i+1)
		if(cnt==f[i])
			x++;
	cout<<x<<endl;
	for(i=1;i<=m;i=i+1)
		if(cnt==f[i])
			cout<<i<<' ';
	return 0;
}
/*
5 6
1 2
2 3
3 4
4 1
4 5
5 1

*/