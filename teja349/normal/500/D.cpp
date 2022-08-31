
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
ll n;
vector< vi > adj(123456),indexx(123456);
ll nyum[123456],subtree[123456];



int dfs(int cur,int prev){
	ll i,x;
	subtree[cur]=1;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			x=dfs(adj[cur][i],cur);
			subtree[cur]+=x;
			nyum[indexx[cur][i]]=(x)*(n-x);

		}
	}
	return subtree[cur];

}




int main(){
	std::ios::sync_with_stdio(false);
	ll i,u,v;
	double cost[123456],sum=0,mult=1;

	cin>>n;
	mult=n*(n-1);
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
		indexx[u].pb(i);
		indexx[v].pb(i);
		cin>>cost[i];
	}
	dfs(0,-1);
	rep(i,n-1){
		sum+=nyum[i]*cost[i];
	}
	int q;
	cin>>q;
	rep(i,q){
		ll j,val;
		cin>>j>>val;
		sum+=nyum[j-1]*(val-cost[j-1]);
		cost[j-1]=val;
		cout<<setprecision(8)<<(sum*6)/mult<<endl;
	}
	return 0;
}