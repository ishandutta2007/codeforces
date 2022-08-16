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
vector< vi > adj(123456);
int a[123456],visit[123456];
ll cnt,ans=0;
//std::ios::sync_with_stdio(false);   
int dfs(int cur){
	visit[cur]=1;
	int i;
	cnt=min(cnt,(ll)a[cur]);
	rep(i,adj[cur].size()){
		if(!visit[adj[cur][i]])
			dfs(adj[cur][i]);
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int i,x,y;
	rep(i,n){
		cin>>a[i];
	}    
	rep(i,m){
		cin>>x>>y;
		x--;
		y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	rep(i,n){
		if(!visit[i]){
			cnt=inf;
			dfs(i);
			ans+=cnt;
		}
	}
	cout<<ans<<endl;
    return 0;  
    
}