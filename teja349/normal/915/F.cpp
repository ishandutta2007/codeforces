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
int dsu[1234567],a[1234567];
vector<vi> adj(1234567); 
int paren(int u){
	if(dsu[u]<0)return u;
	dsu[u]=paren(dsu[u]);
	return dsu[u];
}
ll ans=0,value=0;
int merge(int u,int v){
	u=paren(u);
	v=paren(v);
	if(u==v)
		return 0;
	ans+=value*dsu[u]*dsu[v];
	if(dsu[u]<dsu[v]){
		swap(u,v);
	}
	dsu[v]+=dsu[u];
	dsu[u]=v;
	return 0;
}
vll vec;
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j,u,v;
    rep(i,n){
    	cin>>a[i];
    	vec.pb(mp(a[i],i));
    	dsu[i]=-1;
    }
    sort(all(vec));
    rep(i,n-1){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    int cur;
    rep(i,vec.size()){
    	value=vec[i].ff;
    	cur=vec[i].ss;
    	//ans++;
    	rep(j,adj[cur].size()){
    		if(a[adj[cur][j]]<=a[cur]){
    			
    			merge(cur,adj[cur][j]);
    			//cout<<cur<<" "<<adj[cur][j]<<" "<<ans<<endl;
    		}
    	}
    }
    ll addo=ans;
    rep(i,n){
    	dsu[i]=-1;
    }
    ans=0;
    fd(i,vec.size()-1,0){
    	value=vec[i].ff;
    	cur=vec[i].ss;
    	rep(j,adj[cur].size()){
    		if(a[adj[cur][j]]>=a[cur]){

    			merge(cur,adj[cur][j]);
    		}
    	}
    }
    //cout<<addo<<endl;
    cout<<addo-ans<<endl;

    return 0;  
    
}