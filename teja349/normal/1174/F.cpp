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
 

int remem = 0;
vector<vi> adj(223456);
int subtree[212345],paren[212345][20],big[212345];
int gg[212345],depth[212345];
int getkth(int cur,int k){
	int i;
	fd(i,19,0){
		if((1<<i)<=k){
			k-=(1<<i);
			cur=paren[cur][i];
		}
	}
	return cur;
}
int dfs(int cur,int par){
	int i;
	if(par==-1){
		depth[cur]=0;
	}
	else{
		depth[cur]=depth[par]+1;
	}
	paren[cur][0]=par;
	subtree[cur]=1;
	rep(i,adj[cur].size()){
		if(adj[cur][i]==par)
			continue;
		dfs(adj[cur][i],cur);
		subtree[cur]+=subtree[adj[cur][i]];
	
	}
	int maxi=-1;
	big[cur]=-1;
	rep(i,adj[cur].size()){
		if(adj[cur][i]==par)
			continue;
		if(maxi<subtree[adj[cur][i]]){
			maxi=subtree[adj[cur][i]];
			big[cur]=adj[cur][i];
		}
	}
	gg[cur]=-1;
	if(big[cur]!=-1)
		gg[cur]=gg[big[cur]];
	else
		gg[cur]=cur;
	return 0;
}

int query(int typ,int val){
	if(typ==1)
		cout<<"d ";
	else
		cout<<"s ";
	val++;

	cout<<val<<endl;
	fflush(stdout);
	int x;
	cin>>x;
	if(typ==2)
		x--;
	return x;
}

int printans(int ans){
	cout<<"! "<<ans+1<<endl;
	fflush(stdout);
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	int i;
	int u,v;
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	remem=query(1,0);
	int gao=remem;
	if(remem==0){
		printans(0);
		return 0;
	}
	dfs(0,-1);
	int j;
	f(j,1,20){
		rep(i,n){
			if(paren[i][j-1]==-1){
				paren[i][j]=-1;
			}
			else
				paren[i][j]=paren[paren[i][j-1]][j-1];
		}
	}
	int cur=gg[0];
	while(1){
		remem=query(1,cur);
		int dlca = depth[cur]+gao-remem;
		dlca/=2;
		cur=getkth(cur,depth[cur]-dlca);
		if(gao==dlca)
			break;
		cur=query(2,cur);
		cur=gg[cur];
	}
	printans(cur);
}