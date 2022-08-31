//teja349
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
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int ll
vector<vi> adj(212345);
int n;
int dp[212345][2],dist[212345],subtree[212345];
int dfs(int cur,int par){
	//cout<<cur<<endl;
	int i;
	subtree[cur]=1;
	dp[cur][0]=1;
	dp[cur][1]=0;
	dist[cur]=0;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs(adj[cur][i],cur);
			subtree[cur]+=subtree[adj[cur][i]];
			dist[cur]+=subtree[adj[cur][i]]+dist[adj[cur][i]];
			dp[cur][0]+=dp[adj[cur][i]][1];
			dp[cur][1]+=dp[adj[cur][i]][0];
		}
	}
	return 0;
}
int dfs1(int cur,int par){
	int i;
	int dd,yy,zz;
	rep(i,adj[cur].size()){
		if(adj[cur][i]==par){
			continue;
		}
		dd=dist[adj[cur][i]];
		zz=dp[adj[cur][i]][0];
		yy=dp[adj[cur][i]][1];
		//cout<<dd<<" "<<zz<<" "<<yy<<endl;
		dist[cur]-=subtree[adj[cur][i]]+dd;
		dp[cur][0]-=yy;
		dp[cur][1]-=zz;
		dp[adj[cur][i]][0]+=dp[cur][1];
		dp[adj[cur][i]][1]+=dp[cur][0];
		dist[adj[cur][i]]+=(n-subtree[adj[cur][i]])+dist[cur];
		dist[cur]+=subtree[adj[cur][i]]+dd;
		dp[cur][0]+=yy;
		dp[cur][1]+=zz;
		dfs1(adj[cur][i],cur);
	}
	return 0;
}
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin>>n;
    int i;
    int u,v;
    rep(i,n-1){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs(0,-1);
   // return 0;
    dfs1(0,-1);
    int sumi=0;
    rep(i,n){
    	sumi+=(dist[i]+dp[i][1])/2;
    	//cout<<dist[i]<<endl;
    }
    sumi/=2;
    cout<<sumi<<endl;
    return 0;   
}