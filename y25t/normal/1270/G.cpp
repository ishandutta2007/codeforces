#include<cstdio>
#include<vector>
#define N 1000005

int T;

int n,a[N];

int fa[N];
bool vis[N];
std::vector<int> ans;
inline void dfs(int u){
	vis[u]=1;
	int v=u-a[u];
	if(!vis[v]){
		fa[v]=u;
		dfs(v);
	}
	else
		for(int w=u;1;w=fa[w]){
			ans.push_back(w);
			if(w==v)
				break;
		}
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			fa[i]=vis[i]=0;
		ans.clear();
		dfs(1);
		printf("%d\n",ans.size());
		for(std::vector<int>::iterator it=ans.begin();it!=ans.end();it++)
			printf("%d ",*it);
		puts("");
	}
}