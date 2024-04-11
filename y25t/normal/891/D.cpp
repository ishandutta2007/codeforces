#include<bits/stdc++.h>
#define ll long long
#define N 500005

int n;

std::vector<int> E[N];

struct node{
	int a[2][2];
	node(int x=0){
		a[0][0]=x,a[0][1]=a[1][0]=a[1][1]=0;
	}
};
node operator * (node x,node y){
	node res;
	for(int i=0;i<2;i++){
		for(int j=i;j<2;j++) for(int p=0;p<2;p++) for(int q=0;p+q<2;q++)
			res.a[i==j][p+q]+=x.a[i][p]*y.a[j][q];
		res.a[i][1]+=x.a[i][0]*y.a[0][0];
	}
	return res;
}
node operator + (node x,node y){
	node res;
	for(int i=0;i<2;i++) for(int j=0;i+j<2;j++)
		for(int p=0;p<2;p++) for(int q=0;p+q<2;q++)
			res.a[i+j][p+q]+=x.a[i][p]*y.a[j][q];
	return res;
}

int sz[N];
node f[N],g[N];
inline void dfs1(int u,int fa){
	sz[u]=1;
	if(fa)
		E[u].erase(std::find(E[u].begin(),E[u].end(),fa));
	f[u]=node(1);
	for(auto v:E[u]){
		dfs1(v,u);
		sz[u]+=sz[v];
		f[u]=f[u]*f[v];
	}
}
inline void dfs2(int u){
	std::vector<node> sum;
	node tmp(1);
	sum.push_back(u==1?tmp:tmp*g[u]);
	for(auto v:E[u])
		sum.push_back(sum.back()*f[v]);
	for(int i=E[u].size()-1;~i;i--){
		int v=E[u][i];
		g[v]=sum[i]+tmp;
		tmp=tmp*f[v];
		dfs2(v);
	}
}

ll ans;

int main(){
	scanf("%d",&n);
	if(n&1){
		puts("0");
		return 0;
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[u].push_back(v),E[v].push_back(u);
	}
	dfs1(1,0),dfs2(1);
	for(int i=2;i<=n;i++)
		if(sz[i]&1)
			ans+=1ll*(f[i].a[0][0]+f[i].a[1][1])*(g[i].a[0][0]+g[i].a[1][1]);
		else if(f[i].a[1][0]&&g[i].a[1][0])
			ans+=1ll*sz[i]*(n-sz[i]);
	printf("%lld\n",ans);
}