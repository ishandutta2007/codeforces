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
ll haha[212345][6]={0};
ll lol[212345][6]={0};
vector< vi > adj(212345);
int k;
ll answ=0;

int mergech(int ch,int par){
	int i;
	rep(i,k-1){
		haha[par][i+1]+=haha[ch][i];
		lol[par][i+1]+=lol[ch][i];
	}
	haha[par][0]+=haha[ch][k-1];
	lol[par][0]+=haha[ch][k-1]+lol[ch][k-1];
	return 0;
}

int dfs(int cur,int par){
	int i;
	haha[cur][0]=1;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs(adj[cur][i],cur);
		}
	}

	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			mergech(adj[cur][i],cur);
		}
	}
	return 0;
}

int adder(int node){
	int i;
	f(i,1,k){
		answ+=lol[node][i]+haha[node][i];
	}
	answ+=lol[node][0];
	return 0;
}

int propagate(int ch,int par){
	int i;
	ll d1[10],d2[10];
	rep(i,k){
		d1[i]=haha[par][i];
		d2[i]=lol[par][i];
	}
	rep(i,k-1){
		haha[par][i+1]-=haha[ch][i];
		lol[par][i+1]-=lol[ch][i];
	}
	haha[par][0]-=haha[ch][k-1];
	lol[par][0]-=haha[ch][k-1]+lol[ch][k-1];
	mergech(par,ch);
	rep(i,k){
		haha[par][i]=d1[i];
		lol[par][i]=d2[i];
	}
	return 0;
}
int dfs2(int cur,int par){
	int i;
	adder(cur);
	//cout<<answ<<endl;
	rep(i,adj[cur].size()){
		if(adj[cur][i]==par)
			continue;
		propagate(adj[cur][i],cur);
	}
	rep(i,adj[cur].size()){
		if(adj[cur][i]==par)
			continue;
		dfs2(adj[cur][i],cur);
	}

}

int main(){
	std::ios::sync_with_stdio(false);
	int n,i,u,v;
	cin>>n>>k;
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0,-1);
	dfs2(0,-1);
	cout<<answ/2<<endl;
}