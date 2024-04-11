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
#define pqueue priority_queue< pii >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
int k;
vector<vi> adj(223456),adje(223456);
int arr[212345]={0},siz[212345]={0};
int dfs(int cur,int par){
	if(arr[cur])
		siz[cur]=1;
	else
		siz[cur]=0;
	int i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs(adj[cur][i],cur);
			siz[cur]+=siz[adj[cur][i]];
		}

	}
	return 0;
}
int centroid(int cur,int par){
	int i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			if(siz[adj[cur][i]]>k){
				return centroid(adj[cur][i],cur);
			}
		}
	}
	return cur;
}
int dfs1(int cur,int par,int loca){
	if(arr[cur])
		adje[loca].pb(cur);
	int i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs1(adj[cur][i],cur,loca);
		}
	}
	return 0;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n,i,u,v,val;
	pii p1,p2;
	cin>>n>>k;
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i,2*k){
		cin>>u;
		u--;
		arr[u]=1;

	}
	dfs(0,-1);
	int cent=centroid(0,-1);
	cout<<1<<endl;
	cout<<cent+1<<endl;
	int counter=0;
	rep(i,adj[cent].size()){

		dfs1(adj[cent][i],cent,counter);
		counter++;
	}

	if(arr[cent]==1){
		adje[counter].pb(cent);
		counter++;
	}
	pqueue pq;
	rep(i,counter){
		val=adje[i].size();
		val--;
		//cout<<val<<endl;
		pq.push(mp(val,i));
	}
	//return 0;
	//cout<<counter<<endl;
	//return 0;

	while(k--){
		
		p1=pq.top();
		pq.pop();
		p2=pq.top();
		pq.pop();
		//cout<<p1.ff<<"  "<<p2.ff<<endl;
		cout<<adje[p1.ss][p1.ff]+1<<" "<<adje[p2.ss][p2.ff]+1<<" "<<cent+1<<endl;
		p1.ff--;
		p2.ff--;
		pq.push(p1);
		pq.push(p2);
	}
	return 0;
	

}