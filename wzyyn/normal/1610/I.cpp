#include<bits/stdc++.h>

using namespace std;

const int N=300005;

int n,fa[N],f[N];
int q[N],vis[N];
vector<int> e[N];
void dfs(int x){
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dfs(i);
			f[x]^=f[i]+1;
		}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1);
	vis[1]=1;
	int sg=f[1];
	putchar(sg?'1':'2');
	for (int i=2;i<=n;i++){
		*q=0;
		for (int x=i;!vis[x];x=fa[x])
			q[++*q]=x,vis[x]=1;
		for (;*q;--*q){
			int x=q[*q];
			sg^=f[x]^(f[x]+1)^1;
		}
		putchar(sg?'1':'2');
	}
}