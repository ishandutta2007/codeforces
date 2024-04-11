
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
#define inf 1000*1000*1000+5
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod 1000*1000*1000+7

vector<vi> adj(212345);
int c[212345],visit[212345];
unordered_map<int,int> mapi;
unordered_map<int,int>::iterator it;
int dfs(int cur){
	visit[cur]=1;
	
	mapi[c[cur]]++;
	int i;
	rep(i,adj[cur].size()){
		if(!visit[adj[cur][i]]){
			dfs(adj[cur][i]);
		}
	}
	return 0;

}

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int i,u,v;
	rep(i,n){
		cin>>c[i];

	}
	rep(i,m){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int sumi=0,maxi;
	rep(i,n){
		if(!visit[i]){
			mapi.clear();
			maxi=0;
			
			dfs(i);
			for(it=mapi.begin();it!=mapi.end();it++){
				maxi=max(maxi,it->ss);
				//cout<<maxi<<endl;
				//it->ss=0;
			}
			sumi+=maxi;
		}
	}
	cout<<n-sumi<<endl;


}