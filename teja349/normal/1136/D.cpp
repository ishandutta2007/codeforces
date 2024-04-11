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

vector<vi> adj(312345);
int p[312345];
int u[512345],v[512345];
int good[312345];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n,m;
  	cin>>n>>m;
  	int i;
  	rep(i,n){
  		cin>>p[i];
  	}
  	rep(i,m){
  		cin>>u[i]>>v[i];
  		adj[u[i]].pb(v[i]);
  		if(v[i]==p[n-1]){
  			good[u[i]]=1;
  		}
  	}
  	int cnt=0;
  	set<int> seti;
  	int gg=0;
  	int j;
  	fd(i,n-2,0){
  		if(!good[p[i]]){
  			seti.insert(p[i]);
  		}
  		else{
  			gg=0;
  			rep(j,adj[p[i]].size()){
  				if(seti.find(adj[p[i]][j])!=seti.end())
  					gg++;
  			}
  			if(gg==(int)seti.size()){
  				cnt++;
  			}
  			else{
  				seti.insert(p[i]);
  			}

  		}
  	}

  	cout<<cnt<<endl;
    return 0;   
}