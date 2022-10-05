#include<bits/stdc++.h>
using namespace std;
bool vis[110000]={};
int num;
vector<int> e[110000];
void dfs(int i){
	num++;
	vis[i]=true;
	for(int j=0;j<e[i].size();j++){
		int u=e[i][j];
		if(vis[u]) continue;
		dfs(u);
	}
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int tot=0,ans=1;
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			num=0;
			dfs(i);
			tot++;
			ans=(1ll*ans*num)%k;
		}
	}
	if(tot==1) printf("%d",1%k);
	else{
		for(int j=1;j<=tot-2;j++) ans=(1ll*ans*n)%k;
		printf("%d",ans);
	}
	return 0;
}