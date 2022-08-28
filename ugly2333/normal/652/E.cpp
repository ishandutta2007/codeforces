//CF 652E
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
const int N = 333333;
struct edge{
	int to;
	int w;
	int pr;
	int f;
}e[N<<1];
int tot=1,la[N];
void adde(int x,int y,int z){
	e[++tot].pr=la[x];
	la[x]=tot;
	e[tot].to=y;
	e[tot].w=z;
	e[tot].f=0;
}
int n,m,a,b,vis[N],s[N],q[N];
void dfs1(int u,int fa){
	int i,x;
	vis[u]=1;
	q[u]=1;
	for(i=la[u];i;i=e[i].pr){
		x=e[i].to;
		if(x==fa)
			continue;
		if(vis[x]){
			if(q[x])
				s[u]++,s[x]--;
		}
		else{
			dfs1(x,u);
			if(s[x])
				s[u]+=s[x];
			else
				e[i].f=1;
		}
	}
	q[u]=0;
}
vector<int> v;
void dfs2(int u,int fa){
	int i,x;
	vis[u]=1;
	if(u==b){
		x=v.size();
		for(i=0;i<x;i=i+1)
			e[v[i]].f=0;
	}
	for(i=la[u];i;i=e[i].pr){
		x=e[i].to;
		if(x==fa)
			continue;
		if(!vis[x]){
			v.push_back(i);
			dfs2(x,u);
			v.pop_back();
		}
	}
}
void dfs3(int u,int fa){
	int i,x;
	vis[u]=1;
	for(i=la[u];i;i=e[i].pr){
		x=e[i].to;
		if(x==fa||e[i].f)
			continue;
		if(e[i].w){
			cout<<"YES\n";
			exit(0);
		}
		if(!vis[x])
			dfs3(x,u);
	}
}
int main()
{
	int i,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		adde(x,y,z);
		adde(y,x,z);
	}
	scanf("%d%d",&a,&b);
	memset(vis,0,sizeof(vis));
	dfs1(a,0);
	memset(vis,0,sizeof(vis));
	dfs2(a,0);
	memset(vis,0,sizeof(vis));
	dfs3(a,0);
	cout<<"NO\n";
	return 0;
}