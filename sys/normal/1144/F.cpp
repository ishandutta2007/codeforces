#include<iostream>
#include<vector>
#include<cstdlib>
using std::cin;
using std::cout;
std::vector<int> v[200010];
int n,m,x[200010],col[200010],y[200010];
void dfs(int x){
	for(auto u:v[x]) if(!col[u]) col[u]=col[x]^1,dfs(u);else if(col[u]==col[x])cout<<"NO\n",exit(0);
}
int main(){
	std::ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>x[i]>>y[i],v[x[i]].push_back(y[i]),v[y[i]].push_back(x[i]);
	for(int i=1;i<=n;i++) if(!col[i]) col[i]=2,dfs(i);
	for(int i=1;i<=m;i++) if(col[x[i]]==col[y[i]]) cout<<"NO\n",exit(0);
	cout<<"YES\n";
	for(int i=1;i<=m;i++) cout<<(col[x[i]]&1);
	
	cout<<'\n';
	return 0;
}