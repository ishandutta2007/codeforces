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
#define iinf (1000*1000*100+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+193)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false); 
ll n,m,inf;

vector<vl> adj(123456),revadj(123456),revcost(123456),cost(123456);

ll distt[123456],dists[123456],path[123456],paths[123456],patht[123456];

set<pll> seti;

ll x[123456],y[123456],z[123456];
ll path2[123456],paths2[123456],patht2[123456];

int relax(ll cur,vector<vl> &adj,vector<vl> &cost,ll *dist){
	ll i;
	//<<cur<<"sadas"<<endl;
	rep(i,adj[cur].size()){

		if(dist[adj[cur][i]]>dist[cur]+cost[cur][i]){
			seti.erase(mp(dist[adj[cur][i]],adj[cur][i]));
			dist[adj[cur][i]]=dist[cur]+cost[cur][i];
			seti.insert(mp(dist[adj[cur][i]],adj[cur][i]));
		}
	}
	return 0;
}  

ll dijstra(ll cur,vector<vl> &adj,vector<vl> &cost,ll* dist){
	ll i;
	//cout<<cur<<endl;
	rep(i,n){
		seti.insert(mp(inf,i));
		dist[i]=inf;
	}
	dist[cur]=0;
	seti.erase(mp(inf,cur));
	seti.insert(mp(0,cur));
	pll elem;
	//cout<<inf<<endl;
	//cout<<seti.size()<<endl;
	while(!seti.empty()){
		elem=*(seti.begin());
		//dist[elem.ss]=elem.ff;
		seti.erase(elem);
		//cout<<elem.ss<<endl;
		relax(elem.ss,adj,cost,dist);
	}
	return 0;
}



ll findpath(ll cur,ll s,vector<vl> &adj,vector<vl> &cost,ll * dist){
	ll i;
	if(s==cur){
		path[s]=1;
		path2[s]=1;
		return 1;
	}
	if(path[cur]!=-1){
		return path[cur];
	}
	path[cur]=0;

	rep(i,adj[cur].size()){
		if(dist[adj[cur][i]]+cost[cur][i]==dist[cur]){
			path[cur]+=findpath(adj[cur][i],s,adj,cost,dist);
			path2[cur]+=path2[adj[cur][i]];
			path[cur]%=mod;
		}
	}
	return path[cur];
	
}



int main(){
    std::ios::sync_with_stdio(false);
    ll s,t;
    cin>>n>>m>>s>>t;
    inf=iinf;
    inf*=iinf;
    s--;
    t--;
    ll i,u,v,c;
    rep(i,m){
    	cin>>u>>v>>c;

    	u--;
    	v--;
    	x[i]=u;
    	y[i]=v;
    	z[i]=c;
    	adj[u].pb(v);

    	revadj[v].pb(u);
    	revcost[v].pb(c);
    	cost[u].pb(c);
    	

    }
    //cout<<s<<endl;
    dijstra(s,adj,cost,dists);
    //return 0;
    dijstra(t,revadj,revcost,distt);
    rep(i,n){
    	path[i]=-1;
    	path2[i]=0;
    }
    rep(i,n){
    	findpath(i,s,revadj,revcost,dists);
    	paths[i]=path[i];
    	paths2[i]=path2[i];
    }
    rep(i,n){
    	path[i]=-1;
    	path2[i]=0;
    }
    

    rep(i,n){
    	findpath(i,t,adj,cost,distt);

    	patht[i]=path[i];
    	patht2[i]=path2[i];
    }
    ll ans=dists[t],val,repa,val1;
    
    //return 0;
    //cout<<paths[t]<<endl;
    //return 0;
    rep(i,m){
    	val=paths[x[i]]*patht[y[i]];
    	val1=paths2[x[i]]*patht2[y[i]];
    	//cout<<val<<endl;
    	val%=mod;
    	if(val==paths[t] && val1==paths2[t] && dists[x[i]]+z[i]+distt[y[i]]==ans){
    		cout<<"YES"<<endl;
    	}
    	else{
    		repa=dists[x[i]]+z[i]+distt[y[i]]-ans+1;
    		if(repa<z[i]){
    			cout<<"CAN"<<" "<<repa<<endl;
    		}
    		else{
    			cout<<"NO"<<endl;
    		}
    	}
    }
    //findpath(s);
    return 0;      

}