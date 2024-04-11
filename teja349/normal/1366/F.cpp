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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define int ll
int check(pii a,pii b,pii c){
	if((a.ss-b.ss)*(c.ff-a.ff) < (a.ss-c.ss)*(b.ff-a.ff))
		return 0;

	return 1;	
}

int getinter(pii a, pii b){
	if(a.ss-b.ss<0)
		return -1;
	return (a.ss-b.ss)/(b.ff-a.ff);
}
int getans(pii a,int st,int en){
	int ans=a.ss*(en-st+1);
	ans%=mod;
	int val=en*(en+1)-(st)*(st-1);
	val/=2;
	val%=mod;
	val*=a.ff;
	val%=mod;
	ans+=val;
	ans%=mod;
	return ans;
}
vector<vi> adj(2123),wt(2123);
int dp[2123][2123];
int maxwt[2123];
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    int i,j,k;
    int u,v,w;
    rep(i,m){
    	cin>>u>>v>>w;
    	u--;
    	v--;
    	adj[u].pb(v);
    	wt[u].pb(w);
    	adj[v].pb(u);
    	wt[v].pb(w);
    	maxwt[u]=max(maxwt[u],w);
    	maxwt[v]=max(maxwt[v],w);
    }
    ll iinf=inf;
    iinf*=inf;
    rep(i,n){
    	rep(j,n){
    		dp[i][j]=-1*iinf;
    	}
    }
    dp[0][0]=0;
    ll ans=0;
    rep(i,n){
    	ll maxi=0;
    	rep(j,n){
    		rep(k,adj[j].size()){
    			u=adj[j][k];
    			w=wt[j][k];
    			dp[i+1][u]=max(dp[i+1][u],dp[i][j]+w);
    		}
    		maxi=max(maxi,dp[i][j]);
    	}
    	if(i<=q){
    		//cout<<maxi<<endl;
    		ans+=maxi;
    		ans%=mod;
    	}
    }
    q-=n;
    if(q<0){
    	cout<<ans<<endl;
    	return 0;
    }
    map<int,int> mapi;
    map<int,int>::iterator it;
    rep(i,n){
    	//cout<<maxwt[i]<<" "<<dp[n][i]<<endl;
    	if(dp[n][i]<0)
    		continue;
    	mapi[maxwt[i]]=max(mapi[maxwt[i]],dp[n][i]);
    }
    vii vec;
    for(it=mapi.begin();it!=mapi.end();it++){
    	vec.pb(mp(it->ff,it->ss));
    }
    vii vec1;
    int sz=0;
    rep(i,12345){
    	vec1.pb(mp(0,0));
    }
    rep(i,vec.size()){
    	//cout<<vec[i].ff<<" "<<vec[i].ss<<endl;
    	while(sz>=2 && check(vec1[sz-2],vec1[sz-1],vec[i])){
    		sz--;
    	}
    	vec1[sz]=vec[i];
    	sz++;
    }
    int st=0;
    rep(i,sz-1){
    	int cur=getinter(vec1[i],vec1[i+1]);
    	if(cur<st)
    		continue;
    	if(cur>=st){
    		//cout<<vec1[i+1].ff<<" dsad"<<endl;
    		ans+=getans(vec1[i],st,min(cur,q));
    		ans%=mod;
    		st=min(cur,q)+1;
    	}
    	if(st>q)
    		break;
    }
    if(st<=q){
    	ans+=getans(vec1[sz-1],st,q);
    	ans%=mod;
    }
    cout<<ans<<endl;
    
    return 0;   
}