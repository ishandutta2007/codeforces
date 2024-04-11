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
string s[12];
int a[123][123];
int dp[123][2][2];
int main(){
    std::ios::sync_with_stdio(false);
    cin>>s[0]>>s[1];
    int i,j,k;
    int n=s[0].length();
    rep(i,2){
    	rep(j,s[i].length()){
    		if(s[i][j]=='0'){
    			a[j][i]=0;
    		}
    		else{
    			a[j][i]=1;
    		}
    	}
    }
    
    rep(i,2){
    	rep(j,2){
    		dp[0][i][j]=-inf;
    	}
    }
    dp[0][a[0][0]][a[0][1]]=0;
    f(i,1,n){
    	rep(j,2){
    		rep(k,2){
    			if(j==0)
    				dp[i-1][j+1][k]=max(dp[i-1][j][k],dp[i-1][j+1][k]);
    			if(k==0)
    				dp[i-1][j][k+1]=max(dp[i-1][j][k],dp[i-1][j][k+1]);
    			if(j==0 && k==0)
    				dp[i-1][j+1][k+1]=max(dp[i-1][j][k],dp[i-1][j+1][k+1]);
    		}
    	}

    	if(a[i][0]==0 && a[i][1]==0){
    		dp[i][0][1]=dp[i-1][0][0]+1;
    		dp[i][1][0]=dp[i-1][0][0]+1;
    		dp[i][0][0]=dp[i-1][1][1];
    		dp[i][1][1]=max(dp[i-1][1][0],dp[i-1][0][1])+1;
    		//cout<<"dsad"<<endl;
    	}
    	else if(a[i][0]==0){
    		dp[i][0][1]=dp[i-1][1][1];
    		dp[i][1][0]=-inf;
    		dp[i][0][0]=-inf;
    		dp[i][1][1]=dp[i-1][0][0]+1;	
    	}
    	else if(a[i][1]==0){
			dp[i][1][0]=dp[i-1][1][1];
    		dp[i][0][1]=-inf;
    		dp[i][0][0]=-inf;
    		dp[i][1][1]=dp[i-1][0][0]+1;	

    	}
    	else{
    		dp[i][1][1]=dp[i-1][1][1];
    		dp[i][0][0]=-inf;
    		dp[i][0][1]=-inf;
    		dp[i][1][0]=-inf;

    	}
    }
    //return 0;
    rep(j,2){
    		rep(k,2){
    			if(j==0)
    				dp[i-1][j+1][k]=max(dp[i-1][j][k],dp[i-1][j+1][k]);
    			if(k==0)
    				dp[i-1][j][k+1]=max(dp[i-1][j][k],dp[i-1][j][k+1]);
    			if(j==0 && k==0)
    				dp[i-1][j+1][k+1]=max(dp[i-1][j][k],dp[i-1][j+1][k+1]);
    		}
    	}

    cout<<dp[n-1][1][1]<<endl;


    return 0;  
    
}