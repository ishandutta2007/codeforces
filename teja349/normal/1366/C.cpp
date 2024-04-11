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


int visit[123456];
vector<vi> adj(123456);
int a[123456];
int ones,zero;
int dfs(int node){
	visit[node]=1;
	int i;
	if(a[node])
		ones++;
	else
		zero++;
	rep(i,adj[node].size()){
		if(!visit[adj[node][i]])
			dfs(adj[node][i]);
	}
}
vector<vii> vec(123456);
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n,m;
    	cin>>n>>m;
    	int i,j;
    	rep(i,n+m){
    		vec[i].clear();
    	}
    	rep(i,n){
    		rep(j,m){
    			cin>>a[i*m+j];
    			vec[i+j].pb(mp(i,j));
    		}
    	}
    	rep(i,n*m){
    		adj[i].clear();
    		visit[i]=0;
    	}
    	int k;
    	rep(i,n){
    		rep(j,m){
    			int val=i+j;
    			int req=n-1+m-1-val;
    			rep(k,vec[req].size()){
    				if(vec[req][k].ff>=i && vec[req][k].ss>=j){
    					adj[i*m+j].pb(vec[req][k].ff*m+vec[req][k].ss);
    					adj[vec[req][k].ff*m+vec[req][k].ss].pb(i*m+j);
    				}
    			}
    		}
    	}
    	int ans=0;
    	rep(i,n){
    		rep(j,m){
    			if(!visit[i*m+j]){
    				ones=0;
    				zero=0;
    				dfs(i*m+j);
    				ans+=min(ones,zero);
    			}
    		}
    	}
    	cout<<ans<<endl;
    }
    return 0;   
}