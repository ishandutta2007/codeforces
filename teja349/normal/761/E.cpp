
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
vector< vl > adj(70);
vll vec(200);
int rotatid(ll &x,ll &y){
	if(x==0 && y==0){

		x=1;
		y=0;
		return 0;
		cout<<y<<endl;
	}
	else if(x==1){
		y=1;
		x=0;

	}
	else if(y==1){
		x=-1;
		y=0;
	}
	else if(x==-1){
		y=-1;
		x=0;
	}
	else if(y==-1){
		x=1;
		y=0;
	}
	return 0;
}
ll dfs(ll cur,ll dir1,ll dir2,ll prev,ll pos1,ll pos2,ll val){
	ll counti=0,i;
	rep(i,adj[cur].size()){
		
			counti++;

		
	}
	if(counti>4)
	{	

		cout<<"NO"<<endl;
		exit(0);
	}
	
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			rotatid(dir1,dir2);
			//cout<<dir1<<" "<<dir2<<endl;
			//cout<<adj[cur][i]<<endl;
			vec[adj[cur][i]]=mp(pos1+(val*dir1),pos2+(val*dir2));
			dfs(adj[cur][i],-1*dir1,-1*dir2,cur,pos1+val*dir1,pos2+val*dir2,val/2-1);

		}
	}

	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	ll n,i,u,v;
	cin>>n;
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);

		adj[v].pb(u);
	}
	ll val=pow(2,40);
	//cout<<val<<endl;
	
	vec[0]=mp(0,0);
	dfs(0,0,0,-1,0,0,val);
	cout<<"YES"<<endl;
	rep(i,n){
		cout<<vec[i].ff<<" "<<vec[i].ss<<endl;
	}
	return 0;
}