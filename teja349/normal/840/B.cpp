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
int d[312345],visit[312345],haha[312345],par[312345],act[312345];
vector<vi> adj(312345),edge(312345);
int change(int cur){
	if(cur>0){
		if(d[cur]!=-1){
			d[cur]^=1;
		}
	}
	return 0;
}   
int dfs(int cur){
	int i;
	visit[cur]=1;
	rep(i,adj[cur].size()){
		if(!visit[adj[cur][i]]){
			par[adj[cur][i]]=cur;
			haha[adj[cur][i]]=edge[cur][i];
			dfs(adj[cur][i]);
			//flag=1;
		}

	}
	
	if(d[cur]==1){
		act[cur]=1;
		change(par[cur]);
	}

	

	return 0;
}

int main(){
   // std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i,val=1,u,v;
    f(i,1,n+1){
    	scanf("%d",&d[i]);
    	if(d[i]==-1){
    		val=i;
    	}
    }

    rep(i,m){
    	scanf("%d%d",&u,&v);
    	adj[u].pb(v);
    	edge[u].pb(i);
    	adj[v].pb(u);
    	edge[v].pb(i);
    }
    dfs(val);
    if(d[val]==1){
    	cout<<-1<<endl;
    	return 0;
    }
    else{
    	int sumi=0;
    	f(i,1,n+1){
    		sumi+=act[i];
    	}
    	cout<<sumi<<endl;
    	f(i,1,n+1){
    		if(act[i])
    			printf("%d\n",haha[i]+1);
    	}
    }
   

    return 0;      

}