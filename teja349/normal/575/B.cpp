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
struct totale{
	int a,b,id; 
};
totale total[123456];
vector<vi> adj(123456),edge(123456);
int level[123456],par[100010][20],up[123456],down[123456],haha[123456];
ll twos[1234567];
int dfs(int cur,int prev,int leve){
	int i;
	level[cur]=leve;
	par[cur][0]=prev;
	rep(i,adj[cur].size()){
		if(adj[cur][i]==prev)
			continue;
		dfs(adj[cur][i],cur,leve+1);
		haha[edge[cur][i]]=adj[cur][i];

	}
	return 0;
}
int compute_lca(int p,int q){
	if(level[p]<level[q]){
		swap(p,q);
	}
	int i;
	fd(i,19,0){
		if(level[p]-(1<<i)>=level[q]){
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
int dfs2(int cur,int prev){
	int i;

	rep(i,adj[cur].size()){
		if(adj[cur][i]==prev)
			continue;
		dfs2(adj[cur][i],cur);
		up[cur]+=up[adj[cur][i]];
		down[cur]+=down[adj[cur][i]];
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	int n,u,v,i,c;
	cin>>n;
	int j;
	int st,en,lca;
	rep(i,n-1){
		cin>>u>>v>>c;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
		edge[u].pb(i);
		edge[v].pb(i);
		total[i].a=u;
		total[i].b=v;
		total[i].id=c;

	}
	twos[0]=0;
	f(i,1,1234566){
		twos[i]=2*twos[i-1]+1;
		twos[i]%=mod;
	}
	//cout<<twos[4]<<"dassd";
	dfs(0,-1,0);
	f(i,1,20){
		rep(j,n){
			if(par[j][i-1]==-1){
				par[j][i]=-1;
			}
			else{
				par[j][i]=par[par[j][i-1]][i-1];
			}
		}
	}
	int k;
	cin>>k;
	st=0;
	rep(i,k){
		cin>>en;
		en--;
		lca=compute_lca(st,en);
		up[lca]--;
		up[st]++;
		down[lca]--;
		down[en]++;
		st=en;

	}
	dfs2(0,-1);
	ll ans=0;
	rep(i,n-1){
		//cout<<up[haha[i]]<<" "<<down[haha[i]]<<endl;
		if(haha[i]==total[i].b && total[i].id){
			ans+=twos[up[haha[i]]];
		}
		else if(total[i].id){
			ans+=twos[down[haha[i]]];
		}
		ans%=mod;
	}
	
	ans%=mod;
	cout<<ans<<endl;

}