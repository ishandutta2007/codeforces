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
#define int ll

int dep[223456],paren[212345],subtree[212345],gg[212345],foo[212345];
vector<vi> adj(212345);

int dfs(int cur,int par){
	paren[cur]=par;
	if(par==-1)
		dep[cur]=0;
	else
		dep[cur]=dep[par]+1;
	int i;
	subtree[cur]=1;
	rep(i,adj[cur].size()){
		if(adj[cur][i]==par)
			continue;
		dfs(adj[cur][i],cur);
		subtree[cur]+=subtree[adj[cur][i]];
	}
	return 0;
}
 
signed main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n,k;
	cin>>n>>k;
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
	set<pii> seti;
	rep(i,n){
		if(subtree[i]==1)
			seti.insert(mp(dep[i],i));
		gg[i]=dep[i];
		foo[i]=subtree[i];
	}
	set<pii>::iterator it;
	int elem,ans=0,par;
	rep(i,k){
		it=seti.end();
		it--;
		elem=it->ss;
		//cout<<elem+1<<endl;
		ans+=it->ff;
		par=paren[elem];
		seti.erase(it);
		gg[par]-=subtree[elem];
		foo[par]-=subtree[elem];
		if(foo[par]==1)
			seti.insert(mp(gg[par],par));
	}

	cout<<ans<<endl;
}