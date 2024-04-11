#include<bits/stdc++.h>
#define N 1005

int T;

int n,d[N];

int f[N];
inline int fnd(int x){
	return f[x]?f[x]=fnd(f[x]):x;
}

bool vis[N];

std::priority_queue<std::pair<int,int>> q;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&d[i]);
			q.emplace(d[i],i);
		}
		for(int i=1;i<=n;i++)
			f[i]=vis[i]=0;
		while(q.size()){
			int u=q.top().second;
			q.pop();
			if(vis[u])
				continue;
			vis[u]=1;
			for(int i=1;i<=d[u];i++){
				printf("? %d\n",u),fflush(stdout);
				int v;
				scanf("%d",&v);
				if(!vis[v])
					vis[v]=1,f[v]=fnd(u);
				else{
					f[u]=fnd(v);
					break;
				}
			}
		}
		printf("! ");
		for(int i=1;i<=n;i++)
			printf("%d ",fnd(i));
		puts(""),fflush(stdout);
	}
}