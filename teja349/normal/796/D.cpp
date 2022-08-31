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
vector<vi> adj(312345),edge(312345);
int haha[312345],papa[312345],a[312345];
int dfs1(int cur,int par){
	int i;
	haha[cur]=inf;
	if(a[cur]==1)
		haha[cur]=0;

	rep(i,adj[cur].size()){
		if(adj[cur][i]==par)
			continue;
		dfs1(adj[cur][i],cur);
	}
	rep(i,adj[cur].size()){
		if(adj[cur][i]==par)
			continue;
		haha[cur]=min(haha[cur],haha[adj[cur][i]]+1);
	}
	return 0;

}

int dfs2(int cur,int par){
	int i,lol,dist=inf,value;
	//maama++;
	//cout<<"yoo   "<<cur<<endl;
	rep(i,adj[cur].size()){
		if(adj[cur][i]==par){
			lol=i;
			continue;
		}
		if(haha[adj[cur][i]]<dist){
			dist=haha[adj[cur][i]];
			value=i;
		}

	}

	if((par!=-1) ){
		if(haha[par]<dist){
			dist=haha[par];
			value=lol;
		}
	}

	if(a[cur]!=1){
		//cout<<value<<" "<<cur<<endl;
		papa[edge[cur][value]]=1;
		haha[cur]=dist+1;
	}
	//cout<<cur<<endl;
	
	rep(i,adj[cur].size()){
		//cout<<par<<endl;
		if(adj[cur][i]==par)
			continue;
		dfs2(adj[cur][i],cur);
	}
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,k,d;
	cin>>n>>k>>d;
	int i,val,u,v,root;
	rep(i,k){
		cin>>val;
		val--;
		a[val]=1;
		root=val;
	}
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		edge[u].pb(i);
		adj[v].pb(u);
		edge[v].pb(i);
	}
	dfs1(root,-1);
	dfs2(root,-1);
	int lol=0;
	rep(i,n-1){
		if(!papa[i]){
			lol++;
		}
	}
	cout<<lol<<endl;
	rep(i,n-1){
		if(!papa[i]){
			cout<<i+1<<" ";
		}
	}
}