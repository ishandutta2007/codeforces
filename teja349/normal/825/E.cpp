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
int label[123456],indeg[123456];
vector<vi> adj(123456);
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    int i,u,v;
    cin>>n>>m;
    rep(i,m){
    	cin>>u>>v;
    	u--;
    	v--;
    	swap(u,v);
    	adj[u].pb(v);
    	indeg[v]++;
    }
    pqueue pq;
    rep(i,n){
    	if(indeg[i]==0){
    		pq.push(i);
    	}
    	label[i]=-1;
    }
    int counter=n;
    while(!pq.empty()){
    	int val=pq.top();
    	pq.pop();
    	label[val]=counter--;
    	rep(i,adj[val].size()){
    		indeg[adj[val][i]]--;
    		if(!indeg[adj[val][i]]){
    			pq.push(adj[val][i]);
    		}
    	}

    }
    rep(i,n){
    	cout<<label[i]<<endl;
    }
    return 0;      

}