/*
Contest: -
Problem: P4151
Author: tzc_wk
Time: 2020.7.31
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
#define int long long
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
vector<pii> g[1000005];
int bs[100];
inline void insert(int x){
	for(int i=63;i>=0;i--)
		if(x>>i&1ll){
			if(!bs[i]){
				bs[i]=x;
				return;
			}
			else x^=bs[i];
		}
}
inline int minxor(int x){
	int res=x;
	for(int i=63;i>=0;i--){
		if((res^bs[i])<res) res^=bs[i];
	}
	return res;
}
int weight[1000005];
bool vis[1000005];
inline void dfs(int x,int w){
	weight[x]=w;
	vis[x]=1;
	foreach(it,g[x]){
		int to=it->fi,wei=it->se;
		if(!vis[to]) dfs(to,w^wei);
		else insert(weight[to]^w^wei);
	}
}
signed main(){
	fz(i,1,m){
		int x=read(),y=read(),w=read();
		g[x].push_back({y,w});
		g[y].push_back({x,w});
	}
	dfs(1,0);
	printf("%lld\n",minxor(weight[n]));
	return 0;
}