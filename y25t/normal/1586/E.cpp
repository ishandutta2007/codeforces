#include<bits/stdc++.h>
#define N 300005

int n,m,q,a[N],b[N];

std::vector<int> E[N];
std::vector<std::pair<int,int>> T[N];

int A[N],B[N],f[N];

bool vis[N];
int tot;
inline void dfs(int u){
	vis[u]=1;
	for(auto v:E[u])
		if(!vis[v]){
			T[u].push_back({v,++tot});
			T[v].push_back({u,tot});
			A[tot]=u,B[tot]=v;
			dfs(v);
		}
}

int val[N];
std::vector<int> V;
inline bool dfs1(int u,int fa,int t,int op){
	if(u==t)
		return 1;
	for(auto [v,i]:T[u]) if(v!=fa)
		if(dfs1(v,u,t,op)){
			val[i]^=1;
			if(op)
				V.push_back(v);
			return 1;
		}
	return 0;
}

int ans;
inline void dfs2(int u,int fa,int x){
	int tmp=0;
	for(auto [v,i]:T[u]) if(v!=fa){
		if(val[i])
			tmp++;
		dfs2(v,u,val[i]);
	}
	ans+=(tmp-x+1)>>1;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[u].push_back(v),E[v].push_back(u);
	}
	dfs(1);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&a[i],&b[i]);
		dfs1(a[i],0,b[i],0);
	}
	for(int i=1;i<n;i++)
		ans+=val[i];
	if(ans){
		ans=0;
		dfs2(1,0,0);
		printf("NO\n%d\n",ans);
	}
	else{
		puts("YES");
		for(int i=1;i<=q;i++){
			V.clear();
			dfs1(a[i],0,b[i],1);
			printf("%d\n",V.size()+1);
			std::reverse(V.begin(),V.end());
			printf("%d ",a[i]);
			for(auto x:V)
				printf("%d ",x);
			puts("");
		}
	}
}