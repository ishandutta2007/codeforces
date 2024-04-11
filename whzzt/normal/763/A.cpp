#include "bits/stdc++.h"
using namespace std;

const int N = 100005;
vector<int> e[N];
int n,c[N],res[N],fl[N];
void dfs(int x,int fa){
	res[x] = c[x]; fl[x]=1;
	for(int i=0;i<e[x].size();i++)if(e[x][i]!=fa){
		int to = e[x][i]; dfs(to,x);
		if (res[to]!=res[x]) res[x]=0;
		fl[x] &= !!res[to];
	}
}
int deg[N];
void DFS(int x,int fa,int ans){
	if (ans==0) return ;
	if (fl[x] && ans) {puts("YES"); printf("%d\n",x); exit(0);}
	if (c[x] != ans && ans != -1) return ; 
	int sum = 0;
	for(int i=0;i<e[x].size();i++)if(e[x][i]!=fa){
		int to = e[x][i];
		if (deg[res[to]]==0) sum++;
		deg[res[to]] ++;
	}
	if (sum == 1){
		for(int i=0;i<e[x].size();i++)if(e[x][i]!=fa){
			int to = e[x][i]; deg[res[to]] --;
		}
		for(int i=0;i<e[x].size();i++)if(e[x][i]!=fa){
			int to = e[x][i]; 
			if (x!=1 && e[x].size()==2 || e[x].size()==1) DFS(to,x,c[x]);
			else if (res[to] == c[x]) DFS(to,x,c[x]);
		}
	} else if (sum == 2){
		int a[2]={0},co[2]={0},tp=0;
		for(int i=0;i<e[x].size();i++)if(e[x][i]!=fa){
			int to = e[x][i];
			if (deg[res[to]] == 1) a[tp++]=to;
		}
		for(int i=0;i<e[x].size();i++)if(e[x][i]!=fa){
			int to = e[x][i]; deg[res[to]] --;
			for (int j=0; j<tp; j++)
				if(res[to]!=res[a[j]]) co[j] = res[to];
		}
		for(int i=0;i<tp;i++){
			if (co[i] == c[x]) DFS(a[i],x,co[i]);
		}
	}
}
int main(){
	scanf("%d",&n);int u,v;
	for(int i=2;i<=n;i++){
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	dfs(1,0);
	DFS(1,0,-1);
	puts("NO");
	return 0;
}