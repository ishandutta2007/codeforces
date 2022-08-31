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
vector<vl> adj(212345),cost(212345);
ll dist[212345];
set<pll> seti;

ll relax(ll cur){
	ll i,v;
	rep(i,adj[cur].size()){
		v=adj[cur][i];
		if(dist[v]>dist[cur]+cost[cur][i]){
			seti.erase(mp(dist[v],v));
			dist[v]=dist[cur]+cost[cur][i];
			seti.insert(mp(dist[v],v));
		}
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    ll i,j,u,v,w;
    rep(i,m){
    	cin>>u>>v>>w;
    	u--;
    	v--;
    	w*=2;
    	adj[u].pb(v);
    	adj[v].pb(u);
    	cost[u].pb(w);
    	cost[v].pb(w);
    }
    rep(i,n){
    	cin>>w;
    	adj[n].pb(i);
    	adj[i].pb(n);
    	cost[n].pb(w);
    	cost[i].pb(w);
    }
    ll iinf=inf;
    iinf*=inf;
    rep(i,n){
    	dist[i]=iinf;
    	seti.insert(mp(dist[i],i));
    }
    dist[n]=0;
    pll papa;
    set<pll>::iterator it;
    seti.insert(mp(0,n));
    while(!seti.empty()){
    	it=seti.begin();
    	papa=*it;
    	seti.erase(it);
    	relax(papa.ss);
    }
    rep(i,n){
    	cout<<dist[i]<<" ";
    }
    return 0;  
    
}