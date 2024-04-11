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
#define LOG 18
int par[123456][LOG];
int level[123456],subtree[123456];
vector<vi> adj(123456);

//std::ios::sync_with_stdio(false);   
int dfs(int cur,int prev,int leve){
	int i;
	par[cur][0]=prev;
	level[cur]=leve;
	subtree[cur]=1;
	rep(i,adj[cur].size()){
		if(adj[cur][i]==prev)
			continue;
		dfs(adj[cur][i],cur,leve+1);
		subtree[cur]+=subtree[adj[cur][i]];
	}
	return 0;
}
int findlca(int p,int q){
	int i;
	if(level[p]<level[q]){
		swap(p,q);
	}
	fd(i,LOG-1,0){
		if(level[p]-(1<<i)>=level[q]){
			p=par[p][i];
		}
	}
	if(p==q){
		return p;
	}
	fd(i,LOG-1,0){
		if(par[p][i]!=par[q][i]){
			p=par[p][i];
			q=par[q][i];
		}
	}
	return par[p][0];

}
int findkthpar(int p,int k){
	int val=level[p],i;
	val-=k;
	fd(i,LOG-1,0){
		if(level[p]-(1<<i)>=val){
			p=par[p][i];
		}
	}
	return p;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j,u,v;
    rep(i,n-1){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs(0,-1,0);
    f(j,1,LOG){
    	rep(i,n){
    		if(par[i][j-1]==-1){
    			par[i][j]=-1;
    		}
    		else{
    			par[i][j]=par[par[i][j-1]][j-1];
    		}
    	}
    }

    int m;
    cin>>m;
    rep(i,m){
    	cin>>u>>v;
    	u--;
    	v--;
    	if(u==v){
    		cout<<n<<endl;
    		continue;
    	}
    	//cout<<level[u]<<" "<<level[v]<<endl;
    	if((level[u]+level[v])%2==1){
    		cout<<0<<endl;
    		continue;
    	}

    	int lca=findlca(u,v);
    	if(level[u]==level[v]){
    		//cout<<"Boo"<<endl;
    		u=findkthpar(u,level[u]-level[lca]-1);
    		v=findkthpar(v,level[v]-level[lca]-1);
    		cout<<n-subtree[u]-subtree[v]<<endl;
    	}
    	else{
    		int ht=(level[u]+level[v]-2*level[lca])/2;
    		//cout<<ht<<endl;
    		if(level[u]-level[lca]<ht){
    			
    			u=findkthpar(v,ht);
    			v=findkthpar(v,ht-1);
    			cout<<subtree[u]-subtree[v]<<endl;
    		}
    		else{
    			//cout<<"Boo"<<endl;
    			swap(u,v);
    			u=findkthpar(v,ht);
    			v=findkthpar(v,ht-1);
    			//cout<<u<<" "<<v<<endl;
    			cout<<subtree[u]-subtree[v]<<endl;
    		}
    	}

    }
    return 0;      

}