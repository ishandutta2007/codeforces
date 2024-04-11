#include<cstdio>
#include<algorithm>
#include<vector>
#define N 2005

int n;

int d[N];
inline void qry(int x){
	printf("? %d\n",x);
	fflush(stdout);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
}

int cnt[2];
std::vector<int> vec[N];

int fa[N];
bool vis[N];

int main(){
	scanf("%d",&n);
	qry(1);
	vis[1]=1;
	for(int i=1;i<=n;i++)
		if(d[i]==1){
			vis[i]=1;
			fa[i]=1;
		}
	for(int i=2;i<=n;i++)
		vec[d[i]].push_back(i);
	for(int i=1;i<=n;i++)
		cnt[i&1]+=vec[i].size();
	int o=cnt[0]>cnt[1]?1:2;
	for(int i=o;i<=n;i+=2){
		for(auto u:vec[i]){
			qry(u);
			vis[u]=1;
			for(int v=1;v<=n;v++)
				if(d[v]==1){
					if(!vis[v]){
						fa[v]=u;
						vis[v]=1;
					}
					else
						fa[u]=v;
				}
		}
	}
	puts("!");
	for(int i=2;i<=n;i++)
		printf("%d %d\n",fa[i],i);
}