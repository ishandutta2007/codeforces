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
ll binom[123456],stirl[123456],dp[123456];
ll powt(ll b){
	ll ans=1;
	ll a=2;
	while(b>0){
		if(b%2){
			ans*=a;
			ans%=mod;
		}
		a*=a;
		a%=mod;
		b/=2;
	}
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
   ll i,j;
    rep(i,m+1){
    	stirl[i]=0;
    }
    stirl[0]=1;
    f(i,1,m+1){
    	f(j,1,m+1){
    		dp[j]=j*stirl[j]+stirl[j-1];
    		dp[j]%=mod;
    	}
    	dp[0]=0;
    	rep(j,m+1){
    		stirl[j]=dp[j];
    	}
    }
    ll haha,val=min(n,m);
   	binom[0]=1;
   	f(i,1,val+1){
   		binom[i]=binom[i-1]*(n+1-i);
   		binom[i]%=mod;
   		
   	}
   //	ans=1;
   	ll ans=0;
   	rep(i,val+1){
   		haha=binom[i]*stirl[i];
   		haha%=mod;
   		haha*=powt(n-i);
   		haha%=mod;
   		ans+=haha;
   		ans%=mod;
   	}
   	cout<<ans<<endl;
    return 0;  
    
}