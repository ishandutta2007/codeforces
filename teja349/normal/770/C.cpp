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
int req[123456],visited[123456]={0},indeg[123456]={0},visit1[123456],arr[123456];
vector<vi> adj(123456);
int n;
vi vectop;   
int toposort(){
	stack<int> st;
	int i;
	rep(i,n){
		if(indeg[i]==0){
			st.push(i);
		}
	}

	while(!st.empty()){
		int haha=st.top();
		vectop.pb(haha);
		visit1[haha]=1;
		st.pop();
		rep(i,adj[haha].size()){
			indeg[adj[haha][i]]--;
			if(!indeg[adj[haha][i]])
				st.push(adj[haha][i]);
		}


	}
	return 0;

}
int dfs(int cur){
	if(visited[cur])
		return 0;
	visited[cur]=1;
	int i;
	rep(i,adj[cur].size()){
		dfs(adj[cur][i]);
	}
	rep(i,adj[cur].size()){
		if(req[adj[cur][i]])
			req[cur]=1;
	}
	return 0;


}
int main(){
	std::ios::sync_with_stdio(false);
	int k,i,val,lol,j;
	cin>>n>>k;
	rep(i,k){
		cin>>val;
		arr[i]=val;
		val--;
		req[val]=1;
	}
	rep(i,n){
		cin>>val;
		rep(j,val){
			cin>>lol;
			lol--;
			indeg[i]++;
			adj[lol].pb(i);

		}
	}
	
	toposort();
	rep(i,vectop.size()){
		dfs(vectop[i]);
	}
	int counter=0;
	rep(i,k){
		if(!visit1[arr[i]-1])
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	rep(i,vectop.size()){
		if(req[vectop[i]])
			counter++;
			
	}
	cout<<counter<<endl;
	rep(i,vectop.size()){
		if(req[vectop[i]])
			cout<<vectop[i]+1<<" ";
	}
	cout<<endl;


}