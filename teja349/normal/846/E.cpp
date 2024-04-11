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
vector<vl> adj(123456);
ll w[123456],a[123456],b[123456];
ll iinf;
int add(ll &a,ll &b,ll &c){
	ll val;
	if(iinf/c>abs(b)){
		val=b*c;
	}
	else {
		cout<<"NO"<<endl;
		exit(0);
	}
	a+=val;
	if(abs(a)>iinf)
	{
		cout<<"NO"<<endl;
		exit(0);
	}
	return 0;

}  
int dfs(int cur,int par){
	int i,flag=0;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs(adj[cur][i],cur);
			flag=1;
		}
	}
	b[cur]-=a[cur];
	if(par==-1){
		if(b[cur]<0)
		{
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
		exit(0);
	}
	else{
		if(b[cur]>=0){
			b[par]+=b[cur];

		}
		else{
			add(b[par],b[cur],w[cur]);
		}
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
	int n,dep;
	cin>>n;
	iinf=inf;
	iinf*=inf;
	int i;
	rep(i,n){
		cin>>b[i];
	}    
	rep(i,n){
		cin>>a[i];

	}

	f(i,1,n){
		cin>>dep>>w[i];
		dep--;
		adj[dep].pb(i);
		adj[i].pb(dep);
	}
	dfs(0,-1);
    return 0;  
    
}