
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
//std::ios::sync_with_stdio(false);   


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



ll subtree[123456],verc[123456];
vector<vl> adj(123456),cost(123456);
ll counti=0;
ll dfs1(int cur,int prev){
	int i;
	subtree[cur]=1;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			subtree[cur]+=dfs1(adj[cur][i],cur);
		}
	}
	return subtree[cur];
}

ll dfs2(int cur,int prev,ll distm){
	int i;
	if(distm>verc[cur]){
		//cout<<cur<<endl;
		counti+=subtree[cur];
		return 0;
	}
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev)
		{
			dfs2(adj[cur][i],cur,max(distm+cost[cur][i],(ll)0));
		}
	}
	return 0;
}


int main(){
	std::ios::sync_with_stdio(false);
	int n,i;
	ll u,v;
	cin>>n;
	rep(i,n){
		cin>>verc[i];
	}
	rep(i,n-1){
		cin>>u>>v;
		u--;
		adj[u].pb(i+1);
		adj[i+1].pb(u);
		cost[i+1].pb(v);
		cost[u].pb(v);
	}
	//cout<<"hii";
	dfs1(0,-1);
	dfs2(0,-1,0);
	cout<<counti<<endl;
}