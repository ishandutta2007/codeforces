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

//std::ios::sync_with_stdio(false);  
int cnt=0;
vector<vi> adj(123456); 
int subtree[123456];
int dfs(int cur,int par){
	int i;
	subtree[cur]=1;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs(adj[cur][i],cur);
			subtree[cur]+=subtree[adj[cur][i]];
		}
	}
	if(par!=-1 && subtree[cur]%2==0){
		cnt++;
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n%2){
    	cout<<-1<<endl;
    	return 0;
    }
    int i,u,v;
    rep(i,n-1){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs(0,-1);
    cout<<cnt<<endl;
    return 0;  
    
}