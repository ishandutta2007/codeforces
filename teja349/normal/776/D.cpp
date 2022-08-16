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

int roo[123456];
vector <vi> key(123456);
vector <vi> adj(312345);
int counti;
int N=100000;
int visit[312345]={0};  
int dfs(int cur){
	visit[cur]=counti;
	int i;
	rep(i,adj[cur].size()){
		if(!visit[adj[cur][i]]){
			dfs(adj[cur][i]);
		}
	}
	return 0;
}


int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,j,val,room;
	cin>>n>>m;
	f(i,1,n+1){
		cin>>roo[i];
	}
	f(i,1,m+1){
		cin>>val;
		rep(j,val){
			cin>>room;
			key[room].pb(i);
		}

	}
	f(i,1,n+1){
		int haha=key[i][0];
		int lol=key[i][1];
		if(roo[i]==1){
			
			adj[haha].pb(lol);
			adj[N+haha].pb(N+lol);
			adj[lol].pb(haha);
			adj[N+lol].pb(N+haha);



		}
		else{
			adj[haha].pb(N+lol);
			adj[N+haha].pb(lol);
			adj[lol].pb(N+haha);
			adj[N+lol].pb(haha);
		}
	}
	counti=1;
	f(i,1,200010+4){
		if( !visit[i]){
			dfs(i);
			counti++;
		}
	}
	f(i,1,m+1){
		if(visit[i]==visit[N+i]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
}