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
#define int ll
int l,s;
vii vec;
vii::iterator it;
int dist[123456],lev[123456],dp[123456],mini[123456],w[123456],haha[123456];
vector<vi> adj(123456);
int dfs(int cur,int par){
	int i;
	if(cur==0){
		dist[cur]=w[cur];
		vec.pb(mp(0,cur));
		lev[cur]=1;
	}
	else{
		dist[cur]=w[cur]+dist[par];
		vec.pb(mp(dist[par],cur));
		lev[cur]=lev[par]+1;
	}
	it=lower_bound(all(vec),mp(dist[cur]-s,-1LL));
	haha[cur]=min(lev[cur]-lev[it->ss]+1,l);
	//cout<<dist[cur]<<" "<<cur<<" "<<it->ss<<endl;
	rep(i,adj[cur].size()){
		dfs(adj[cur][i],cur);
	}
	rep(i,adj[cur].size()){
		dp[cur]+=dp[adj[cur][i]];
		mini[cur]=max(mini[cur],mini[adj[cur][i]]);
	}
	if(mini[cur]==0){
		dp[cur]++;
		mini[cur]=haha[cur];
	}
	mini[cur]--;
	vec.pop_back();
}
int p[123456];
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n>>l>>s;
    int i;
    rep(i,n){
    	cin>>w[i];
    	if(w[i]>s){
    		cout<<-1<<endl;
    		return 0;
    	}
    }
    f(i,1,n){
    	cin>>p[i];
    	p[i]--;
    	adj[p[i]].pb(i);
    }
    dfs(0,-1);  
    cout<<dp[0]<<endl;
    return 0;   
}