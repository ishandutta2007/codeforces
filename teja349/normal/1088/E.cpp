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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

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

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define int ll
int a[312345],ans[312345];
vector<vi> adj(312345);
int maxi;
int dfs(int cur,int par){
	int i;
	ans[cur]=a[cur];
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs(adj[cur][i],cur);
			ans[cur]+=max(ans[adj[cur][i]],0LL);
		}
	}
	return 0;
}
int cnt=0;
int dfs1(int cur,int par){
	int i;
	ans[cur]=a[cur];
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs1(adj[cur][i],cur);
			ans[cur]+=max(ans[adj[cur][i]],0LL);
		}
	}
	if(ans[cur]==maxi){
		cnt++;
		ans[cur]=0;
	}
	return 0;
}
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n;
  	cin>>n;
  	int i;
  	rep(i,n){
  		cin>>a[i];
  	}
  	int u,v;
  	rep(i,n-1){
  		cin>>u>>v;
  		u--;
  		v--;
  		adj[u].pb(v);
  		adj[v].pb(u);

  	}
  	dfs(0,-1);
  	maxi=ans[0];
  	rep(i,n){
  		maxi=max(ans[i],maxi);
  	}
  	dfs1(0,-1);
  	cout<<maxi*cnt<<" "<<cnt<<endl;
    return 0;   
}