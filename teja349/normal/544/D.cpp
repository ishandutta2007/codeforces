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

int dist[3123],d[3123][3123];
vector<vi> adj(3123);

int bfs(int u,int n){
	int i;
	rep(i,n){
		dist[i]=inf;
	}
	dist[u]=0;
	queue<int> que;
	que.push(u);
	int cur;
	while(!que.empty()){
		cur=que.front();
		//cout<<cur<<"dsa"<<endl;
		que.pop();
		rep(i,adj[cur].size()){
			if(dist[adj[cur][i]]==inf){
				dist[adj[cur][i]] = dist[cur]+1;
				que.push(adj[cur][i]);
			}
		}
	}
	rep(i,n){
		d[u][i]=dist[i];
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int i,u,v;
    rep(i,m){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    int s1,s2,t1,t2,l1,l2;
    cin>>s1>>t1>>l1;
    s1--;t1--;
    cin>>s2>>t2>>l2;
    s2--;t2--;
    rep(i,n){
    	//if(i==s1)
    		bfs(i,n);
    }
    int j;
    
   // cout<<d[s1][t1]<<" sdfdd "<<d[s2][t2]<<endl;
    if(d[s1][t1]>l1 || d[s2][t2]>l2){
    	cout<<-1<<endl;
    	return 0;
    }
    int mini=d[s1][t1]+d[s2][t2];
    int min1,min2;
    rep(i,n){
    	rep(j,n){
    		min1=min(d[i][s1]+d[i][j]+d[j][t1],d[i][t1]+d[i][j]+d[j][s1]);
    		min2=min(d[i][s2]+d[i][j]+d[j][t2],d[i][t2]+d[i][j]+d[j][s2]);
    		if(min1>l1 || min2>l2)
    			continue;
    		mini=min(mini,min1+min2-d[i][j]);
    	}
    }
    cout<<m-mini<<endl;

    return 0;   
}