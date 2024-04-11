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
int dp[5002][5002][2];
vector<vi> adj(12345);
int subtree[5004],c[5003],d[5003],dp1[5003],dp2[5003];
int dfs(int u){
	//cout<<u<<endl;
	int i,j,k,sumi=1;
	subtree[u]=1;
	rep(i,adj[u].size()){
		dfs(adj[u][i]);
		subtree[u]+=subtree[adj[u][i]];
	}
	if(subtree[u]==1){
		dp[u][1][0]=c[u];
		dp[u][1][1]=c[u]-d[u];
		dp[u][0][1]=0;
		dp[u][0][0]=0;
		return 0;
	}
	rep(i,subtree[u]+2){
		dp1[i]=inf;
		//cout<<"Daas"
		dp2[i]=inf;
		dp[u][i][0]=inf;
		dp[u][i][1]=inf;
	}
	//dp[u][1][0]=c[u];
	dp[u][1][1]=c[u]-d[u];
	//dp[u][0][0]=inf;
	//dp[u][0][1]=0;
	sumi=1;
	rep(i,adj[u].size()){
		rep(j,sumi+1){
			rep(k,subtree[adj[u][i]]+1){
				dp1[j+k]=min(dp1[j+k],dp[u][j][1]+dp[adj[u][i]][k][1]);
				dp1[j+k]=min(dp1[j+k],inf);
				
			}
		}
		sumi+=subtree[adj[u][i]];
		rep(j,sumi+1){
			dp[u][j][1]=min(dp[u][j][1],dp1[j]);
			dp1[j]=inf;
		}
	}
	sumi=1;
	
	dp1[0]=0;

	rep(i,adj[u].size()){
		rep(j,sumi+1){
			rep(k,subtree[adj[u][i]]+1){
				dp2[j+k]=min(dp2[j+k],dp1[j]+dp[adj[u][i]][k][0]);
				dp2[j+k]=min(dp2[j+k],inf);
			}
		}
		sumi+=subtree[adj[u][i]];
		rep(j,sumi+1){
			dp1[j]=min(dp1[j],dp2[j]);
			dp2[j]=inf;
		}
	}
	rep(i,subtree[u]+1){
		dp[u][i][1]=min(dp[u][i][1],dp1[i]);
		dp1[i]=inf;
	}
	dp[u][1][0]=c[u];
	dp[u][0][0]=0;
	
	//dp[u][0][0]=inf;
	//dp[u][0][1]=0;
	sumi=1;
	rep(i,adj[u].size()){
		
		rep(j,sumi+1){
			rep(k,subtree[adj[u][i]]+1){
				
				dp1[j+k]=min(dp1[j+k],dp[u][j][0]+dp[adj[u][i]][k][0]);
				dp1[j+k]=min(dp1[j+k],inf);
					
			}

		}

		sumi+=subtree[adj[u][i]];
		rep(j,sumi+1){
			dp[u][j][0]=min(dp[u][j][0],dp1[j]);
			dp1[j]=inf;
		}
	}
	return 0;
	//sumi=0;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n,val;
    int i,u;
    cin>>n>>val;
    cin>>c[0]>>d[0];
    f(i,1,n){
    	cin>>c[i]>>d[i];
    	cin>>u;
    	u--;
    	adj[u].pb(i);    	
    }
    dfs(0);
    fd(i,n,0){
    	if(dp[0][i][1]<=val){
    		
    		cout<<i<<endl;
    		return 0;
    	}
    }


    
    
}