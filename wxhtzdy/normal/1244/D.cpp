#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=100050;
int n,c[3][N],deg[N],dep[N],root=1;
vector<int> E[N],par[3];
void DFS1(int u,int p){
	bool can=true;
	for(int e:E[u])if(e!=p){
		can=false;
		DFS1(e,u);
	}
	if(can)root=u;
}
void DFS(int u,int p){
	par[dep[u]%3].pb(u);
	for(int e:E[u])if(e!=p){
		deg[u]++;
		dep[e]=dep[u]+1;
		DFS(e,u);
	}
}
int main(){
	scanf("%i",&n);
	for(int i=0;i<3;i++)for(int j=1;j<=n;j++)scanf("%i",&c[i][j]);
	for(int i=1;i<n;i++){
		int u,v;scanf("%i%i",&u,&v);
		E[u].pb(v);
		E[v].pb(u);
	}
	DFS1(1,-1);
	DFS(root,-1);
	for(int i=1;i<=n;i++){
		if(deg[i]>1){
			printf("-1");
			return 0;
		}
	}
	vector<int> col(3);
	iota(col.begin(),col.end(),0);
	ll ans=1e18;
	vector<int> perm;
	do{
		ll tmp=0;
		for(int i=0;i<3;i++){
			for(int j:par[i])tmp+=c[col[i]][j];
		}
		if(ans>tmp){
			ans=tmp;
			perm=col;
		}
	}while(next_permutation(col.begin(),col.end()));
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)printf("%i ",perm[dep[i]%3]+1);
	return 0;
}