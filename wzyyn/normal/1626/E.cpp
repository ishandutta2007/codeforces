#include<bits/stdc++.h>

using namespace std;

const int N=300005;
int n,c[N],sc[N];
vector<int> e[N];
int q[N],fa[N],ans[N];
void dfs(int x){
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dfs(i);
			sc[x]+=sc[i];
		}
	sc[x]+=c[x];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1);
	for (int i=1;i<=n;i++)
		if (c[i]){
			ans[i]=1;
			for (auto j:e[i])
				ans[j]=1;
		}
	int h=0,t=0;
	for (int i=1;i<=n;i++)
		if (ans[i]) q[++t]=i;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x]){
			int sub=(fa[i]==x?sc[1]-sc[i]:sc[x]);
			if (sub>=2&&!ans[i]) ans[i]=1,q[++t]=i;
		}
	}
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}