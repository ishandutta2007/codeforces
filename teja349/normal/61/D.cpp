
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
vector < vi > adj(123456),cost(123456);
ll dist[123456]={0};
int dfs(int cur,int prev){
	int i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			dist[adj[cur][i]]=dist[cur]+cost[cur][i];
			dfs(adj[cur][i],cur);
		}
	}
	return 0;
}


int main(){
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	 int i;
	 int u,v,w;
	 ll sumi=0;
	 rep(i,n-1){
	 	cin>>u>>v>>w;
	 	u--;
	 	v--;
	 	sumi+=w;
	 	adj[u].pb(v);
	 	adj[v].pb(u);
	 	cost[u].pb(w);
	 	cost[v].pb(w);

	 }
	 ll ans=0;
	 dist[0]=0;
	 dfs(0,-1);
	 rep(i,n){
	 	//cout<<dist[i]<<endl;
	 	ans=max(ans,dist[i]);
	 }
	 cout<<(sumi*2)-ans<<endl;
}