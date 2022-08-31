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
int root;
vector< set<int> > adj(212345);
int visit[212345]={0};
int dfs(int cur){
	//cout<<cur<<endl;
	visit[cur]=1;
	int i;
	//cout<<cur<<" f "<<root<<endl;
	if(adj[cur].size()!=adj[root].size()){
		cout<<"NO"<<endl;
		exit(0);
	}
	set<int>::iterator it1,it2;
	it1=adj[cur].begin();
	it2=adj[root].begin();
	rep(i,adj[cur].size()){
		if((*it1)!=(*it2)){
			cout<<"NO"<<endl;
			exit(0);
		}
		
		it1++;
		it2++;

	}
	it1=adj[cur].begin();
	rep(i,adj[cur].size()){
		if(!visit[*it1])
			dfs(*it1);
		it1++;
	}
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,u,v;
	cin>>n>>m;
	rep(i,n){
		adj[i].insert(i);
	}
	rep(i,m){
		cin>>u>>v;
		u--;
		v--;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	rep(i,n){
		root=i;
		if(!visit[i])
			dfs(i);
	}
	cout<<"YES"<<endl;
	return 0;

}