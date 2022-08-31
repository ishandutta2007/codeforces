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
int comp=1;  
vector<vi> adj(123456),haha(123456);
int par[123456][18],zero[123456][18],one[123456][18];
int lev[123456],visit[123456],n;
int dfs(int cur,int despo){
	int i;
	lev[cur]=despo;
	visit[cur]=comp;
	rep(i,adj[cur].size()){
		dfs(adj[cur][i],despo+1);
		one[adj[cur][i]][0]=haha[cur][i];
		zero[adj[cur][i]][0]=haha[cur][i];
	}
	return 0;

}
int precompute(){
	int i,j;
	f(j,1,18){
		rep(i,n){
			if(par[i][j-1]!=-1)
				par[i][j]=par[par[i][j-1]][j-1];
			else
				par[i][j]=-1;
		}
	}
	f(j,1,18){
		rep(i,n){
			if(par[i][j]!=-1){
				zero[i][j]=min(zero[par[i][j-1]][j-1],zero[i][j-1]);
				one[i][j]=max(one[par[i][j-1]][j-1],one[i][j-1]);
			}
			else{
				zero[i][j]=0;
				one[i][j]=1;
			}
		}
	}
	return 0;

}
int findlca(int u,int v){
	int i;
	if(lev[u]<lev[v]){
		swap(u,v);
	}
	fd(i,17,0){
		if(lev[u]-(1<<i)>=lev[v]){
			u=par[u][i];
		}
	}
	if(u==v)
		return u;
	fd(i,17,0){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}
int findmax(int v,int u){
	int i;
	int maxi=0;
	fd(i,17,0){
		if(lev[u]-(1<<i)>=lev[v]){
			//cout<<one[u][i]<<"add"<<endl;
			maxi=max(maxi,one[u][i]);
			u=par[u][i];
		}
	}
	return maxi;
}
int findmin(int v,int u){
	int maxi=1;
	int i;
	fd(i,17,0){
		if(lev[u]-(1<<i)>=lev[v]){
			
			maxi=min(maxi,zero[u][i]);
			u=par[u][i];
		}
	}
	return maxi;
}

int main(){
    std::ios::sync_with_stdio(false);
    //int n;
    cin>>n;
    int i,type;
    rep(i,n){
    	cin>>par[i][0]>>type;
    	
    	if(type==-1){
    		continue;
    	}
    	par[i][0]--;
    	adj[par[i][0]].pb(i);
    	haha[par[i][0]].pb(type);
    	//adj[i].pb(par[i]);
    }
    rep(i,n){
    	if(!visit[i]){
    		comp++;
    		dfs(i,0);
    	}
    }
    precompute();
    //return 0;
    int q;
    cin>>q;
    while(q--){
    	int baba,u,v;
    	cin>>baba>>u>>v;
    	u--;
    	v--;
    	int lca;
    	if(u==v || visit[u]!=visit[v]){
    		cout<<"NO"<<endl;
    		continue;
    	}
    	if(baba==1){
    		lca=findlca(u,v);
    		//return 0;
    		if(lca!=u){
    			cout<<"NO"<<endl;
    			continue;
    		}
    		int val=findmax(u,v);
    		if(val==0){
    			cout<<"YES"<<endl;
    		}
    		else{
    			cout<<"NO"<<endl;
    		}
    	}
    	else{
    		lca=findlca(u,v);
    		if(v==lca){
    			cout<<"NO"<<endl;
    			continue;
    		}
    		int val=findmax(lca,u);
    		//cout<<val<<endl;

    		if(val==0){
    			val=findmin(lca,v);
    			 //cout<<lca<<" "<<v <<endl;
    			if(val==1)
    				cout<<"YES"<<endl;
    			else
    				cout<<"NO"<<endl;
    		}
    		else{
    			cout<<"NO"<<endl;
    		}
    	}
    }
    return 0;  
    
}