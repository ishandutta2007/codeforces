
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

vector< vi > adj(100009);
double esti[100009];
double subtree[100009];


int dfs(int cur,int prev){
	int i;
	subtree[cur]=1;

	rep(i,adj[cur].size()){

		subtree[cur]+=dfs(adj[cur][i],cur);
	}
	return subtree[cur];
	
}

int dfs2(int cur,int prev){
	int i;
	rep(i,adj[cur].size()){
		esti[adj[cur][i]]=esti[cur]+1+(1.0*(subtree[cur]-subtree[adj[cur][i]]-1))/2;
		// if(cur==0){
		// 	cout<<adj[cur][i]<<"  "<<esti[adj[cur][i]]<<endl;
		// }
		dfs2(adj[cur][i],cur);
	}
	
	return 0;
}


int main(){
	int n,p,i;
	cin>>n;
	f(i,1,n){
		cin>>p;
		p--;

		adj[p].pb(i);
	}
	dfs(0,-1);
	esti[0]=1.0;
	dfs2(0,-1);
	rep(i,n){
		cout<<setprecision(8)<<esti[i]<<" ";
	}
}