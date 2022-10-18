#include<bits/stdc++.h>
#define N 2005

int P;
inline void fmo(int &x){
	x+=(x>>31)&P;
}

int n;

std::vector<int> E[N];

int f[N],g[N],h[N],F[N][3],G[3];
inline void dfs(int u,int fa,int k){
	if(fa&&k==1)
		E[u].erase(std::find(E[u].begin(),E[u].end(),fa));
	g[u]=f[u];
	F[u][0]=1,F[u][1]=F[u][2]=0;
	for(auto v:E[u]){
		dfs(v,u,k);
		int x=f[v],y;
		fmo(y=g[v]-x);
		fmo(g[u]+=1ll*h[v]*y%P-P);
		for(int i=0;i<3;i++)
			G[i]=1ll*F[u][i]*x%P;
		for(int i=0;i<3;i++)
			fmo(G[std::min(2,i+1)]+=1ll*F[u][i]*y%P-P);
		for(int i=0;i<3;i++)
			F[u][i]=G[i];
	}
	for(int i=0;i<3;i++)
		fmo(g[u]+=F[u][i]-P);
	std::vector<int> V(E[u].size()+1);
	V.back()=1;
	for(int i=(int)E[u].size()-1;~i;i--)
		V[i]=1ll*V[i+1]*g[E[u][i]]%P;
	for(int i=0,t=1;i<(int)E[u].size();i++){
		int v=E[u][i];
		fmo(h[v]+=1ll*t*V[i+1]%P-P);
		t=1ll*t*g[v]%P;
	}
}

int H[N];

int C[N][N];

int main(){
	scanf("%d%d",&n,&P);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[u].emplace_back(v),E[v].emplace_back(u);
	}
	for(int i=1;i<n;i++){
		dfs(1,0,i);
		std::swap(f,g);
		H[i]=1;
		for(auto j:E[1])
			H[i]=1ll*H[i]*f[j]%P;
	}
	for(int i=0;i<=n;i++)
		C[i][0]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++)
		fmo(C[i][j]=C[i-1][j-1]+C[i-1][j]-P);
	for(int i=1;i<n;i++){
		int res=0;
		for(int j=1;j<=i;j++)
			fmo(res+=1ll*((i-j)&1?P-1:1)*C[i][j]%P*H[j]%P-P);
		printf("%d ",res);
	}
	puts("");
}