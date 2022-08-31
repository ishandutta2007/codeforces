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
int ind[1234],indeg[1234];
vector<vi> adj(1234);
int n,m;
int checkit(int curi,int ans){
	int i;
	rep(i,n){
		ind[i]=indeg[i];
	}
	indeg[curi]--;
	stack<int> st;
	st.push(curi);
	int cnt=0,cur;
	while(!st.empty()){
		cur=st.top();
		st.pop();
    	cnt++;
    	rep(i,adj[cur].size()){
    		indeg[adj[cur][i]]--;
    		if(!indeg[adj[cur][i]])
    			st.push(adj[cur][i]);
    	}

	}
	rep(i,n){
		indeg[i]=ind[i];
	}
	//cout<<cnt<<endl;
	if(cnt==ans){
		cout<<"YES"<<endl;
		exit(0);
	}
}
int main(){
    std::ios::sync_with_stdio(false);
    int i,u,v;
    cin>>n>>m;
    rep(i,m){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	indeg[v]++;
    }
    stack<int> st;
    rep(i,n){
    	if(!indeg[i]){
    		//cout<<i<<endl;
    		st.push(i);
    	}
    }
    int cur,cnt=0;
    while(!st.empty()){
    	cur=st.top();
    	st.pop();
    	cnt++;
    	rep(i,adj[cur].size()){
    		indeg[adj[cur][i]]--;
    		if(!indeg[adj[cur][i]])
    			st.push(adj[cur][i]);
    	}
    	
    }
    if(cnt==n){
    	cout<<"YES"<<endl;
    	return 0;
    }
    rep(i,n){
    	if(indeg[i]==1){
    		//cout<<i<<" "<<cnt<<endl;
    		//indeg[i]--;
    		checkit(i,n-cnt);
    	}
    }
    cout<<"NO"<<endl;
    return 0;


  	return 0;  
    
}