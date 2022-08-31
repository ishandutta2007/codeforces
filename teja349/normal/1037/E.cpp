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
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

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
vector<vi> adj(212345);
int u[212345],v[212345],lol[212345];
int remov[212345];
int deg[212345],ans[212345];
int main(){
    std::ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    int i,j;
    rep(i,m){
    	cin>>u[i]>>v[i];
    	u[i]--;
    	v[i]--;
    	adj[u[i]].pb(i);
    	adj[v[i]].pb(i);
    	deg[u[i]]++;
    	deg[v[i]]++;
    }
    set<pii> seti;
    rep(i,n){
    	seti.insert(mp(deg[i],i));
    }
    pii papa;
    int cur,edg;
    fd(i,m-1,0){
    	
    	while(!seti.empty()){
    		papa=*(seti.begin());
    		if(papa.ff<k){
    			deg[papa.ss]=0;
    			remov[papa.ss]=1;
    			seti.erase(papa);
    			cur=papa.ss;
    			rep(j,adj[papa.ss].size()){
    				edg=adj[cur][j];
    				
    				if(!lol[edg]){
    					lol[edg]=1;
    					if(!remov[u[edg]]){
    						seti.erase(mp(deg[u[edg]],u[edg]));
    						deg[u[edg]]--;
    						seti.insert(mp(deg[u[edg]],u[edg]));
    						//deg[u[edg]]--;
    					}
    					swap(u[edg],v[edg]);
    					if(!remov[u[edg]]){
    						seti.erase(mp(deg[u[edg]],u[edg]));
    						deg[u[edg]]--;
    						seti.insert(mp(deg[u[edg]],u[edg]));
    						//deg[u[edg]]--;
    					}
    				}
    			}
    		}
    		else{
    			break;
    		}
    	}
    	ans[i]=seti.size();
    	if(!lol[i]){
    		lol[i]=1;
    		edg=i;
    		if(!remov[u[edg]]){
				seti.erase(mp(deg[u[edg]],u[edg]));
				deg[u[edg]]--;
				seti.insert(mp(deg[u[edg]],u[edg]));
				//deg[u[edg]]--;
			}
			swap(u[edg],v[edg]);
			if(!remov[u[edg]]){
				seti.erase(mp(deg[u[edg]],u[edg]));
				deg[u[edg]]--;
				seti.insert(mp(deg[u[edg]],u[edg]));
				//deg[u[edg]]--;
			}
    	}
    }
    rep(i,m){
    	cout<<ans[i]<<endl;
    }
    return 0;   
}