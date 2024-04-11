#include<bits/stdc++.h>
using namespace std;
const int p=1000000007;
int d,n;
int a[3000];
vector<int> e[3000];
int ans=0;
bool q[3000];
int dfs(int j,int fa){
	if(!q[j]) return 0;
	int u=1;
	for(int o=0;o<e[j].size();o++){
		if(e[j][o]!=fa) u=(1ll*u*(dfs(e[j][o],j)+1))%p;
	} 
	return u;
}
void solve(int i){
	for(int j=1;j<=n;j++){
		q[j]=true;
		if(a[j]<a[i]) q[j]=false;
		if((a[j]==a[i])&&(j<i)) q[j]=false;
		if(a[j]>a[i]+d) q[j]=false;
	} 
	ans=(ans+dfs(i,i))%p;
}
int main(){
	scanf("%d%d",&d,&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++) solve(i);
	printf("%d",ans);
	return 0;
}