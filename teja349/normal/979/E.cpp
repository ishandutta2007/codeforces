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
ll dp[55][55][55][55];
ll c[55],two[12354];
int main(){
    std::ios::sync_with_stdio(false);
    ll n,parpar;
    cin>>n>>parpar;
    ll i,j,k;
    two[0]=1;
    f(i,1,100){
    	two[i]=two[i-1]*2;
    	two[i]%=mod;
    }
    f(i,1,n+1){
    	cin>>c[i];
    }
    i=1;
    if(c[i]==0){
    	dp[1][1][1][0]=1;
    }
    else if(c[i]==1){
    	dp[1][0][0][1]=1;
    }
    else{
    	dp[1][1][1][0]=1;
    	dp[1][0][0][1]=1;
    }
    ll black,oddw,oddb,white,evenw,evenb,ans;
    f(i,2,n+1){
    	rep(black,i){
    		rep(oddb,black+1){
    			white=i-1-black;
    			evenb=black-oddb;
    			rep(oddw,white+1){
    				//cout<<dp[i][black][oddb][oddw]<<endl;
    				evenw=white-oddw;
    				if(c[i]==1 || c[i]==-1){
    					if(oddb==0){
    						ans=0;
    					}
    					else{
    						ans=two[oddb-1];
    					}
    					ans%=mod;
    					ans*=two[evenb+white];
    					ans%=mod;
    					dp[i][black][oddb][oddw]+=dp[i-1][black][oddb][oddw]*ans;
    					dp[i][black][oddb][oddw]%=mod;
    					if(oddb==0){
    						ans=1;
    					}
    					else{
    						ans=two[oddb-1];
    					}
    					ans*=two[evenb+white];
    					ans%=mod;
    					dp[i][black][oddb][oddw+1]+=dp[i-1][black][oddb][oddw]*ans;
    					dp[i][black][oddb][oddw+1]%=mod;
    				}
    				if(c[i]==0 || c[i]==-1){
    					if(oddw==0){
    						ans=0;
    					}
    					else{
    						ans=two[oddw-1];
    					}
    					ans*=two[evenw+black];
    					ans%=mod;
    					dp[i][black+1][oddb][oddw]+=dp[i-1][black][oddb][oddw]*ans;
    					dp[i][black+1][oddb][oddw]%=mod;
    					if(oddw==0){
    						ans=1;
    					}
    					else{
    						ans=two[oddw-1];
    					}
    					ans*=two[evenw+black];
    					ans%=mod;
    					dp[i][black+1][oddb+1][oddw]+=dp[i-1][black][oddb][oddw]*ans;
    					dp[i][black+1][oddb+1][oddw]%=mod;
    				}
    			}
    		}
    	}
    }
    //cout<<dp[2][1][1][1]<<endl;
    ans=0;
    rep(i,52){
    	rep(j,52){
    		rep(k,52){
    			if((j+k)%2==parpar)
    				ans+=dp[n][i][j][k];
    		}
    	}
    }
    ans%=mod;
    cout<<ans<<endl;
    return 0;  
    
}