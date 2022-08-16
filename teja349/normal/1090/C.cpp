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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

set<int> avail;
vector<vi> adj(123456);
vector< set<int> > seti(123456);
int vali[123456];
int tolose[123456],togain[123456];
int findnextavail(int val){
	return *(avail.lower_bound(val));
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n,m;
  	cin>>n>>m;
  	int i;
  	int sumi=0;
  	vii vec;
  	int j;
  	int u;
  	rep(i,n){
  		cin>>vali[i];
  		
  		sumi+=vali[i];
  		vec.pb(mp(vali[i],i));
  		rep(j,vali[i]){
  			cin>>u;
  			u--;
  			adj[i].pb(u);
  		}
  	}
  	int reqd,lef;
  	reqd=sumi/n;
  	lef=sumi%n;
  	sort(all(vec));
  	vi exc,def;
  	//cout<<reqd<<endl;
  	//cout<<lef<<endl;
  	rep(i,n-lef){
  		if(vec[i].ff<reqd){
  			def.pb(vec[i].ss);
  			togain[vec[i].ss]=reqd-vec[i].ff;
  		}
  		else if(vec[i].ff>reqd){
  			exc.pb(vec[i].ss);
  			tolose[vec[i].ss]=vec[i].ff-reqd;
  		}
  	}
  	f(i,n-lef,n){
  		if(vec[i].ff>reqd+1){
  			exc.pb(vec[i].ss);
  			tolose[vec[i].ss]=vec[i].ff-reqd-1;
  		}
  		else if(vec[i].ff<reqd+1){
  			def.pb(vec[i].ss);
  			togain[vec[i].ss]=reqd+1-vec[i].ff;
  		}
  	}
  	int gao=0;
  	rep(i,exc.size()){
  		u=exc[i];
  		//cout<<u<<endl;
  		gao+=tolose[u];
  		rep(j,adj[u].size()){

  			seti[adj[u][j]].insert(u);
  		}
  	}
  	cout<<gao<<endl;
  	rep(i,m){
  		if(seti[i].size()>0){
  			avail.insert(i);
  		}
  	}
  	avail.insert(inf);
  	int k;
  	int val;
  	rep(i,def.size()){
  		u=def[i];
  		//cout<<u<<endl;
  		sort(all(adj[u]));
  		int previ=-1;
  		adj[u].pb(inf);
  		int haha;
  		rep(j,adj[u].size()){
  			if(adj[u][j]==previ+1){
  				previ++;
  				continue;
  			}
  			//cout<<previ+1<<"dsasd"<<togain[u]<<endl;
  			while(togain[u]){
  				val=findnextavail(previ+1);
  				//cout<<val<<" "<<u<<endl;
  				if(val>=adj[u][j]){
  					previ=adj[u][j];
  					break;
  				}
  				else{
  					togain[u]--;
  					haha=*seti[val].begin();
  					cout<<haha+1<<" "<<u+1<<" "<<val+1<<endl;
  					seti[val].erase(haha);
  					if(seti[val].empty()){
  						avail.erase(val);
  					}
  					tolose[haha]--;
  					if(tolose[haha]==0){
  						rep(k,adj[haha].size()){
  							if(seti[adj[haha][k]].find(haha)!=seti[adj[haha][k]].end()){
  								seti[adj[haha][k]].erase(haha);
  								if(seti[adj[haha][k]].empty()){
  									avail.erase(adj[haha][k]);
  								}
  							}
  						}
  					}
  					previ=val;
  				}
  			}
  			
  			
  		}
  	}

    return 0;   
}