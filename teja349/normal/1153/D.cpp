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
vector<vi> adj(312345);
int req[312345],op[312345];
int k=0;
int dfs(int cur){
	int i;
	if(adj[cur].empty()){
		req[cur]=1;
		k++;
		return 0;
	}
	rep(i,adj[cur].size()){
		dfs(adj[cur][i]);
	}
	if(op[cur]==1){
		req[cur]=inf;
		rep(i,adj[cur].size()){
			req[cur]=min(req[cur],req[adj[cur][i]]);
		}
	}
	else{
		req[cur]=0;
		rep(i,adj[cur].size()){
			req[cur]+=req[adj[cur][i]];
		}
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	int i;
	rep(i,n){
		cin>>op[i];
	}
	int p;
	f(i,1,n){
		cin>>p;
		p--;
		adj[p].pb(i);
	}
	dfs(0);
	cout<<k-req[0]+1<<endl;
    return 0;   
}