#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2007;
int n;
int edge[maxn][maxn],cost[maxn],k[maxn],c[maxn],x[maxn],y[maxn],p[maxn];
int ans;
bool vis[maxn];
 
void prim() {
	cost[n] = 0;
	for (int i=1;i<n;++i){
		cost[i]=1e18;
	}
	while(true) {
		int v = -1;
		for(int u = 1;u <= n;u++) {  
			if(!vis[u] && (v == -1 || cost[u] < cost[v])) v = u;
		}
		if(v == -1) break;
		vis[v] = 1;
		ans += cost[v];  
		for(int u = 1;u <= n;u++) {
			if (!vis[u]&&cost[u]>edge[v][u]) p[u]=v;
			cost[u] = min(cost[u],edge[v][u]);
		}
	}
}

#undef int
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>x[i]>>y[i];
	}
	for (int i=1;i<=n;++i){
		cin>>c[i];
	}
	for (int i=1;i<=n;++i){
		cin>>k[i];
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			edge[i][j]=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
		}
	}
	for (int i=1;i<=n;++i){
		edge[n+1][i]=edge[i][n+1]=c[i];
	}
	n++;
	prim();
	cout<<ans<<endl;
	vector<int> v1;
	vector<pair<int,int> > v2;
	for (int i=1;i<n;++i){
		if (p[i]==n) v1.push_back(i);
		else v2.push_back({i,p[i]});
	}
	cout<<v1.size()<<endl;
	for (auto c:v1){
		cout<<c<<endl;
	}
	cout<<v2.size()<<endl;
	for (auto c:v2){
		cout<<c.first<<" "<<c.second<<endl; 
	}
	return 0;
}