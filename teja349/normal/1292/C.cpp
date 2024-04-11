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

int paren[3123][3123],subtree[3123],lca[3123][3123];
vector<vi> adj(3123);

int dep[3123];
int dfs(int cur,int par){
	int i;
	paren[cur][0]=par;
	subtree[cur]=1;
	if(par==-1)
		dep[cur]=0;
	else
		dep[cur]=dep[par]+1;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs(adj[cur][i],cur);
			subtree[cur]+=subtree[adj[cur][i]];
		}
	}
	return 0;
}
int allparen(int cur){
	int gg=cur;
	int i=0;
	while(gg!=-1){
		gg=paren[gg][0];
		paren[cur][i]=gg;
		i++;
	}
	return 0;
}
int getparen(int p,int d){
	if(d<0)
		return p;
	return paren[p][d];
}
int dfslca(int haha,int gg,int cur,int previ){
	int i;
	lca[haha][cur]=gg;
	rep(i,adj[cur].size()){
		if(adj[cur][i]==previ)
			continue;
		if(adj[cur][i]==paren[cur][0])
			continue;
		dfslca(haha,gg,adj[cur][i],previ);
	}
	return 0;
}

int alllca(int cur){
	int gg=cur;
	int previ=-1;
	while(gg!=-1){
		dfslca(cur,gg,gg,previ);
		previ=gg;
		gg=paren[gg][0];
	}	
	assert(previ==0);
	return 0;
}
int dp[3123][3123],visit[3123][3123];
int getdist(int p,int q){
	return dep[p]+dep[q]-2*dep[lca[p][q]];

}
int n;
int compute(int p,int q){
	if(p==q)
		return 0;
	if(visit[p][q])
		return dp[p][q];
	visit[p][q]=1;
	int dd=getdist(p,q);
	if(lca[p][q]==q){
		
		dp[p][q]=compute(q,p);
	}
	else if(lca[p][q]==p){
		dp[p][q]=max(compute(p,paren[q][0]),compute(getparen(q,dd-2),q));
		dp[p][q]+=subtree[q]*(n-subtree[getparen(q,dd-2)]);
	}
	else{
		dp[p][q]=max(compute(p,paren[q][0]),compute(paren[p][0],q));
		dp[p][q]+=subtree[q]*subtree[p];
	}
	return dp[p][q];
}
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin>>n;
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
    rep(i,n){
    	allparen(i);
    }
    rep(i,n){
    	alllca(i);
    }
    int maxi=0;
    int j;
    rep(i,n){
    	rep(j,n){
    		maxi=max(maxi,compute(i,j));
    		// if(i<j)
    		// 	cout<<i+1<<" "<<j+1<<": "<<compute(i,j)<<endl;
    	}
    }
    cout<<maxi<<endl;
    return 0;   
}