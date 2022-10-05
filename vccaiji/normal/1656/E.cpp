#include<bits/stdc++.h>
using namespace std;
vector<int> e[110000];
int a[110000];
int s[110000];
int o[2];
void dfs1(int i,int c,int fa){
	o[c]++;
	for(int j=0;j<e[i].size();j++){
		if(e[i][j]!=fa) dfs1(e[i][j],c^1,i);
	}
}
void dfs2(int i,int fa){
	for(int j=0;j<e[i].size();j++){
		if(e[i][j]!=fa){
			a[e[i][j]]=s[i];
			s[e[i][j]]=1-s[i];
			a[i]-=s[i];
			dfs2(e[i][j],i);
		}
	}
}
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		o[0]=o[1]=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs1(1,0,1);
		int oo=1;
		if(o[0]>50000) oo=e[1][0];
		a[oo]=1;
		s[oo]=-1;
		dfs2(oo,0);
		for(int i=1;i<=n;i++) printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}