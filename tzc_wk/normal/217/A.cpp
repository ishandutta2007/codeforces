#include <bits/stdc++.h>
using namespace std;
const int MN=1005;
vector<int> g[2017];
bool used[2017],need[2017];
void dfs(int v){
	used[v]=true;
	for(int i=0;i<g[v].size();i++){
		int u=g[v][i];
		if(!used[u])	dfs(u);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(MN+y);
		g[MN+y].push_back(x);
		need[x]=true;
		need[MN+y]=true;
	}
	int ans=0;
	for(int i=0;i<2*MN;i++){
		if(need[i]&&!used[i]){
			ans++;
			dfs(i);
		}
	}
	cout<<ans-1<<endl;
}