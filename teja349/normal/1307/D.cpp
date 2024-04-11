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

int sp[212345];
int lol[212345];
int dist[212345];
vector<vi> adj(212345);
int bfs(int st,int n){
	int i;
	rep(i,n){
		dist[i]=inf;
	}
	dist[st]=0;
	queue<int> que;
	que.push(st);
	int cur;
	while(!que.empty()){
		cur=que.front();
		que.pop();
		rep(i,adj[cur].size()){
			if(dist[adj[cur][i]]>dist[cur]+1){
				dist[adj[cur][i]]=dist[cur]+1;
				que.push(adj[cur][i]);
			}
		}
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    int i;
    int a,b;
    rep(i,k){
    	cin>>sp[i];
    	sp[i]--;
    }
    rep(i,m){
    	cin>>a>>b;
    	a--;
    	b--;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    bfs(0,n);
    rep(i,n){
    	lol[i]=dist[i];
    }
    bfs(n-1,n);
    vii vec;
    rep(i,k){
    	vec.pb(mp(lol[sp[i]]-dist[sp[i]],sp[i]));
    }
    int maxi=0;
    sort(all(vec));
    int sofar=dist[vec[k-1].ss];
    fd(i,k-2,0){
    	maxi=max(maxi,lol[vec[i].ss]+sofar+1);
    	sofar=max(sofar,dist[vec[i].ss]);
    }
    maxi=min(maxi,lol[n-1]);
    cout<<maxi<<endl;
    return 0;   
}