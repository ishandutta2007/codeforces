#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const LL INF = 1e17;
const int N = 2010;

vector<int> g[N];
string s[N];
int n,m,fa[N],ans[N],vis[N];

bool dfs(int x){
	ans[x] = vis[x] = 1;
	for(auto u:g[x]){
		if(vis[u]==1) return false;
		if(!vis[u] && !dfs(u)) return false;
		ans[x] = max(ans[x], ans[u]+1);
	}
	vis[x] = 2;
	return true;
}

int find(int x){return x==fa[x]?x:(fa[x]=find(fa[x]));}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	rep(i,1,n+m)fa[i]=i;
	rep(i,1,n){
		cin>>s[i];
		rep(j,1,m)if(s[i][j-1]=='=')fa[find(i)]=find(n+j); 
	}
	rep(i,1,n)rep(j,1,m){
		int x = find(i), y = find(n+j);
		if(s[i][j-1]=='>')g[x].push_back(y);
		if(s[i][j-1]=='<')g[y].push_back(x);
	}
	rep(i,1,n+m)if(!vis[find(i)] && !dfs(find(i))){
		puts("No");return 0;
	}
	cout<<"Yes"<<endl;
	rep(i,1,n)cout<<ans[find(i)]<<" ";
	cout<<endl;
	rep(i,n+1,n+m)cout<<ans[find(i)]<<" ";
	return 0;
}