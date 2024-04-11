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
#define mod (998244353)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
ll dp[512][512],dp1[512][512];
ll wow[512];
int main(){
    std::ios::sync_with_stdio(false);
   ll n,kk;
   ll i,j,k;
    cin>>n>>kk;
    dp[1][1]=1;
    f(i,1,n){
    	f(j,1,n+2){
    		f(k,1,j+1){
    			dp1[max(j,k+1)][k+1]+=dp[j][k];
    			dp1[j][1]+=dp[j][k];
    			dp1[j][1]%=mod;
    			dp1[max(j,k+1)][k+1]%=mod;
    		}
    	}
    	rep(j,n+2){
    		rep(k,n+2){
    			dp[j][k]=dp1[j][k];
    			dp1[j][k]=0;
    		}
    	}

    }
    f(i,1,n+1){
    	rep(j,n+1){
    		wow[i]+=dp[i][j];
    		wow[i]%=mod;
    	}
    }
    ll ans=0;
    rep(i,n+1){
    	rep(j,n+1){
    		if(i*j<kk){
    			ans+=wow[i]*wow[j];
    			ans%=mod;
    		}
    	}
    }
    ans*=2;
    ans%=mod;
    cout<<ans<<endl;
    return 0;     
}