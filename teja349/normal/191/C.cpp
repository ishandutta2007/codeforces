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
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false); 

vector<vi> adj(123456),edge(123456);
int level[123456],par[123456][20],lol[123456],bit[212345],chain[123456];
int head[123456],segpos[123456],arr[123456],subtree[123456];
int update(int pos,int val){
	while(pos<212345){
		bit[pos]+=val;
		pos+=pos&(-pos);
	}
	return 0;
}
int query(int pos){
	int sumi=0;
	while(pos>0){
		sumi+=bit[pos];
		pos-=pos&(-pos);
	}
	return sumi;
}
int dfs(int cur,int prev,int leve){
	int i;
	level[cur]=leve;
	subtree[cur]=1;
	rep(i,adj[cur].size()){
		if(prev==adj[cur][i])
			continue;
		dfs(adj[cur][i],cur,leve+1);
		par[adj[cur][i]][0]=cur;

		lol[edge[cur][i]]=adj[cur][i];
		subtree[cur]+=subtree[adj[cur][i]];
	}

	return 0;
}

int updatepath(int u,int v){
	//cout<<u<<" "<<v<<endl;
	while(head[chain[u]]!=head[chain[v]]){
		update(segpos[u]+1,-1);
		
		update(segpos[head[chain[u]]],1);
		//cout<<u<<endl;

		//cout<<segpos[u]+1<<" ff "<<u<<" "<<head[chain[u]]<<"  ";
		//cout<<segpos[head[chain[u]]]<<endl;
		u=par[head[chain[u]]][0];
		//cout<<par[4][0]<<endl;
		
	}

	if(u==v){
		//cout<<"asdasd"<<endl;
		return 0;
	}
	if(u!=v){
		update(segpos[u]+1,-1);
		update(segpos[v]+1,1);

	}
	return 0;
}

int find_lca(int p,int q){
	if(level[p]<level[q]){
		swap(p,q);
	}
	int i;
	fd(i,19,0){
		if((level[p]-(1<<i))>=level[q]){
			p=par[p][i];
		}

	}
	if(p==q)
		return p;
	fd(i,19,0){
		if(par[p][i]!=par[q][i]){
			p=par[p][i];
			q=par[q][i];
		}

	}
	return par[p][0];

}
int compute(int p,int q){

	int lca=find_lca(p,q);

	updatepath(p,lca);
	//cout<<"adad"<<endl;
	updatepath(q,lca);
	//cout<<"adad"<<endl;
}
int chainno=0;
int elem=3;

int hld(int cur,int prev){

	if(head[chainno]==-1){
		head[chainno]=cur;
		//cout<<cur<<endl;
	}
	chain[cur]=chainno;
	arr[elem++]=cur;
	segpos[cur]=elem-1;
	int i;
	int bigchild=-1;
	int maxi=-1;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			if(subtree[adj[cur][i]]>maxi){
				maxi=subtree[adj[cur][i]];

				bigchild=adj[cur][i];
			}
		}
	}
	if(bigchild!=-1){
		hld(bigchild,cur);
	}

	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			if(adj[cur][i]!=bigchild){
				chainno++;
				hld(adj[cur][i],cur);
			}
		}
	}
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,i,j,u,v;
	cin>>n;
	rep(i,n-1){
		
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		edge[u].pb(i);
		adj[v].pb(u);
		edge[v].pb(i);
	}

	rep(i,n+4){
		head[i]=-1;
	}

	dfs(0,-1,0);

	hld(0,-1);

	f(i,1,20){
		rep(j,n){
			if(par[j][i-1]!=-1){
				par[j][i]=par[par[j][i-1]][i-1];
			}
			else{
				par[j][i]=-1;
			}
		}

	}

	int k;
	cin>>k;
	rep(i,k){
		cin>>u>>v;
		u--;
		v--;
		//cout<<u<<" "<<v<<endl;
		//cout<<"bee"<<endl;
		compute(u,v);
	}

	//return 0;
	rep(i,n-1){

		
		cout<<query(segpos[lol[i]])<<" ";
	}

}