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
int counter=0,timer=0,visit[123456],haha[123456],subtree[123456],pre[123456],post[123456];
int lol[123456];
vector<vi> adj(123456);
int dfs(int cur){
	visit[cur]=counter;
	subtree[cur]=1;
	pre[cur]=timer++;
	int i;
	rep(i,adj[cur].size()){
		dfs(adj[cur][i]);
		subtree[cur]+=subtree[adj[cur][i]];
	}
	post[cur]=timer++;
	return 0;
}
int inn(int a,int b){
	//cout<<post[b]<<" "<<post[a]<<endl;
	if(pre[b]<pre[a] && post[a]<post[b]){
		return 1;
	}
	return 0;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    int i,a,b;
    rep(i,k){
    	cin>>a>>b;
    	if(haha[b]==0){
    		haha[b]=a;
    	}
    	else{
    		lol[a]=1;
    		//par[a]=haha[b];
    		adj[haha[b]].pb(a);
    		haha[b]=a;
    	}

    }
    f(i,1,n+1){
    	if(!lol[i]){
    		counter++;
    		dfs(i);
    	}
    }
    rep(i,q){
    	cin>>a>>b;
    	if(haha[b]==0){
    		cout<<0<<endl;
    	}
    	else{
    		//cout<<"boo";
    		if(visit[a]!=visit[haha[b]]){
    			//cout<<"saa";
    			cout<<0<<endl;
    		}
    		else if(inn(haha[b],a)){
    			cout<<subtree[a]<<endl;
    		}
    		else{
    			//cout<<"SAs";
    			cout<<0<<endl;
    		}
    	}
    }

}