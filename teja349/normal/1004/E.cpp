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
vector<vl> adj(123456),wt(123456);
vl vec;
stack<ll> sta;
ll st,en;
ll maxi,elem;
ll dist[123456];
ll hh[123456];
ll visit[123456],bow[123456],bbow[123456];
ll gg;
ll dfs(ll cur,ll par){
	if(par==-1){
		dist[cur]=0;
	}
	if(dist[cur]>maxi){
		maxi=dist[cur];
		elem=cur;
	}
	ll i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par && !visit[adj[cur][i]]){
			dist[adj[cur][i]]=dist[cur]+wt[cur][i];
			dfs(adj[cur][i],cur);
		}
		else if(visit[adj[cur][i]]){
			if(vec[gg+1]==adj[cur][i]){
				hh[gg]=wt[cur][i];
			}
		}
	}
	return 0;
}
ll flag;
ll dfs1(ll cur,ll par){
	if(flag){
		visit[cur]=1;
		sta.push(cur);
	}
	if(cur==en){
		flag=0;
	}
	ll i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs1(adj[cur][i],cur);
		}
	}
	if(flag==1){
		visit[cur]=0;
		sta.pop();
	}
	return 0;

}
multiset<ll> seti,setin,setla;
ll lefter,righter;
ll getmax(){
	multiset<ll>::iterator it;
	it=seti.end();
	it--;
	ll val=*it+righter;
	it=setin.end();
	it--;
	val=max(val,*it);
	it=setla.end();
	it--;
	val=max(val,*it+lefter);
	return val;
	
	
}
int main(){
    std::ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    ll i,u,v,d;

    rep(i,n-1){
    	cin>>u>>v>>d;
    	u--;
    	v--;
    	adj[u].pb(v);
    	wt[u].pb(d);
    	adj[v].pb(u);
    	wt[v].pb(d);
    }
    maxi=0;
    elem=0;
    dfs(0,-1);
    st=elem;
    maxi=0;
    dfs(elem,-1);
    en=elem;
    flag=1;
    //cout<<st<<en<<endl;
    dfs1(st,-1);
    while(!sta.empty()){
    	vec.pb(sta.top());
    	sta.pop();
    }
    ll mama=0;
    vec.pb(-3);
    rep(i,vec.size()-1){
    	gg=i;
    	maxi=0;

    	dfs(vec[i],-1);
    	bow[i]=maxi;
    	mama=max(mama,bow[i]);
    }

    if(vec.size()<=k+1){
    	cout<<mama<<endl;
    	return 0;
    }
    mama=0;
    seti.insert(0);
    f(i,k,vec.size()-1){
    	mama+=hh[i-1];
    	bbow[i]=bow[i]+mama;
    	seti.insert(bbow[i]);
    }
   lefter=0;
   righter=0;
    rep(i,k){
    	setin.insert(bow[i]);
    }
    ll mini=inf;
    mini*=inf;
    setla.insert(0);
    rep(i,vec.size()-1){
    	mini=min(mini,getmax());
    	if(i+k+1==vec.size()){
    		break;
    	}
    	lefter+=hh[i];
    	righter-=hh[i+k-1];
    	setla.insert(bow[i]+hh[i]-lefter);
    	setin.erase(setin.find(bow[i]));
    	setin.insert(bow[i+k]);
    	seti.erase(seti.find(bbow[i+k]));
    	
    }
    cout<<mini<<endl;


    return 0;  
    
}