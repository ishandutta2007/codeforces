
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
int waste[123456]={0};
int color[123456];
vector< vi > adj(123456);
int dfs(int cur,int prev){
	int i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			dfs(adj[cur][i],cur);
		}
	}
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			if(waste[adj[cur][i]] || color[adj[cur][i]]!=color[cur]){
				waste[cur]=1;
			}

		}
	}

	return 0;
}
int dfs2(int cur,int prev){
	int val;
	if(prev==-1)
		val=0;
	else 
		val=1;
	int i,countgood=0;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			if(!waste[adj[cur][i]])
				countgood++;

		}
	}
	//cout<<countgood<<endl;
	// if(cur==1){
	// 	cout<<"dads"<<countgood+val<<endl;
	// }
	if(countgood+val == adj[cur].size()){

		cout<<"YES"<<endl;
		cout<<cur+1<<endl;
		exit(0);
	}

	if(countgood+1+val<adj[cur].size()){
		return 0;
	}
	if(prev!=-1){
		if(color[cur]!=color[prev])
			return 0;

	}

	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			if(waste[adj[cur][i]]){
				//cout<<"gfdfsd";
				val=adj[cur][i];
			}
			else{
				if(color[adj[cur][i]]!=color[cur]){

					return 0;
				}
			}
		}
	}

	dfs2(val,cur);
	return 0;


}
int main(){
	std::ios::sync_with_stdio(false);
	int n,i,u,v;
	cin>>n;
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	//cout<<"dasasd";
	rep(i,n){
		cin>>color[i];
	}
	//cout<<"dfssfd";
	dfs(0,-1);
	// rep(i,n){
	// 	cout<<waste[i]<<endl;
	// }
	//return 0;
	dfs2(0,-1);
	cout<<"NO"<<endl;
}