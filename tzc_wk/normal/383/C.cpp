#include <bits/stdc++.h>
using namespace std;
int n,T,a[200005],depth[200005],cnt;
vector<int> g[200005];
int idx=0,st[200005],ed[200005],id[200005];
void dfs(int x,int fa){
	st[x]=++idx;
	id[idx]=x;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y==fa)	continue;
		depth[y]=depth[x]+1;
		dfs(y,x);
	}
	ed[x]=idx;
}
int bit[200005];
int lowbit(int x){return x&(-x);}
void add(int ind,int x){
	while(ind<=n){
		bit[ind]+=x;
		ind+=lowbit(ind);
	}
}
int query(int ind){
	int ans=0;
	while(ind)	ans+=bit[ind],ind^=lowbit(ind);
	return ans;
}
int main(){
	cin>>n>>T;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	depth[1]=0;
	dfs(1,0);
//	for(int i=1;i<=n;i++)	cout<<st[i]<<" "<<ed[i]<<endl;
	while(T--){
		int opt;cin>>opt;
		if(opt==1){
			int x,val;
			cin>>x>>val;
			if(depth[x]&1)	add(st[x],val),add(ed[x]+1,-val);
			else			add(st[x],-val),add(ed[x]+1,val);
		}
		else{
			int x;cin>>x;
			if(depth[x]&1)	cout<<query(st[x])+a[x]<<endl;
			else			cout<<a[x]-query(st[x])<<endl;
		}
	}
}