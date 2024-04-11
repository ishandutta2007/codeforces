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
vector<vi> adj(1234567);
vi vecof;
int deg[1234567]={0},visit[1234567]={0},mama[1234567]={0};
int dfs(int u){
	visit[u]=1;
	int i;
	rep(i,adj[u].size()){
		if(!visit[adj[u][i]]){
			dfs(adj[u][i]);
		}
	}
	return 0;
}
ll sumi=0;
int dfs2(int u){
	int i;
	rep(i,adj[u].size()){
		sumi+=deg[adj[u][i]];
	}
	sumi-=deg[u];
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,m;
	int i,u,v;
	cin>>n>>m;
	int haha=0;
	int ans;
	rep(i,m){
		cin>>v>>u;
		u--;
		v--;
		mama[u]=1;
		mama[v]=1;
		ans=u;
		if(u!=v){
			adj[u].pb(v);
			deg[u]++;
			adj[v].pb(u);
			deg[v]++;
			haha++;
		}
		else{
			vecof.pb(u);
		}


	}
	//return 0;

	dfs(ans);
	rep(i,n){
		if(!visit[i] && mama[i]==1){

			cout<<0<<endl;
			return 0;
		}
	}
	rep(i,n){
		dfs2(i);
	}
	sumi/=2;
	ll lol=vecof.size();
	sumi+=lol*(lol-1)/2;
	sumi+=lol*(haha);
	cout<<sumi<<endl;
}