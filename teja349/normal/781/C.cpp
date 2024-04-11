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
vector<vi> adj(212345);
int ans[512345];
int visit[212345]={0}; 
int counti=0;
int dfs(int cur){

	visit[cur]=1;
	ans[counti++]=cur;
	int i;
	rep(i,adj[cur].size()){
		if(!visit[adj[cur][i]]){
			dfs(adj[cur][i]);
			ans[counti++]=cur;
		}
	}
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,u,v,k;
	cin>>n>>m>>k;
	int i,lol=0;
	rep(i,m){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0);
	int val=2*n;
	int haha=val/k;
	if(val%k)
		haha++;
	//cout<<counti<<endl;
	i=0;
	int clone=1;
	cout<<min(haha,counti)<<" ";
	rep(i,counti){

		if(lol==haha )
		{
			clone++;
			lol=0;
			cout<<endl;
			cout<<min(haha,counti-i)<<" ";
		}
		lol++;
		cout<<ans[i]+1<<" ";
	}
	cout<<endl;

	f(i,clone,k){
		cout<<1<<" "<<1<<endl;
	}


	



}