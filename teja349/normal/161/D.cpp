
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

int n,k;
ll sum=0;
int lev[60000]={0};
int nyum[50004][505]={0};
vector< vi > adj(51000);
int dfs(int cur,int prev,int level){
	int i,j;
	lev[cur]=level;
	nyum[cur][0]=1;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			dfs(adj[cur][i],cur,level+1);
			int val=adj[cur][i];
			rep(j,k+2){
				nyum[cur][j+1]+=nyum[val][j];
			}
		}

	}
	return 0;
}

int dfs2(int cur,int prev){
	int i,j;
	ll sum1=0;
	sum+=nyum[cur][k];
	rep(j,adj[cur].size()){
		if(adj[cur][j]!=prev){
			int val=adj[cur][j];
			rep(i,k-1){
				sum1+=nyum[val][i]*(nyum[cur][k-1-i]-nyum[val][k-2-i]);
				//cout<<sum1<<endl;
			}
			dfs2(val,cur);
		}
	}
	sum+=sum1/2;
	//cout<<nyum[1][1]<<endl;
}

int main(){
	std::ios::sync_with_stdio(false); 
	int i,u,v;
	cin>>n>>k;
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0,-1,0);
	dfs2(0,-1);
	cout<<sum<<endl;

}