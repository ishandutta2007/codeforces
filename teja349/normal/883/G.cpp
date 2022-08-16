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
int visit[312345],visit1[312345],t[312345],u[312345],v[312345],deed[312345];
vector<vi> adj(312345);
int su=0;
int dfs1(int cur){
	visit[cur]=1;
	su++;
	int j,ind;
	rep(j,adj[cur].size()){
		ind=adj[cur][j];
		if(t[ind]!=2){
			if(t[ind]==1 && u[ind]==cur){
				if(!visit[v[ind]]){
					dfs1(v[ind]);
				}
			}
			else if(t[ind]==-1 && v[ind]==cur){
				if(!visit[u[ind]])
					dfs1(u[ind]);
			}
		}
		else{
			if(u[ind]==cur)
				t[ind]=-1;
			else
				t[ind]=1;
		}
	}
	return 0;

}
int dfs2(int cur){
	visit1[cur]=1;
	su++;
	int j,ind;
	rep(j,adj[cur].size()){
		ind=adj[cur][j];
		if(t[ind]!=2){
			if(t[ind]==1 && u[ind]==cur){
				if(!visit1[v[ind]]){
					dfs2(v[ind]);
				}
			}
			else if(t[ind]==-1 && v[ind]==cur){
				if(!visit1[u[ind]])
					dfs2(u[ind]);
			}
		}
		else{
			if(u[ind]==cur){
				t[ind]=1;
				if(!visit1[v[ind]])
					dfs2(v[ind]);
			}
			else{
				t[ind]=-1;
				if(!visit1[u[ind]])
					dfs2(u[ind]);
			}
		}
	}
	return 0;

}
int main(){
    std::ios::sync_with_stdio(false);
    int n,m,s;
    cin>>n>>m>>s;
    int i;
    rep(i,m){
    	cin>>t[i]>>u[i]>>v[i];
    	//sec[i]=t[i];
    	deed[i]=t[i];
    	adj[u[i]].pb(i);
    	if(t[i]==2){
    		adj[v[i]].pb(i);
    		//adj[v[i]]
    	}
    }
    dfs2(s);
    cout<<su<<endl;
    rep(i,m){
    	if(deed[i]==2){
    		if(t[i]==-1)
    			cout<<'-';
    		else
    			cout<<'+';
    	}
    	t[i]=deed[i];

    }
    cout<<endl;
    su=0;
    dfs1(s);
    cout<<su<<endl;
    rep(i,m){
    	if(deed[i]==2){
    		if(t[i]==-1)
    			cout<<'-';
    		else
    			cout<<'+';
    	}

    }
    cout<<endl;
    return 0;  
    
}