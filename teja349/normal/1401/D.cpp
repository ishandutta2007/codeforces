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

int n;
vector<vi> adj(123456);
vi gg;
int subtree[123456];
int dfs(int node,int par){
	int i;
	subtree[node]=1;
	rep(i,adj[node].size()){
		if(adj[node][i]==par)
			continue;
		dfs(adj[node][i],node);
		subtree[node]+=subtree[adj[node][i]];
		gg.pb(subtree[adj[node][i]] * (n-subtree[adj[node][i]]));
	}
	return 0;
}
int b[123456];
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	cin>>n;
    	int i;
    	rep(i,n){
    		adj[i].clear();
    	}
    	int u,v;
    	rep(i,n-1){
    		cin>>u>>v;
    		u--;
    		v--;
    		adj[u].pb(v);
    		adj[v].pb(u);
    	}
    	gg.clear();
    	dfs(0,-1);
    	int m;
    	cin>>m;
    	rep(i,m){
    		cin>>b[i];
    	}
    	if(m<n-1){
    		f(i,m,n-1){
    			b[i]=1;
    		}
    		m=n-1;
    	}
    	sort(all(gg));
    	sort(b,b+m);
    	int val=1;
    	f(i,n-1,m){
    		b[n-2]*=b[i];
    		b[n-2]%=mod;
    	}
    	int ans=0;
    	rep(i,n-1){
    		gg[i]%=mod;
    		ans+=gg[i]*b[i];
    		ans%=mod;
    	}
    	cout<<ans<<endl;

    }
    return 0;   
}