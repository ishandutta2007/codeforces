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
#define pdqueue priority_queue< pii,vii ,greater< pii > >

//std::ios::sync_with_stdio(false);   
vector<vi> adj(123456);
pdqueue pq;
int typ[123456],outdeg[123456];
int dfs(int u){
	
	int i;
	rep(i,adj[u].size()){
		if(typ[adj[u][i]]||!typ[u]){
			outdeg[adj[u][i]]--;
			if(!outdeg[adj[u][i]]){
				pq.push(mp(typ[adj[u][i]],adj[u][i]));
				dfs(adj[u][i]);
			}
		}
	}
	return 0;
}
int dfsmain(int u){
	//cout<<"das";
	//pq.push(mp(typ[u],u));
	int i;
	rep(i,adj[u].size()){
		if(!typ[adj[u][i]]){
			//cout<<"Dasd";
			outdeg[adj[u][i]]--;
			if(!outdeg[adj[u][i]]){
				pq.push(mp(typ[adj[u][i]],adj[u][i]));
				dfs(adj[u][i]);
			}
		}
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i,u,v;
    rep(i,n){
    	cin>>typ[i];
    }
    rep(i,m){
    	cin>>u>>v;
    	adj[v].pb(u);
    	outdeg[u]++;
    }
    vi vec;
    rep(i,n){
    	if(!outdeg[i]){
    		//cout<<i<<"dasds"<<endl;
    		pq.push(mp(typ[i],i));
    		vec.pb(i);
    	}
    }
    rep(i,vec.size()){
    	dfs(vec[i]);
    }
    vec.clear();
    int counter=0;
    while(!pq.empty()){
    	pii papa=pq.top();
    	
    	//cout<<papa.ff<<" "<<papa.ss<<endl;
    	if(papa.ff==0){
    		pq.pop();
    		//dfs(papa.ss);
    		
    		continue;
    	}
    	while(!pq.empty()){
    		vec.pb((pq.top()).ss);
    		pq.pop();
    	}
    	rep(i,vec.size()){
    		dfsmain(vec[i]);
    	}
    	counter++;
    	vec.clear();
    }
    cout<<counter<<endl;
    return 0;  
    
}