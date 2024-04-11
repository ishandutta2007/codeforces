#include <bits/stdc++.h>
using namespace std;
#define kprintf(...)	fprintf(stderr,__VA_ARGS__)
#pragma GCC diagnostic error "-std=c++11"
const int MAXN=(2e5+20)*2;
vector<int> g[MAXN];
int n,m,q;
bool vis[MAXN];
void dfs(int v){
	vis[v]=true;
	for(int u:g[v]){
		if(!vis[u])	dfs(u);
	}
}
int main(){
	cin>>n>>m>>q;
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(n+y);
		g[n+y].push_back(x);
	}
	int ans=-1;
	for(int i=1;i<=m+n;i++){
		if(!vis[i]){
			ans++;
			dfs(i);
		}
	}
	cout<<ans<<endl;
}//