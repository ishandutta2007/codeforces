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
int indeg[123456]={0};
vector<vi> adj(123456);
vii edge;
stack<int> st;  
int n,m; 
int check(int val){
	int i,haha=0,counter=0,u,v;
	//st.erase();
	rep(i,n){
		adj[i].clear();
		indeg[i]=0;
	}
	rep(i,val){
		u=edge[i].ff;
		v=edge[i].ss;
		adj[v].pb(u);
		indeg[u]++;
	}
	while(!st.empty()){
		st.pop();
	}
	rep(i,n){
		if(indeg[i]==0){
			st.push(i);
			counter++;
			//haha++;
		}
	}
	int value;

	while(!st.empty()){
		if(counter>1){
			return 0;
		}
		haha++;
		counter--;
		value=st.top();
		st.pop();
		rep(i,adj[value].size()){
			indeg[adj[value][i]]--;
			if(indeg[adj[value][i]]==0){
				st.push(adj[value][i]);
				counter++;
			}
		}

	}
	if(haha==n){
		return 1;
	}
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	int i,u,v;
	cin>>n>>m;
	rep(i,m){
		cin>>u>>v;
		u--;
		v--;
		edge.pb(mp(u,v));
		
	}
	int low=1;
	int high=m;
	int mid;
	int ans=-1;
	//cout<<check(4)<<endl;
	while(low<=high){
		mid=(low+high)/2;
		//mid=4;
	//	cout<<low<<"  "<<high<<"  "<<mid<<endl;
		if(check(mid)){
			ans=mid;
			//cout<<ans<<endl;
			high=mid-1;
		}
		else{
			low=mid+1;
		}

	}
	cout<<ans<<endl;
}