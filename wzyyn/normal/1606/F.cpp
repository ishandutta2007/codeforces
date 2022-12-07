#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,Q,ans[N];
int fa[N],dep[N];
vector<int> e[N],f[N];
vector<pair<int,int> > op[N];
void dfs(int x){
	f[x].resize(e[x].size()-(x!=1));
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dep[i]=dep[x]+1;
			dfs(i);
			if (f[i].size()>f[x].size())
				f[x].resize(f[i].size());
			for (int j=0;j<f[i].size();j++)
				f[x][j]+=f[i][j]-1;
		}
	for (auto i:op[x])
		if (i.first<f[x].size())
			ans[i.second]+=f[x][i.first];
	for (int i=0;i<f[x].size();i++)
		f[x][i]+=e[x].size()-i-(x!=1);
	for (;f[x].size()&&f[x].back()<=0;f[x].pop_back());
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++){
		int x,v;
		scanf("%d%d",&x,&v);
		op[x].push_back(pair<int,int>(v,i));
		ans[i]=e[x].size()-(x!=1);
	}
	dfs(1);
	for (int i=1;i<=Q;i++)
		printf("%d\n",ans[i]);
}