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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<vi> adj(12345);
int dep[12345];
int dfs(int cur,int par){
	int i;
	if(par==0)
		dep[cur]=1;
	else
		dep[cur]=dep[par]+1;
	rep(i,adj[cur].size()){
		if(adj[cur][i]==par)
			continue;
		dfs(adj[cur][i],cur);
	}
	return 0;
}
int a[1234],b[1234];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n;
    	int i;
    	cin>>n;
    	rep(i,n+3){
    		adj[i].clear();
    	}
    	int u,v;
    	rep(i,n-1){
    		cin>>u>>v;
    		adj[u].pb(v);
    		adj[v].pb(u);
    	}
    	int k1,k2;
    	cin>>k1;
    	rep(i,k1){
    		cin>>a[i];
    	}
    	cin>>k2;
    	rep(i,k2){
    		cin>>b[i];
    	}
    	cout<<"B "<<b[0]<<endl;
    	fflush(stdout);
    	cin>>u;
    	rep(i,k1){
    		if(a[i]==u){
    			break;
    		}
    	}
    	if(i!=k1){
    		cout<<"C "<<u<<endl;
    		fflush(stdout);
    		continue;
    	}
    	dfs(u,0);
    	int val=0;
    	rep(i,k1){
    		if(dep[a[i]]<dep[a[val]]){
    			val=i;
    		}
    	}
    	cout<<"A "<<a[val]<<endl;
    	fflush(stdout);
    	cin>>u;
    	rep(i,k2){
    		if(b[i]==u){
    			break;
    		}
    	}
    	if(i!=k2){
    		cout<<"C "<<a[val]<<endl;
    		fflush(stdout);
    	}
    	else{
    		cout<<"C "<<-1<<endl;
    		fflush(stdout);
    	}



    }
    return 0;   
}