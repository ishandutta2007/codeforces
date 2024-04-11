/*
Contest: -
Problem: Codeforces 51F
Author: tzc_wk
Time: 2020.7.29
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),m=read();
vector<int> g[100005];
int dfn[100005],low[100005],tim=0;
map<pii,bool> bridge;
inline void tarjan(int x,int f){
	dfn[x]=low[x]=++tim;
	foreach(it,g[x]){
		int y=*it;
		if(!dfn[y]){
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
			if(low[y]>dfn[x]) bridge[pii(x,y)]=bridge[pii(y,x)]=1;
		}
		else if(y!=f) low[x]=min(low[x],dfn[y]);
	}
}
int ecc[100005],comp=0,siz[100005];
inline void findcomp(int x){
	if(ecc[x]) return;
	ecc[x]=comp;siz[comp]++;
	foreach(it,g[x]){
		int y=*it;
		if(!bridge[pii(x,y)]) findcomp(y);
	}
}
map<pii,bool> edged;
vector<int> new_g[100005];
int dep1[100005],dep2[100005],vis[100005],deg[100005];
vector<int> points;
inline void dfs1(int x,int f){
	points.push_back(x);
	vis[x]=1;
	foreach(it,new_g[x]){
		int y=*it;
		if(y==f) continue;
		dep1[y]=dep1[x]+1;
		dfs1(y,x);
	}
}
inline void dfs2(int x,int f){
	foreach(it,new_g[x]){
		int y=*it;
		if(y==f) continue;
		dep2[y]=dep2[x]+1;
		dfs2(y,x);
	}
}
signed main(){
	fz(i,1,m){
		int x=read(),y=read();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int ans=n-1;
	fz(i,1,n) if(!dfn[i]) tarjan(i,0);
	fz(i,1,n) if(!ecc[i]) comp++,findcomp(i);
	fz(i,1,n) foreach(it,g[i]){
		int j=*it;
		if(ecc[i]!=ecc[j]&&!edged[pii(ecc[i],ecc[j])]){
			edged[pii(ecc[i],ecc[j])]=edged[pii(ecc[j],ecc[i])]=1;
			new_g[ecc[i]].push_back(ecc[j]);
			new_g[ecc[j]].push_back(ecc[i]);
			deg[ecc[i]]++;deg[ecc[j]]++;
		}
	}
	fz(i,1,comp){
		if(deg[i]==1) ans--;
		else if(deg[i]==0) ans-=2;
	}
	int t=0;
	fz(i,1,comp) if(!vis[i]){
		points.clear();
		t++;
		dfs1(i,0);int u=0,v=0;
		foreach(j,points) if(dep1[*j]>dep1[u]) u=*j;dfs2(u,0);
		foreach(j,points) if(dep2[*j]>dep2[v]) v=*j;
		ans-=dep2[v]-2;
//		cout<<dep2[v]-2<<endl;
	}
	printf("%d\n",ans);
	return 0;
}