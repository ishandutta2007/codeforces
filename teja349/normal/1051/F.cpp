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
#define flush fflush(stdout) 
#define primeDEN 727999983
//cout<<fixed<<setprecision(15)<<ans;
 


ll par[123456][18];
ll dist[123456],u[123456],v[123456],d[123456],lev[123456];
ll visit[123456],touch[123456];
vl vec;
vector<vl> adj(123456);
int dfs(int cur){
	visit[cur]=1;
	int i;
	//cout<<cur<<" "<<1<<endl;
	int flag=0,gg,haha;
	rep(i,adj[cur].size()){
		haha=adj[cur][i];
		gg=((cur^u[haha])^v[haha]);
		
		if(visit[gg]){
			if(touch[haha])
				continue;
			touch[haha]=1;
			
			flag=1;
		}
		else{
			touch[haha]=1;
			par[gg][0]=cur;
			lev[gg]=lev[cur]+1;
			dist[gg]=dist[cur]+d[haha];
			dfs(gg);
		}	
	}
	if(flag){
		vec.pb(cur);
	}
	return 0;
}
ll iinf;
ll wow[123456];
int doshort(int ver,int n){
	int i;

	rep(i,n){
		wow[i]=iinf;
	}
	set<pll> seti;
	wow[ver]=0;
	rep(i,n){
		seti.insert(mp(wow[i],i));
	}
	pll papa;
	ll cur,haha,gg;
	while(!seti.empty()){
		papa=*(seti.begin());
		seti.erase(papa);
		cur=papa.ss;
		//cout<<cur<<" "<<wow[cur]<<endl;
		rep(i,adj[cur].size()){
			haha=adj[cur][i];
			gg=((cur^u[haha])^v[haha]);
			if(wow[gg]>wow[cur]+d[haha]){
				seti.erase(mp(wow[gg],gg));
				wow[gg]=wow[cur]+d[haha];
				seti.insert(mp(wow[gg],gg));
			}
		}
	}
	return 0;

}

int lca(int p,int q){
	if(lev[p]>lev[q]){
		swap(p,q);
	}
	int i;
	fd(i,17,0){
		if(lev[q]-(1<<i)>=lev[p]){
			q=par[q][i];
		}
	}
	if(p==q)
		return p;
	fd(i,17,0){
		if(par[p][i]!=par[q][i]){
			p=par[p][i];
			q=par[q][i];
		}
	}
	return par[p][0];
}


ll foo[22][123456];
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    iinf=inf;
    iinf*=inf;
    int i;
    rep(i,m){
    	cin>>u[i]>>v[i]>>d[i];
    	u[i]--;
    	v[i]--;
    	adj[u[i]].pb(i);
    	adj[v[i]].pb(i);
    }
    par[0][0]=-1;
    dist[0]=0;
    lev[0]=0;
    dfs(0);
    //return 0;
    int j;
    f(j,1,18){
    	rep(i,n){
    		if(par[i][j-1]==-1)
    			par[i][j]=-1;
    		else
    			par[i][j]=par[par[i][j-1]][j-1];
    	}
    }
    rep(i,vec.size()){
    	doshort(vec[i],n);
    	rep(j,n){
    		//cout<<wow[j]<<"sasa "<<endl;
    		foo[i][j]=wow[j];
    	}
    }
    // rep(i,n){
    // 	cout<<dist[i]<<endl;
    // }
    //cout<<vec.size()<<endl;
    int q;
    cin>>q;
    int x,y;
    ll mini,gg;
    rep(j,q){
    	cin>>x>>y;
    	x--;
    	y--;
    	mini=iinf;
    	rep(i,vec.size()){
    		mini=min(mini,foo[i][x]+foo[i][y]);
    	}
    	gg=lca(x,y);
    	mini=min(mini,dist[x]+dist[y]-2*dist[gg]);
    	cout<<mini<<endl;
    }



    return 0;   
}