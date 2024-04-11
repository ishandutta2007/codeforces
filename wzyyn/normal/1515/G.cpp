#include<bits/stdc++.h>
using namespace std;

const int N=200005;

int n,m;
vector<pair<int,int> > e[N];
int dfn[N],low[N],col[N];
int stk[N],inq[N],vis[N];
long long dep[N],Gloop[N];

long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}
void Tarjan(int x){
	dfn[x]=low[x]=++*dfn;
	stk[++*stk]=x; inq[x]=1;
	for (auto i:e[x])
		if (!dfn[i.first]){
			Tarjan(i.first);
			low[x]=min(low[x],low[i.first]);
		}
		else if (inq[i.first])
			low[x]=min(low[x],dfn[i.first]);
	if (low[x]==dfn[x]){
		++*col;
		int y=23333333;
		for (;y!=x;){
			y=stk[(*stk)--];
			inq[y]=0;
			col[y]=*col;
		}
	}
}
void dfs(int x,int co){
	vis[x]=1;
	for (auto i:e[x])
		if (col[i.first]==co){
			if (!vis[i.first]){
				dep[i.first]=dep[x]+i.second;
				dfs(i.first,co);
			}
			else
				Gloop[co]=gcd(Gloop[co],dep[x]+i.second-dep[i.first]);
		}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		e[x].push_back(pair<int,int>(y,v));
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i])
			Tarjan(i);
	for (int i=1;i<=n;i++)
		if (!Gloop[col[i]])
			dfs(i,col[i]);
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		int G=gcd(v,Gloop[col[x]]);
		puts(y%G?"NO":"YES");
	}
}