
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
//std::ios::sync_with_stdio(false);   


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

vector<vi> adj(123456),cost(123456);
int valued[123456];
vi vec;


int dfs(int cur,int prev){
	int ans=1,i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			valued[adj[cur][i]]=cost[cur][i];
			int val=dfs(adj[cur][i],cur);
			ans*=val;
		}
	}
	if(ans==0){
		return 0;
	}
	else if(valued[cur]==2){
		vec.pb(cur);
		return 0;
	}
	return 1;

}



int main(){
	std::ios::sync_with_stdio(false);   

	int n,u,v,c,i;
	cin>>n;
	rep(i,n-1){
		cin>>u>>v>>c;
		u--;
		v--;
		adj[u].pb(v);
		cost[u].pb(c);
		cost[v].pb(c);
		adj[v].pb(u);
	}
	valued[0]=1;
	dfs(0,-1);
	cout<<vec.size()<<endl;
	rep(i,vec.size()){
		cout<<vec[i]+1<<" ";
	}

}