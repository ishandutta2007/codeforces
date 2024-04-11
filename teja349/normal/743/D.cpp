
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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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
ll infff;
vector<vl> adj(220000);
ll cost[220000],subtreemax[220000],subtree[220000];

ll maximu;
ll dfs(int cur,int prev){
	ll i;
	subtree[cur]=cost[cur];
	subtreemax[cur]=infff;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			subtree[cur]+=dfs(adj[cur][i],cur);

			if(subtreemax[cur]<subtreemax[adj[cur][i]])
				subtreemax[cur]=subtreemax[adj[cur][i]];
		}
	}

	if(subtreemax[cur]<subtree[cur])
		subtreemax[cur]=subtree[cur];
	//if(cur==3)
	//	cout<<subtree[3]<<"Dsads"<<endl;
	return subtree[cur];
}


ll dfs2(int cur,int prev){
	ll i,max1=infff,max2=infff;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			ll val=subtreemax[adj[cur][i]];
			if(val>max1){
				max2=max1;
				max1=val;
			}
			else if(val>max2){
				max2=val;
			}
			dfs2(adj[cur][i],cur);
		}
		
	}
	if(max1!=infff&&max2!=infff){
		if(maximu<max1+max2){
			maximu=max1+max2;
		}
	}
}
int main(){
	//std::ios::sync_with_stdio(false);   
	infff=inf;
	infff=infff*infff*(-1);
	maximu=infff;
	ll n,i,u,v;
	cin>>n;
	rep(i,n){
		cin>>cost[i];

	}
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0,-1);

	dfs2(0,-1);
	//cout<<"hii";
	fflush(stdout);
	if(maximu==infff){
		cout<<"Impossible";
		return 0;
	}
	//cout<<subtreemax[3]<<endl;
	cout<<maximu<<endl;
}