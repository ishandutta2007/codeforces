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
ll extend_gcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll x1,y1;
	ll ans =extend_gcd(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;

	return ans;
}
ll inv(ll val){
	ll x,y;
	//cout<<val<<endl;
	extend_gcd(mod,val,x,y);
	y%=mod;
	y+=mod;
	y%=mod;
	return y;
}

ll dp[123456][2];
vector<vi> adj(123456);
int bb[123456];

int dfs(int cur,int par){
	if(adj[cur].size()==1 && par!=-1){
		if(bb[cur])
			dp[cur][1]=1;
		else
			dp[cur][0]=1;
		return 0;
	}
	//return 0;
	int i;
	ll val;
	rep(i,adj[cur].size()){
		if(adj[cur][i]==par)
			continue;
		dfs(adj[cur][i],cur);
	}
	//cout<<cur<<endl;
	if(bb[cur]==1){
		dp[cur][1]=1;
		rep(i,adj[cur].size()){
			if(adj[cur][i]==par)
				continue;
			val=adj[cur][i];
			dp[cur][1]*=(dp[val][0]+dp[val][1])%mod;
			dp[cur][1]%=mod;
		}
		dp[cur][0]=0;
		return 0;
	}
	else{
		dp[cur][0]=1;
		rep(i,adj[cur].size()){
			if(adj[cur][i]==par)
				continue;
			val=adj[cur][i];
			dp[cur][0]*=(dp[val][0]+dp[val][1])%mod;
			dp[cur][0]%=mod;
		}
		rep(i,adj[cur].size()){
			if(adj[cur][i]==par)
				continue;
			val=adj[cur][i];
			
			dp[cur][1]+=(inv((dp[val][0]+dp[val][1])%mod)*dp[val][1])%mod;
			dp[cur][1]%=mod;
		}
		dp[cur][1]*=dp[cur][0];
		dp[cur][1]%=mod;
	}
	return 0;

}
int main(){
    std::ios::sync_with_stdio(false);
   	int n;
   	cin>>n;
   	int u,i;
   	rep(i,n-1){
   		cin>>u;
   		adj[i+1].pb(u);
   		adj[u].pb(i+1);
   	}
   	rep(i,n){
   		cin>>bb[i];
   	}
   	//return 0;
   	dfs(0,-1);
   	cout<<dp[0][1]<<endl;
    
}