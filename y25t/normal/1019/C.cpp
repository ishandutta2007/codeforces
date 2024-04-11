#include<cstdio>
#include<algorithm>
#include<vector>
#define N 1000005

int n,m;

std::vector<int> E[N];

bool col[N],vis[N];

std::vector<int> ans;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			col[i]=vis[i]=1;
			for(auto j:E[i])
				vis[j]=1;
		}
	for(int i=n;i;i--)
		if(col[i])
			for(auto j:E[i])
				col[j]=0;
	for(int i=1;i<=n;i++)
		if(col[i])
			ans.push_back(i);
	printf("%d\n",ans.size());
	for(auto i:ans)
		printf("%d ",i);
	puts("");
}