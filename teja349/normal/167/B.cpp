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
double dp[205][405][205];
double p[1234];
int a[12345];
int main(){
    std::ios::sync_with_stdio(false);
    int n,l,k,i,j,r;
    cin>>n>>l>>k;
    //int i;
    f(i,1,n+1){
    	cin>>p[i];
    	p[i]/=100.00;
    }
    f(i,1,n+1){
    	cin>>a[i];
    }
    dp[0][201+k][0]=1;
    rep(i,n){
    	f(j,0,404){
    		rep(r,n+1){
    			if(!dp[i][j][r])
    				continue;
    			if(a[i+1]!=-1){
    				//cout<<i<<" "<<j<<" "<<r<<endl;
    				dp[i+1][min(j+a[i+1],403)][r+1]+=dp[i][j][r]*p[i+1];
    			}
    			else{
    				//cout<<i<<" "<<j<<" "<<r<<endl;
    				dp[i+1][j-1][r+1]+=dp[i][j][r]*p[i+1];
    				//cout<<i<<" "<<j<<" "<<r<<" "<<dp[i][j][r]*p[i+1]<<endl;
    			}
    			dp[i+1][j][r]+=dp[i][j][r]*(1-p[i+1]);
    		}
    	}
    }
    double sumi=0;
    f(j,201,404){
    	f(r,l,n+1){
    		if(dp[n][j][r])
    			//cout<<j<<" "<<r<<" "<<dp[n][j][r]<<endl;
    		sumi+=dp[n][j][r];
    	}
    }
   // cout<<dp[2][][1]<<endl;
    cout<<setprecision(20)<<sumi<<endl;


    
}