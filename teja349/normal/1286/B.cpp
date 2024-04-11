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

int p[12345],val[12345],subtree[12345],c[12345];
vector<vi> adj(12345);
int dfsss(int node){
	int i;
	subtree[node]=1;
	rep(i,adj[node].size()){
		dfsss(adj[node][i]);
		subtree[node]+=subtree[adj[node][i]];
	}
	return 0;
}
int setval(int node,int sumi,int gg){
	int i;
	val[node]+=sumi;
	if(val[node]>=gg)
		val[node]++;
	rep(i,adj[node].size()){
		setval(adj[node][i],sumi,gg);
	}
}
int dfs(int node){
	int i;
	rep(i,adj[node].size()){
		dfs(adj[node][i]);
	}
	int sumi=0;
	int counter=1;
	val[node]=c[node]+1;
	//cout<<node<<" "<<
	rep(i,adj[node].size()){
		setval(adj[node][i],sumi,val[node]);
		sumi+=subtree[adj[node][i]];
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i,root;
    rep(i,n){
    	cin>>p[i]>>c[i];
    	p[i]--;
    	if(p[i]==-1)
    		root=i;
    	else
    		adj[p[i]].pb(i);
    }
    dfsss(root);
    int flag=0;
    rep(i,n){
    	if(subtree[i]-1<c[i])
    	{
    		flag=1;
    	}
    }
    if(flag){
    	cout<<"NO"<<endl;
    	return 0;
    }
    cout<<"YES"<<endl;
    dfs(root);
    rep(i,n){
    	cout<<val[i]<<" ";
    }
    cout<<endl;
    return 0;   
}