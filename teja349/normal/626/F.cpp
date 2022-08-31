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
int n,k;
 int a[1234];
 int dp[202][202][1234];
int pushall(int i,int j,int val){
	//cout<<i<<" "<<j<<" "<<val<<endl;
	int val1=val+j*(a[i+1]-a[i]);
	if(val1>k){
		return 0;
	}
	//cout<<val1<<endl;
	dp[i+1][j][val1]+=(1LL*(j+1)*dp[i][j][val])%mod;
	dp[i+1][j+1][val1]+=dp[i][j][val];
	//return 0;
	if(j!=0)
		dp[i+1][j-1][val1]+=(1LL*j*dp[i][j][val])%mod;
	dp[i+1][j][val1]%=mod;
	dp[i+1][j][val1]%=mod;
	if(j!=0)
		dp[i+1][j-1][val1]%=mod;
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    
    cin>>n>>k;
    int i,j,p;
    f(i,1,n+1){
    	cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[0][0][0]=1;
    //return 0;
    rep(i,n+1){
    	rep(j,i+1){
    		rep(p,k+1){
    			pushall(i,j,p);
    		}
    		
    	}
    }
    ll sumi=0;
    rep(i,k+1){
    	sumi+=dp[n][0][i];
    	//cout<<dp[n][0][i]<<endl;
    	sumi%=mod;
    }
    cout<<sumi<<endl;

    return 0;      

}