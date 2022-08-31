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
vector<vi> adj(123456);
ll a[123456];
map<int,ll> even,mapi;
map<int,ll>::iterator it;
int odd[123456]; 
int dfs(int cur,int par){
	int i;
	if(adj[cur].size()==0){
		odd[cur]=1;
        return 0;
	}
	rep(i,adj[cur].size()){
		dfs(adj[cur][i],cur);
		if(odd[adj[cur][i]])
			odd[cur]=0;
		else
			odd[cur]=1;
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n;
   ll i;
    rep(i,n){
    	cin>>a[i];
    }
    ll val;
    f(i,1,n){
    	cin>>val;
    	val--;
    	adj[val].pb(i);
    }
    dfs(0,-1);
    ll ans=0;
    ll counti=0;
    rep(i,n){
    	if(odd[i]){
    		ans^=a[i];
           // cout<<i<<" ";
    		counti++;
    	}
    }
    //cout<<endl;
    rep(i,n){
    	if(odd[i]){
    		mapi[a[i]]++;
    	}
    	else
    		even[a[i]]++;
    }
    ll sumi=0;
    if(ans==0){
    	sumi+=counti*(counti-1)/2;
    	counti=n-counti;
    	sumi+=(counti)*(counti-1)/2;
    	for(it=mapi.begin();it!=mapi.end();it++){
    		sumi+=(it->ss)*(even[it->ff]);
    	}
    	cout<<sumi<<endl;
    }
    else{
       // cout<<ans<<endl;
    	for(it=mapi.begin();it!=mapi.end();it++){
    		ans^=(it->ff);
    		sumi+=(it->ss)*(even[ans]);
    		ans^=(it->ff);
    	}
    	cout<<sumi<<endl;
    }	
    
}