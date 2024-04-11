#include <bits/stdc++.h>
using namespace std;
const int N=505;
const int M=10050;
int n,m,k,u[M],v[M],par[M][N][2];
int root(int x,int i,int t){return par[i][x][t]==x?x:par[i][x][t]=root(par[i][x][t],i,t);}
void unite(int x,int y,int i,int t){par[i][root(x,i,t)][t]=par[i][root(y,i,t)][t];}
int main(){
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++){
		par[0][i][0]=i;
		par[m+1][i][1]=i;
	}
	for(int i=1;i<=m;i++)scanf("%i %i",&u[i],&v[i]);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)par[i][j][0]=par[i-1][j][0];
		unite(u[i],v[i],i,0);
	}
	for(int i=m;i>=1;i--){
		for(int j=1;j<=n;j++)par[i][j][1]=par[i+1][j][1];
		unite(u[i],v[i],i,1);
	}
	scanf("%i",&k);
	while(k--){
		int l,r;scanf("%i%i",&l,&r);
		int p[N];
		for(int i=1;i<=n;i++)p[i]=i;
		function<int(int)> find=[&](int x){return p[x]==x?x:p[x]=find(p[x]);};
		function<void(int,int)> unite=[&](int x,int y){p[find(x)]=find(y);};
		for(int i=1;i<=n;i++){
			unite(par[l-1][i][0],i);
			unite(par[r+1][i][1],i);
		}
		int ans=0;
		for(int i=1;i<=n;i++)ans+=(find(i)==i?1:0);
		printf("%i\n",ans);
	}
	return 0;
}