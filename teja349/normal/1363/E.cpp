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

int bad[212345],a[212345],b[212345],c[212345],mini[212345];
pii subtree[212345];
vector<vi> adj(212345);
int tot=0;
int dfs(int cur,int par){
	int i;
	if(b[cur]!=c[cur]){
		if(c[cur])
			subtree[cur].ff=1;
		else
			subtree[cur].ss=1;
	}
	if(par==-1){
		mini[cur]=a[cur];
	}	
	else{
		mini[cur]=min(mini[par],a[cur]);
	}
	//subtree[cur]=bad[cur];	
	rep(i,adj[cur].size()){
		if(adj[cur][i]==par)
			continue;
		dfs(adj[cur][i],cur);
		subtree[cur].ff+=subtree[adj[cur][i]].ff;
		subtree[cur].ss+=subtree[adj[cur][i]].ss;
	}
	int mew=min(subtree[cur].ff,subtree[cur].ss);
	tot+=mini[cur]*mew*2;
	subtree[cur].ff-=mew;
	subtree[cur].ss-=mew;
	
	return 0;
}

main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    int cnt=0;
    rep(i,n){
    	cin>>a[i]>>b[i]>>c[i];
    	if(b[i]==1)
    		cnt++;
    	if(c[i]==1)
    		cnt--;
    }
    if(cnt!=0){
    	cout<<-1<<endl;
    	return 0;
    }
    int u,v;
    rep(i,n-1){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs(0,-1);
    cout<<tot<<endl;
    return 0;   
}