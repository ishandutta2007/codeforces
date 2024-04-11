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
vector<vi> adj(312345);
int dp[312345][28],indeg[312345];
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int i,j,cur,cnt=0,u,v;
    rep(i,m){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	indeg[v]++;
    }
    stack<int> st;
    rep(i,n){
    	if(indeg[i]==0)
    		st.push(i);
    }
    while(!st.empty()){
    	cur=st.top();
    	st.pop();
    	cnt++;
    	dp[cur][s[cur]-'a']++;
    	rep(i,adj[cur].size()){
    		rep(j,26){
    			dp[adj[cur][i]][j]=max(dp[cur][j],dp[adj[cur][i]][j]);
    		}
    		indeg[adj[cur][i]]--;
    		if(!indeg[adj[cur][i]]){
    			st.push(adj[cur][i]);
    		}
    	}
    }
    if(cnt!=n){
    	cout<<-1<<endl;
    	return 0;
    }
    int maxi=0;
    rep(i,n){
    	rep(j,26){
    		maxi=max(maxi,dp[i][j]);
    	}
    }
    cout<<maxi<<endl;
    return 0;  
    
}