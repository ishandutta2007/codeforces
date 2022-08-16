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
int gg[212345],dp[212345];
vector<vi> adj(312345);
int dfs(int cur){
	int i;
	dp[cur]=1;
	rep(i,adj[cur].size()){
		dfs(adj[cur][i]);
		dp[cur]*=(dp[adj[cur][i]]+2);
		dp[cur]%=mod;
	}
	dp[cur]--;
	dp[cur]%=mod;
	dp[cur]+=mod;
	dp[cur]%=mod;
	return 0;
}
int p[312345],pre[312345],post[312345];

int dfs1(int cur){
	int i,boo;
	if(p[cur]==-1){
		boo=-1;
	}
	else{
		boo=dp[p[cur]];
	}
	gg[cur]=dp[cur]+1;
	gg[cur]*=(boo+2);
	gg[cur]--;
	gg[cur]%=mod;
	gg[cur]+=mod;
	gg[cur]%=mod;
	pre[0]=1;
	rep(i,adj[cur].size()){
		pre[i+1]=pre[i]*(dp[adj[cur][i]]+2);
		pre[i+1]%=mod;
	}
	post[adj[cur].size()]=1;
	fd(i,(int)adj[cur].size()-1,0){
		post[i]=post[i+1]*(dp[adj[cur][i]]+2);
		post[i]%=mod;
	}
	vi fuck;
	rep(i,adj[cur].size()){
		dp[cur]=pre[i]*post[i+1];
		dp[cur]%=mod;
		dp[cur]*=(boo+2);
		dp[cur]%=mod;
		dp[cur]--;
		dp[cur]%=mod;
		dp[cur]+=mod;
		dp[cur]%=mod;
		fuck.pb(dp[cur]);
	}
	rep(i,adj[cur].size()){
		dp[cur]=fuck[i];
		dfs1(adj[cur][i]);
	}
	return 0;
}
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    f(i,1,n){
    	cin>>p[i];
    	p[i]--;
    	adj[p[i]].pb(i);
    }
    p[0]=-1;
    dfs(0);
    //cout<<dp[0]<<endl;
    dfs1(0);
    rep(i,n){
    	gg[i]++;
    	gg[i]%=mod;
    	cout<<gg[i]<<endl;
    }
    return 0;   
}