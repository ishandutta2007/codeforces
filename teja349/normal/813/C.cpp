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
vi vec;
int lev[212345],paren[212345],x;  
vector<vi> adj(212345);
int dfs1(int cur,int par){
	int maxi=0;
	int i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			maxi=max(maxi,dfs1(adj[cur][i],cur)+1);
		}
	}


	return maxi;
}
int dfs(int cur,int par,int leve){
	
	vec.pb(cur);
	paren[cur]=par;
	lev[cur]=leve;
	int val,haha;
	if(cur==x){
		int val=vec[lev[cur]/2 +1];

		haha=dfs1(val,paren[val]);
		//cout<<haha<<endl;
		val=lev[val]+haha;

		cout<<2*val<<endl;
		exit(0);
	}
	int i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs(adj[cur][i],cur,leve+1);
		}
	}
	vec.erase(vec.end()-1);
	return 0;

}

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    cin>>n>>x;
    int i,u,v;
    rep(i,n-1){
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs(1,-1,0);
    return 0;

}