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

int chosen[512345],blog[512345];
vector<vi> adj(512345);
int printbad(){
	cout<<-1<<endl;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int i,j;
    int u,v;
    rep(i,m){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    vii vec;
    rep(i,n){
    	cin>>blog[i];
    	vec.pb(mp(blog[i],i+1));
    }
    sort(all(vec));
    rep(i,n){
    	int good=0;
    	rep(j,adj[i].size()){
    		if(blog[adj[i][j]]==blog[i]){
    			printbad();
    			return 0;
    		}
    		if(blog[i]>blog[adj[i][j]] && chosen[blog[adj[i][j]]]==0){
    			chosen[blog[adj[i][j]]]=1;
    			good++;
    		}
    	}
    	if(good+1!=blog[i]){
    		//cout<<i<<" "<<blog[i]<<" "<<good<<endl;
			printbad();
			return 0;
		}
		rep(j,blog[i])
			chosen[j]=0;
    }
    rep(i,vec.size()){
    	cout<<vec[i].ss<<" ";
    }
    cout<<endl;
    return 0;   
}