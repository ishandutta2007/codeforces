#include<bits/stdc++.h>
#define N 200005

int TTT;

int n;

int a[N],d[N],deg[N];
std::vector<int> T[N],E[N];

bool flg;
inline int dfs(int u,int fa){
	d[u]=d[fa]^1;
	a[u]^=d[u];
	int tmp=a[u]-d[u];
	for(auto v:T[u]) if(v!=fa)
		tmp+=dfs(v,u);
	if(u==1)
		flg&=!tmp;
	else{
		flg&=tmp==1||tmp==-1;
		if(tmp==1)
			E[u].push_back(fa),deg[fa]++;
		else
			E[fa].push_back(u),deg[u]++;
	}
	return tmp;
}

inline void sol(int u){
	if(!E[u].size())
		return;
	int v=E[u].back();
	E[u].pop_back();
	printf("%d %d\n",u,v);
	sol(v);
}

int main(){
	scanf("%d",&TTT);
	while(TTT--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			a[i]=d[i]=deg[i]=0,T[i].clear(),E[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			a[u]^=1,a[v]^=1;
			T[u].push_back(v),T[v].push_back(u);
		}
		flg=1;
		dfs(1,0);
		if(!flg){
			puts("NO");
			continue;
		}
		puts("YES");
		std::queue<int> q;
		std::vector<int> p;
		for(int i=1;i<=n;i++) if(!deg[i])
			q.push(i);
		while(q.size()){
			int u=q.front();
			q.pop();
			if(a[u])
				p.push_back(u);
			for(auto v:E[u]) if(!--deg[v])
				q.push(v);
		}
		std::reverse(p.begin(),p.end());
		for(auto u:p)
			sol(u);
	}
}