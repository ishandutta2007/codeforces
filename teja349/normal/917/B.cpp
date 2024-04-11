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

//std::ios::sync_with_stdio(false);   
int visit[123][123][123][2],dp[123][123][123][2];
vector<vii> adj(123);
int compute(int p,int q,int previ,int turn){
	if(visit[p][q][previ][turn])
		return dp[p][q][previ][turn];
	int val,i,haha;
	visit[p][q][previ][turn]=1;
	if(turn==1){
		if(previ==adj[q].size()){
			dp[p][q][previ][turn]=0;
			return 0;
		}
		val=compute(p,q,previ+1,turn);
		if(val==1){
			dp[p][q][previ][turn]=1;
			return 1;
		}
		haha=lower_bound(all(adj[p]),mp(adj[q][previ].ff,-1))-adj[p].begin();
		//haha-=adj[p].begin();
		val=compute(p,adj[q][previ].ss,haha,turn^1);
		dp[p][q][previ][turn]=val;
		return val;
	}
	else{
		dp[p][q][previ][turn] = compute(q,p,previ,turn^1)^1;
		return dp[p][q][previ][turn];
	}
	return 0;

}
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i,j;
    int u,v;
    char ch;
    rep(i,m){
    	cin>>u>>v>>ch;
    	u--;
    	v--;
    	adj[u].pb(mp(ch-'a'+1,v));
    	//edge[u].pb(ch-'a'+1);
    }
    rep(i,n){
    	sort(all(adj[i]));
    }
    int val;
    rep(i,n){
    	rep(j,n){
    		val=compute(i,j,0,0);
    		if(val==0){
    			cout<<"A";
    		}
    		else{
    			cout<<"B";
    		}
    	}
    	cout<<endl;
    }
    return 0;  
    
}