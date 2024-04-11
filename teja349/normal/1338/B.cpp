
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
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
 
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
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
 
 
 int tot=0;
 vector<vi> adj(123456);
 int dep[123456],deg[123456];
int dfs(int cur,int par){
	if(par==-1){
		dep[cur]=0;
	}
	else{
		dep[cur]=dep[par]+1;
	}
	int i;
	int cnt=0,flag=0;
	rep(i,adj[cur].size()){
		if(adj[cur][i]==par)
			continue;
		if(deg[adj[cur][i]]==1){
			flag=1;
			//continue;
		}
		else
			cnt++;
		dfs(adj[cur][i],cur);
	}
	cnt+=flag;
	tot+=cnt;
	return 0;
} 
signed main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	int i;
	cin>>n;
	int u,v,root;
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		deg[u]++;
		deg[v]++;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i,n){
		if(deg[i]>1)
			break;
	}
	root=i;
	int zero=0,one=0;
	dfs(root,-1);
	rep(i,n){
		if(deg[i]==1){
			if(dep[i]%2==0)
				zero=1;
			else
				one=1;
		}
	}
	if(zero==0 || one==0)
		cout<<1<<" "<<tot<<endl;
	else
		cout<<3<<" "<<tot<<endl;
}