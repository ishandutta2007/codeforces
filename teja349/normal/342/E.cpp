
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
vector< vi > adj(123456);
vector< set < int > > adjcen(123456);
int paren[100005][18];
int level[100005];
int siz[100005];
int parcen[100005];
int maxpain[100005];
int compute();
int lca(int u,int v);
int decompose(int value,int parent);
int dfs2(int cur,int par);
int centroid_find(int cur,int par,int limit);
int query(int u);
int paint(int u);
int n,m;
int main(){
	std::ios::sync_with_stdio(false);
	int i,u,v,t;
	cin>>n>>m;
	rep(i,n+3){
		maxpain[i]=inf;
	}
	//cout<<"dsfs";
	rep(i,n-1){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
		adjcen[u].insert(v);
		adjcen[v].insert(u);
	}
	//cout<<"fsdfd  ";
	fflush(stdout);
	decompose(1,0);
	//cout<<"fsdfd  ";
	fflush(stdout);
	compute();
	//cout<<"fsdfd  ";
	fflush(stdout);
	paint(1);


	while(m--){
		cin>>t>>u;
		if(t==1){
			paint(u);
		}
		else{
			cout<<query(u)<<endl;
		}
	}
}

int paint(int u){
	int fix=u;
	while(u!=0){
		int v=u;
		int lcm=lca(fix,v);
		//cout<<fix<<" "<<v<<" "<<lcm<<endl;
		int dist=level[fix]+level[v]-2*level[lcm];
		maxpain[u]=min(dist,maxpain[u]);
		u=parcen[u];

	}
	return 0;
}

int query(int u){
	int fix=u;
	int ans=inf;
	while(u!=0){
		int v=u;
		int lcm=lca(fix,v);

		int dist=level[fix]+level[v]-(2*level[lcm]);
		ans=min(ans,maxpain[u]+dist);
		u=parcen[u];

	}
	return ans;
}

int dfs1(int cur,int par,int leveled){
	int i;
	paren[cur][0]=par;	
	level[cur]=leveled;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs1(adj[cur][i],cur,leveled+1);
		}
	}
	return 0;
}

int compute(){
	dfs1(1,-1,0);
	int i,j;
	f(j,1,18){
		f(i,1,n+1){
			if(paren[i][j-1]!=-1)
				paren[i][j]=paren[paren[i][j-1]][j-1];
			else
				paren[i][j]=-1;
		}
	}
	return 0;
}

int lca(int u,int v){
	//cout<<u<<" "<<v<<"   asdas";
	int i,j;
	if(level[v]>level[u]){
		swap(u,v);
	}
	fd(i,17,0){
		if(level[u]-(1<<i) < level[v])
			continue;
		u=paren[u][i];
	}
	//cout<<level[u]<<" "<<level[v]<<endl;
	if(u==v){
		return u;
	}
	fd(j,17,0){
		if(paren[u][j]!=paren[v][j]){
			u=paren[u][j];
			v=paren[v][j];
		}
	}
	return paren[u][0];
}
int decompose(int value,int parent){
	dfs2(value,-1);

	int cur=centroid_find(value,-1,siz[value]/2);
	//return 0;
	set< int >::iterator it;
	for(it=adjcen[cur].begin();it!=adjcen[cur].end();){
		int val=*it;
		adjcen[cur].erase(val);
		adjcen[val].erase(cur);
		decompose(val,cur);
		it=adjcen[cur].begin();
	}
	parcen[cur]=parent;
	return 0;

}
int dfs2(int cur,int par){
	siz[cur]=1;
	set< int >::iterator it;
	for(it=adjcen[cur].begin();it!=adjcen[cur].end();it++){
		if(*it!=par){
			dfs2(*it,cur);
			siz[cur]+=siz[*it];
		}
	}
	return 0;
}

int centroid_find(int cur,int par,int limit){
	set< int >::iterator it;
	for(it=adjcen[cur].begin();it!=adjcen[cur].end();it++){
		if(*it!=par){
			
			if(siz[*it]>limit){
				return centroid_find(*it,cur,limit);
			}
		}
	}
	return cur;
}