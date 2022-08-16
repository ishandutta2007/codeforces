
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
ll subtree[123456][2],a[123456];
vector < vi > adj(123456);
ll ans;
int dfs(int cur,int prev){
	subtree[cur][0]=0;
	subtree[cur][1]=0;
	int val=a[cur]&1,i;

	
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			dfs(adj[cur][i],cur);
			subtree[cur][0]+=subtree[adj[cur][i]][0^val];
			subtree[cur][1]+=subtree[adj[cur][i]][1^val];
		}
	}
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			ans+=subtree[adj[cur][i]][0]*(subtree[cur][1]-subtree[adj[cur][i]][1^val]);
			ans+=subtree[adj[cur][i]][1]*(subtree[cur][0]-subtree[adj[cur][i]][0^val]);
		}
	}
	subtree[cur][val]++;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			ans+=2*subtree[adj[cur][i]][0]*val;
			ans+=2*subtree[adj[cur][i]][1]*(1^val);
		}
	}
	a[cur]/=2;
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,i,u,v;
	ll sumi1=0;
	cin>>n;
	rep(i,n){
		cin>>a[i];
		sumi1+=a[i];
	}
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ll sumi=0;
	rep(i,25){
		ans=0;
		dfs(0,-1);
		//return 0;
		//cout<<ans<<endl;
		sumi+=ans*(1<<i);
	}

	//cout<<sumi<<" as   d"<<(2<<0)endl;
	cout<<sumi/2 + sumi1<<endl;
}