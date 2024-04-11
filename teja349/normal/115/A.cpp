
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
vector< vi > adj(3000);
int p[3000];  
int dfs(int cur){
	int i;
	int maxi=0;
	rep(i,adj[cur].size()){

		maxi=max(maxi,dfs(adj[cur][i]));
	}
	return maxi+1;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,i;
	cin>>n;
	int mini=1;
	rep(i,n){
		cin>>p[i];
		if(p[i]<0)
			continue;
		p[i]--;

		adj[p[i]].pb(i);
	}
	rep(i,n){
		if(p[i]==-1){

			mini=max(mini,dfs(i));
		}
	}
	cout<<mini<<endl;
}