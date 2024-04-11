/*
Contest: Codeforces Round #668 (Div.1)
Problem: Codeforces 1404B
Author: tzc_wk
Time: 2020.9.6
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n,a,b,da,db;
vector<int> g[100005];
int dep[100005],dep1[100005];
inline void dfs(int x,int f){
	foreach(it,g[x]){
		int y=*it;if(y==f) continue;
		dep[y]=dep[x]+1;dfs(y,x);
	}
}
inline void dfs1(int x,int f){
	foreach(it,g[x]){
		int y=*it;if(y==f) continue;
		dep1[y]=dep1[x]+1;dfs1(y,x);
	}
}
inline void solve(){
	cin>>n>>a>>b>>da>>db;
	fz(i,1,n) g[i].clear(),dep[i]=dep1[i]=0;
	fz(i,1,n-1){
		int u,v;cin>>u>>v;
		g[u].pb(v);g[v].pb(u);
	}
	dfs(b,0);
	int d=dep[a],rt=1;
	fz(i,1,n) if(dep[i]>dep[rt]) rt=i;
	dfs1(rt,0);
	int mx=0;fz(i,1,n) mx=max(mx,dep1[i]);
	if(2*da>=db||2*da>=mx||da>=d) puts("Alice");
	else puts("Bob");
}
int main(){
	int T=read();
	while(T--){
		solve();
	}
	return 0;
}