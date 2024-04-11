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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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
multiset<int> seti;
multiset<int>::iterator it;
vector<vi> adj(323456);
int a[312345];
int finder(int val){
	int haha=a[val];
	it=seti.find(a[val]);
	seti.erase(it);
	int i;
	rep(i,adj[val].size()){
		it=seti.find(a[adj[val][i]]);
		seti.erase(it);
		haha=max(haha,a[adj[val][i]]+1);
	}
	if(!seti.empty()){
		it=seti.end();
		it--;
		haha=max(haha,*it +2);
	}
	seti.insert(a[val]);
	rep(i,adj[val].size()){
		seti.insert(a[adj[val][i]]);
		//seti.erase(it);
		//haha=max(haha,a[adj[val][i]]+1);
	}
	return haha;

}
int main(){
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int i,u,v,mini=inf;
	rep(i,n){
		cin>>a[i];
		seti.insert(a[i]);
		//pq.push(mp(a[i],i))
	}
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	//return 0;
	rep(i,n){
		int val=finder(i);
		//cout<<val<<endl;
		mini=min(mini,val);
	}
	cout<<mini<<endl;

}