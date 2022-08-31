
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


vi vec;
int pre[123456],goal[123456];
vector< vi > adj(123456);

int dfs(int cur,int parent,int level,int odd,int even){
	int i=cur;
	if(level%2==0 && even==0){
		if(pre[i]!=goal[i]){
			even=1;
			vec.pb(i);
			pre[i]=goal[i];
		}

	}
	else if(level%2==0 && even==1){
		if(pre[i]==goal[i]){
			vec.pb(i);
			even=0;
			pre[i]=goal[i];
		}

	}
	else if(level%2==1 && odd==1){
		if(pre[i]==goal[i]){
			vec.pb(i);
			odd=0;
			pre[i]=goal[i];
		}

	}
	else if(level%2==1 && odd==0){
		if(pre[i]!=goal[i]){
			vec.pb(i);
			odd=1;
			pre[i]=goal[i];
		}

	}
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=parent)
			dfs(adj[cur][i],cur,level+1,odd,even);
	}
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
	rep(i,n){
		cin>>pre[i];
	}
	rep(i,n){
		cin>>goal[i];
	}
	dfs(0,-1,0,0,0);
	cout<<vec.size()<<endl;
	rep(i,vec.size()){
		cout<<vec[i]+1<<endl;
	}
}