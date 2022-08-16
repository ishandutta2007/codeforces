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
int x[12345],y[12345];
vector<vi> adj(123456),adj1(123456);
int visit[123456],dist[123456],n,m;
int bfs(int cur){
	deque<int> q;
	q.push_front(cur);

	dist[cur]=0;
	int value,i;
	while(!q.empty()){
		value=q.front();
		q.pop_front();
		if(visit[value]==1){
			continue;
		}
		//cout<<value<<" boo"<<endl;
		visit[value]=1;
		//lol=value;
		rep(i,adj[value].size()){
			if(!visit[adj[value][i]]){
				dist[adj[value][i]]=min(dist[adj[value][i]],dist[value]);
				q.push_front(adj[value][i]);
			}
		}
		rep(i,adj1[value].size()){
			if(!visit[adj1[value][i]]){
				dist[adj1[value][i]]=min(dist[adj1[value][i]],dist[value]+1);
				q.push_back(adj1[value][i]);
			}
		}

	}
	return 0;
}
map<pii,int> mapi;
int valid(int u,int v){
	if(u<1 || u>n|| v<1 || v>m)
		return 0;
	if(mapi.find(mp(u,v))!=mapi.end())
		return 1;
	return 0;
}
int validro(int u){
	if(u<1 || u>n)
		return 0;
	return 1; 
}
int validco(int u){
	if(u<1 || u>m)
		return 0;
	return 1; 
}
int rownum[12345],colnum[12345];
int main(){
    std::ios::sync_with_stdio(false);
    int k;
    cin>>n>>m>>k;
    int i,u,v;
    int src;
    rep(i,k){
    	cin>>u>>v;
    	dist[i]=inf;
    	mapi[mp(u,v)]=i;
    	x[i]=u;
    	y[i]=v;
    	if(u==1 && v==1)
    		src=i;
    	//row[u].pb(v);
    	//col[v].pb(u);
    }
    int counti=k;
    f(i,1,n+1){
    	dist[counti]=inf;
    	rownum[i]=counti++;

    }
    f(i,1,m+1){
    	dist[counti]=inf;
    	colnum[i]=counti++;
    }
    rep(i,k){
    	u=x[i];
    	v=y[i];
    	int val;
    	if(valid(u-1,v)){
    		val=mapi[mp(u-1,v)];
    		adj[i].pb(val);
    	}
    	if(valid(u+1,v)){
    		val=mapi[mp(u+1,v)];
    		adj[i].pb(val);
    	}
    	if(valid(u,v-1)){
    		val=mapi[mp(u,v-1)];
    		adj[i].pb(val);
    	}
    	if(valid(u,v+1)){
    		val=mapi[mp(u,v+1)];
    		adj[i].pb(val);
    	}
    	adj1[i].pb(rownum[u]);
    	adj1[i].pb(colnum[v]);
    	adj[rownum[u]].pb(i);
    	adj[colnum[v]].pb(i);
    	if(validro(u-1)){
    		adj[rownum[u-1]].pb(i);
    		adj1[i].pb(rownum[u-1]);
    	}
    	if(validro(u+1)){
    		adj[rownum[u+1]].pb(i);
    		adj1[i].pb(rownum[u+1]);
    	}
    	if(validco(v-1)){
    		adj[colnum[v-1]].pb(i);
    		adj1[i].pb(colnum[v-1]);
    	}
    	if(validco(v+1)){
    		adj[colnum[v+1]].pb(i);
    		adj1[i].pb(colnum[v+1]);
    	}




    }
    bfs(src);
    if(mapi.find(mp(n,m))!=mapi.end()){
    	if(dist[mapi[mp(n,m)]]!=inf){
    		cout<<dist[mapi[mp(n,m)]]<<endl;
    	}
    	else{
    		cout<<-1<<endl;
    	}
    	return 0;
    }
    int mini=inf;
    rep(i,k){
    	//cout<<dist[10]<<endl;
    	if(x[i]>=n-1 || y[i]>=m-1){
    		mini=min(dist[i]+1,mini);
    	}
    	
    }
    if(mini==inf){
    	cout<<-1<<endl;
    }
    else{
    	cout<<mini<<endl;
    }

    
}