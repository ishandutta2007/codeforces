#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],b[N],ans;
struct edge{
	int to,nxt;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
	cnt++;
	ed[cnt].to=et;
	ed[cnt].nxt=h[st];
	h[st]=cnt;
}
set<int>st[N];
void dfs(int x,int fa){
	b[x]=a[x]^b[fa];
	for(int i=h[x];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v!=fa)dfs(v,x);
	}
}
void solve(int x,int fa){
	int pd=0;
	st[x].insert(b[x]);
	for(int i=h[x];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v!=fa){
			solve(v,x);
			if(st[x].size()<st[v].size())st[x].swap(st[v]);
			for(int o:st[v])pd|=st[x].count(o^a[x]);
			for(int o:st[v])st[x].insert(o);
			st[v].clear();
		}
	}
	if(pd){
		ans++;
		st[x].clear();
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	solve(1,0);
	printf("%d",ans);
}