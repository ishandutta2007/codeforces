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
vector<vl> adj(1234);
vll vec;
ll counter=0;
ll n;
map<ll,ll> mapi;
ll dp[100][100];
ll check(ll mid){
	ll i,j,adder;
	rep(i,counter+10){
		adj[i].clear();
	}
	rep(i,vec.size()){
		adder=vec[i].ff-mid*vec[i].ss;
		//cout<<adder<<endl;
		adj[mapi[vec[i].ff]].pb(adder);
	}
	rep(i,counter){
		sort(all(adj[i]));
	}
	ll iinf=inf;
	iinf*=inf;
	rep(i,n+3){
		dp[counter][i]=iinf;
	}
	ll k;
	ll sumi=0;
	dp[counter][0]=0;
	//cout<<counter<<endl;
	//n=2;
	fd(i,counter-1,0){
		
		rep(j,n+1){
			sumi=0;
			dp[i][j]=iinf;
			ll siz=adj[i].size();
			if(j+siz<=n){
				//cout<<siz<<endl;
				dp[i][j]=dp[i+1][j+siz];
				//cout<<dp[i][j]<<endl;
			}
			rep(k,adj[i].size()){
				sumi+=adj[i][k];
				k++;
				ll previ = j-k+siz-k;
				if(previ>=siz-k && previ>=0 && previ<=n){
					//cout<<j<<"csfd"<<previ<<endl;
					dp[i][j]=min(dp[i][j],dp[i+1][previ]+sumi);
				}
				k--;
			}
		}
	}
	rep(i,n+1){
		//cout<<mapi[10000]<<endl;
		//cout<<i<<" "<<dp[0][i]<<endl;
		if(dp[0][i]<=0){
			
			return 1;
		}
	}
	return 0;
}
ll a[123],b[123];
int main(){
    std::ios::sync_with_stdio(false);
    
    cin>>n;
    ll i;
    rep(i,n){
    	cin>>a[i];
    	a[i]*=1000;
    	mapi[a[i]]=1;
    }
    map<ll,ll>::iterator it;
    for(it=mapi.begin();it!=mapi.end();it++){
    	it->ss=counter++;
    }
    rep(i,n){
    	cin>>b[i];
    }
    rep(i,n){
    	vec.pb(mp(a[i],b[i]));
    }
    sort(all(vec));
    ll low=0;
    ll high=inf;
    high*=1000;
    ll mid,ans;
    //cout<<check(1160)<<endl;
    //return 0;
    while(low<=high){
    	mid=(low+high)/2;
    	if(check(mid)){
    		ans=mid;
    		high=mid-1;
    	}
    	else{
    		low=mid+1;
    	}
    }
    cout<<ans<<endl;
    return 0;  
    
}