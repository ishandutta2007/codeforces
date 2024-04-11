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
int dp[123456][4];
int main(){
    std::ios::sync_with_stdio(false);
    int i;
    string s;
    cin>>s;
    int n=s.length();
    i=0;
    if(s[0]=='a'){
    	dp[i][0]=0;
    	dp[i][1]=1;
    	dp[i][2]=0;	
    }
    else{
    	dp[i][0]=1;
    	dp[i][1]=0;
    	dp[i][2]=1;	
    }
    
    f(i,1,s.length()){
    	//cout<<i<<endl;

    	if(s[i]=='a'){
    		dp[i][0]=dp[i-1][0];
    		dp[i][1]=min(dp[i-1][0]+1,dp[i-1][1]+1);
    		dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
    		dp[i][2]=min(dp[i-1][2],dp[i][2]);

    	}
    	else{
    		dp[i][0]=dp[i-1][0]+1;
    		dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
    		dp[i][2]=min(dp[i-1][0]+1,dp[i-1][1]+1);
    		dp[i][2]=min(dp[i-1][2]+1,dp[i][2]);
    	}

    }

    cout<<n-min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2])<<endl;

    return 0;  
    
}