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
#define inf (1000*1000*100+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);
vector<vl> adj(123456),cost(123456);
ll dist[123456],mark[123456];
vll vec;
set<pll> seti;
ll n,m,k;   
int relax(int cur){
	int i;
	rep(i,adj[cur].size()){
		if(dist[adj[cur][i]]>dist[cur]+cost[cur][i]){
			seti.erase(mp(dist[adj[cur][i]],adj[cur][i]));
			dist[adj[cur][i]]=dist[cur]+cost[cur][i];
			seti.insert(mp(dist[adj[cur][i]],adj[cur][i]));
		}
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    //int n,m,k;
    ll i,u,v,c;
    cin>>n>>m>>k;
    rep(i,m){
    	cin>>u>>v>>c;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    	cost[u].pb(c);
    	cost[v].pb(c);
    }
    rep(i,k){
    	cin>>u>>c;
    	u--;
    	vec.pb(mp(c,u));
    }
     ll iinf=inf;
     iinf*=inf;
    vec.pb(mp(iinf+10,8));
    sort(vec.begin(),vec.end());
   
    f(i,1,n){
    	dist[i]=iinf;
    	seti.insert(mp(dist[i],i));
    }
    dist[0]=0;
    int haha=0;
    pll elem;
    seti.insert(mp(0,0));
    i=0;
    while(!seti.empty()){
    	//elem=seti.begin();
    	elem=*(seti.begin());
    	//cout<<elem.ff
    	while(vec[i].ff<elem.ff){

    		if(!mark[vec[i].ss]){
    			haha++;
    			seti.erase(mp(dist[vec[i].ss],vec[i].ss));
    			dist[vec[i].ss]=vec[i].ff;
    			seti.insert(mp(dist[vec[i].ss],vec[i].ss));
    			i++;
    			//cout<<"vdc";
    			break;
    		}
    		else{
    			i++;
    		}

    	}
    	//elem=seti.begin();

    	elem=*(seti.begin());
    	relax(elem.ss);
    	seti.erase(elem);
    	mark[elem.ss]=1;
    }
    cout<<k-haha<<endl;
    return 0;      

}