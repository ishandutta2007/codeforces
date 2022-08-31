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

vector<vi> adj(12345),rev(12345);
int deg[12345];
int visit[12345];
int counter=0;
int dfs(int cur){
	visit[cur]=counter;
	int i;
	rep(i,adj[cur].size()){
		if(!visit[adj[cur][i]])
			dfs(adj[cur][i]);
	}
	return 0;
}
string s[12345];
int haha[12345];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n,m;
  	cin>>n>>m;
  	int i,j;
  	rep(i,n){
  		cin>>s[i];
  		rep(j,m){
  			if(s[i][j]=='='){
  				adj[i].pb(j+n);
  				adj[j+n].pb(i);
  			}
  		}
  	}
  	counter=1;
  	rep(i,n+m){
  		if(!visit[i]){
  			
  			dfs(i);
  			counter++;
  		}
  	}
  	rep(i,n+m){
  		adj[i].clear();
  	}
  	rep(i,n){
  		rep(j,m){
  			if(visit[i]==visit[j+n] && s[i][j]!='='){
  				cout<<"No"<<endl;
  				return 0;
  			}
  		}
  	}
  	rep(i,n){
  		rep(j,m){
  			if(s[i][j]=='<'){
  				adj[visit[i]].pb(visit[j+n]);
  				rev[visit[j+n]].pb(visit[i]);
  				deg[visit[j+n]]++;
  			}
  			if(s[i][j]=='>'){
  				adj[visit[j+n]].pb(visit[i]);
  				rev[visit[i]].pb(visit[j+n]);
  				deg[visit[i]]++;
  			}
  		}
  	}
  	stack<int> st;
  	f(i,1,counter){
  		if(deg[i]==0){
  			st.push(i);
  			//cout<<counter<<endl;
  		}
  	}
  	int used=0,cur,lol;
  	while(!st.empty()){
  		used++;
  		cur=st.top();
  		st.pop();
  		lol=0;
  		rep(i,adj[cur].size()){
  			deg[adj[cur][i]]--;
  			if(deg[adj[cur][i]]==0){
  				st.push(adj[cur][i]);
  			}
  		}
  		rep(i,rev[cur].size()){
  			lol=max(lol,haha[rev[cur][i]]);
  		}
  		haha[cur]=lol+1;	
  	}
  	//cout<<used<<endl;
  	if(used!=counter-1){
  		cout<<"No"<<endl;
  		return 0;
  	}
  	cout<<"Yes"<<endl;
  	rep(i,n){
  		cout<<haha[visit[i]]<<" ";
  	}
  	cout<<endl;
  	rep(i,m){
  		cout<<haha[visit[i+n]]<<" ";
  	}
  	cout<<endl;


    return 0;   
}