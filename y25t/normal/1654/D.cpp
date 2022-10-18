#include<bits/stdc++.h>
#define P 998244353
#define N 200005

inline int fmo(int x){
	return x+((x>>31)&P);
}
inline int fp(int x,int k=P-2){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}

std::vector<std::pair<int,int>> D[N];

int T;

int n;

std::vector<std::tuple<int,int,int>> E[N];

int mx[N],f[N];
inline void dfs(int u,int fa){
	for(auto [v,x,y]:E[u]) if(v!=fa){
		for(auto [p,i]:D[x])
			f[p]-=i;
		for(auto [p,i]:D[y]){
			f[p]+=i;
			mx[p]=std::max(mx[p],f[p]);
		}
		dfs(v,u);
		for(auto [p,i]:D[x])
			f[p]+=i;
		for(auto [p,i]:D[y])
			f[p]-=i;
	}
}

int ans=0;
inline void Dfs(int u,int fa,int tmp){
	ans=fmo(ans+tmp-P);
	for(auto [v,x,y]:E[u]) if(v!=fa)
		Dfs(v,u,1ll*tmp*x%P*fp(y)%P);
}

int main(){
	for(int i=1;i<=2e5;i++){
		int x=i;
		for(int j=2;j*j<=x;j++)
			if(x%j==0){
				int cnt=0;
				while(x%j==0)
					x/=j,cnt++;
				D[i].emplace_back(j,cnt);
			}
		if(x>1)
			D[i].emplace_back(x,1);
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			E[i].clear();
		for(int i=1;i<n;i++){
			int u,v,x,y;
			scanf("%d%d%d%d",&u,&v,&x,&y);
			E[u].emplace_back(v,y,x),E[v].emplace_back(u,x,y);
		}
		for(int i=1;i<=n;i++)
			mx[i]=f[i]=0;
		dfs(1,0);
		int tmp=1;
		for(int i=1;i<=n;i++)
			tmp=1ll*tmp*fp(i,mx[i])%P;
		ans=0;
		Dfs(1,0,tmp);
		printf("%d\n",ans);
	}
}