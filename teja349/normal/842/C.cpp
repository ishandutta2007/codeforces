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

vector< vi > adj(212345);
vector< set<int> > seti(212345);
int a[212345],haha[212345];
int calc(int cur,int val,int par){
	if(par==-1){
		seti[val].insert(a[val]);
		seti[val].insert(a[cur]);
		return 0;
	}
	set<int>::iterator it;
	for(it=seti[cur].begin();it!=seti[cur].end();it++){
		seti[val].insert(__gcd(*it,a[val]));
	}
	seti[val].insert(haha[cur]);
	return 0;
}
int dfs(int cur,int par){
	if(par!=-1){
		haha[cur]=__gcd(haha[par],a[cur]);
	}
	else{
		haha[cur]=a[cur];
	}
	int i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			calc(cur,adj[cur][i],par);
			dfs(adj[cur][i],cur);
		}
		
	}
	return 0;
}
int main(){
    //std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int u,v;
    int i;
    rep(i,n){
    	scanf("%d",&a[i]);
    }
    //int i;
    rep(i,n-1){
    	scanf("%d%d",&u,&v);
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    seti[0].insert(a[0]);
    //ans[0]=a[0];
    dfs(0,-1);
    set<int>::iterator it;
    rep(i,n){
    	it=seti[i].end();
    	it--;
    	printf("%d\n",*it);
    }


    return 0;  
    
}