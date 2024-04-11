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

//std::ios::sync_with_stdio(false);   
int dsu[312345];
vector<vi> adj(312345);
int ans[312345];

int find(int u){
	if(dsu[u]<0)
		return u;
	return dsu[u]=find(dsu[u]);
}
int merge(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v)
		return 0;
	if(dsu[u]<dsu[v]){
		dsu[v]=u;
	}
	else if(dsu[v]<dsu[u]){
		dsu[u]=v;
	}
	else{
		dsu[u]=v;
		dsu[v]--;
	}
	return 0;
}
int merger(int u,int v){
	int val;
	if(dsu[u]<dsu[v]){
		dsu[v]=u;
		val=(ans[u]+1)/2 + (ans[v]+1)/2 +1;
		ans[u]=max(ans[u],max(ans[v],val));
	}
	else if(dsu[v]<dsu[u]){
		dsu[u]=v;
		val=(ans[u]+1)/2 + (ans[v]+1)/2 +1;
		ans[v]=max(ans[u],max(ans[v],val));
	}
	else{
		dsu[u]=v;
		dsu[v]--;
		val=(ans[u]+1)/2 + (ans[v]+1)/2 +1;
		ans[v]=max(ans[u],max(ans[v],val));
	}
	return 0;
}
int remem,maxi;
int dfs(int cur,int par,int level){
	if(level>maxi)
	{
		remem=cur;
		maxi=level;
	}
	int i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs(adj[cur][i],cur,level+1);
		}
	}
	return 0;
}
int main(){
    //std::ios::sync_with_stdio(false);
    int n,m,q,u,v,i,j,t;
    cin>>n>>m>>q;
    rep(i,n+10){
    	dsu[i]=-1;
    }
    rep(i,m){
    	scanf("%d %d",&u,&v);
    	//u--;
    	//v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    	merge(u,v);
    }
    f(i,1,n+1){
    	if(dsu[i]<0){
    		maxi=-1;
    		dfs(i,-1,0);
    		maxi=-1;
    		dfs(remem,-1,0);
    		ans[i]=maxi;
    		//seti.insert(i);
    	}
    }
    rep(i,q){
    	scanf("%d",&t);
    	if(t==1){
    		scanf("%d",&u);
    		printf("%d\n",ans[find(u)]);
    	}
    	else{
    		scanf("%d %d",&u,&v);
    		u=find(u);
    		v=find(v);
    		if(u==v)
    			continue;
    		merger(u,v);
    	}

    }
    return 0;
}