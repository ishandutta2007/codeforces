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
vector<vi> adj(123456);
 ll n,m,k,x;
 ll dp[123456][4][13];
int dfs(int cur,int par){
	//cout<<cur<<endl;
	int i,j,flag=0,haha;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			flag=1;
			dfs(adj[cur][i],cur);
		}
	}
	if(flag==0){
		dp[cur][1][1]=1;
		dp[cur][2][0]=m-k;
		dp[cur][0][0]=k-1;
		return 0;
	}
	else{
		dp[cur][0][0]=(k-1);

		rep(haha,adj[cur].size()){
			if(adj[cur][haha]!=par){
				int val=adj[cur][haha];
				fd(i,x,0){
					fd(j,x,0){
						if(i+j>x)
							continue;
						ll val1=(dp[val][0][j]+dp[val][1][j]+dp[val][2][j]);
						val1%=mod;
						if(j!=0){
							dp[cur][0][i+j]+=val1*dp[cur][0][i];

							dp[cur][0][i+j]%=mod;
						}
						else{
							dp[cur][0][i+j]=val1*dp[cur][0][i];

							dp[cur][0][i+j]%=mod;
						}
					}
				}
			}

		}
		dp[cur][1][1]=1;
		rep(haha,adj[cur].size()){
			if(adj[cur][haha]!=par){
				int val=adj[cur][haha];
				fd(i,x,0){
					fd(j,x,0){
						if(i+j>x)
							continue;
						ll val1=(dp[val][0][j]);
						val1%=mod;
						if(j!=0){
							dp[cur][1][i+j]+=val1*dp[cur][1][i];

							dp[cur][1][i+j]%=mod;
						}
						else{
							dp[cur][1][i+j]=val1*dp[cur][1][i];

							dp[cur][1][i+j]%=mod;
						}
					}
				}
			}

		}
		dp[cur][2][0]=m-k;
		rep(haha,adj[cur].size()){
			if(adj[cur][haha]!=par){
				int val=adj[cur][haha];
				fd(i,x,0){
					fd(j,x,0){
						if(i+j>x)
							continue;
						ll val1=(dp[val][0][j]+dp[val][2][j]);
						val1%=mod;
						if(j!=0){
							dp[cur][2][i+j]+=val1*dp[cur][2][i];

							dp[cur][2][i+j]%=mod;
						}
						else{
							dp[cur][2][i+j]=val1*dp[cur][2][i];

							dp[cur][2][i+j]%=mod;
						}
					}
				}
			}

		}
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    
    cin>>n>>m;
    int u,v,i,j;
    rep(i,n-1){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    
    cin>>k>>x;
    dfs(0,-1);

    ll sumi=0;
    rep(i,x+1){
    	rep(j,3){
    		//cout<<i<<" "<<j<<" "<<dp[0][j][i]<<endl;
    		sumi+=dp[0][j][i];
    		sumi%=mod;
    	}
    }
    cout<<sumi<<endl;
    return 0;  
    
}