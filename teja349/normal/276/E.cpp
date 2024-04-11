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

//std::ios::sync_with_stdio(false);   
ll bitpos[123456],siz[123456],lev[123456];
vector<vl> adj(123456),bit(123456);

ll dfs(ll cur,ll par,ll dist,ll posi){
	bitpos[cur]=posi;
	siz[posi]++;
	ll i;
	lev[cur]=dist;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs(adj[cur][i],cur,dist+1,posi);
		}
	}
	return 0;
}
ll update(ll posi,ll ind,ll val){
	if(posi==0){
		bit[ind][posi]+=val;
		return 0;
	}
	while(posi<siz[ind]+2){
		bit[ind][posi]+=val;
		posi+=posi&(-posi);
	}
	return 0;
}
ll query(ll posi,ll ind){
	ll ans=0;
	while(posi>0){
		ans+=bit[ind][posi];
		posi-=posi&(-posi);
	}
	ans+=bit[ind][0];
	return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    ll n,q;
    cin>>n>>q;
    ll i,u,v;
    rep(i,n-1){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    ll counter;
    rep(i,adj[0].size()){
    	dfs(adj[0][i],0,1,i+1);
    	counter=i+2;
    }
    siz[0]=123444;
    bit[0].resize(123456,0);
    f(i,1,counter){
    	bit[i].resize(siz[i]+3,0);
    }
    ll x,d;
    while(q--){
    	ll typ;
    	cin>>typ;
    	if(typ==0){
    		cin>>v>>x>>d;
    		v--;
    		if(v==0){
    			update(d,0,x);
    		}
    		else{
    			
    			update(lev[v]+d+1,bitpos[v],-1*x);
    			if(d>=lev[v]){
    				update(d-lev[v],0,x);
    				update(max((ll)1,d-lev[v]+1),bitpos[v],x);
    			}
    			else{
    				update(max((ll)1,lev[v]-d),bitpos[v],x);
    			}
    		}
    	}
    	else{
    		cin>>v;
    		v--;
    		if(v==0){
    			cout<<query(120000,0)<<endl;
    		}
    		else{
    			cout<<query(lev[v],bitpos[v])+query(120000,0)-query(lev[v]-1,0)<<endl;
    		}
    	}
    }

    return 0;  
    
}