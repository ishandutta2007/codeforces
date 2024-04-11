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
vector<vi> adj(212345);
int visit[212345],dist[212345]; 
struct total{
	int a,b,c;
};
vector<total> vec;
int dfs(int cur,int par){
	visit[cur]=1;
	stack<int> st;
	if(par!=-1)
		dist[cur]=dist[par]+1;
	int i;
	rep(i,adj[cur].size()){
		if(!visit[adj[cur][i]]){
			dfs(adj[cur][i],cur);
		}
		if(adj[cur][i]!=par && dist[adj[cur][i]]<dist[cur]){
			if(dist[adj[cur][i]]==-1)
				dist[adj[cur][i]]=inf;
			
			st.push(adj[cur][i]);
			if(st.size()==2){
				int val1=st.top();
				st.pop();
				int val2=st.top();
				st.pop();
				total haha;
				haha.a=val1;
				haha.b=cur;
				haha.c=val2;
				vec.pb(haha);
				//ans++;
			}

		}

	}
	if(par==-1){
		return 0;
	}
	if(st.size()==1){
		
		int val1=st.top();
		st.pop();
		total haha;
				haha.a=val1;
				haha.b=cur;
				haha.c=par;
		vec.pb(haha);
	}
	else{
		dist[cur]=-1;
	}
	return 0;

}
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i,j,u,v;
    rep(i,m){
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    f(i,1,n+1){
    	if(!visit[i]){
    		dfs(i,-1);
    	}
    }
    cout<<vec.size()<<endl;
    rep(i,vec.size()){
    	cout<<vec[i].a<<" "<<vec[i].b<<" "<<vec[i].c<<endl;
    }
    return 0;  
    
}