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
int dp[10][2000];
int a[10][100];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j,val,val1,val2;
    rep(i,n){
    	rep(j,6){
    		cin>>val;
    		a[i][val]=1;
    	}
    }
    rep(i,10){
    	rep(j,n){
    		if(a[j][i]==1){
    			dp[(1<<j)][i]=1;
    		}
    	}
    }
    f(i,10,100){
    	val1=i/10;
    	val2=i%10;
    	if(dp[1][val1] && dp[2][val2])
    		dp[3][i]=1;
    	if(dp[1][val2] && dp[2][val1])
    		dp[3][i]=1;

    	if(dp[1][val1] && dp[4][val2])
    		dp[5][i]=1;
    	if(dp[1][val2] && dp[4][val1])
    		dp[5][i]=1;

    	if(dp[4][val1] && dp[2][val2])
    		dp[6][i]=1;
    	if(dp[4][val2] && dp[2][val1])
    		dp[6][i]=1;
    }
    f(i,100,1000){
        val1=i/10;
    	val2=i%10;
    	if(dp[5][val1] && dp[2][val2])
    		dp[7][i]=1;
        
        if(dp[6][val1] && dp[1][val2])
    		dp[7][i]=1;
    	
    	if(dp[3][val1] && dp[4][val2])
    		dp[7][i]=1;
    }
    int flag;
    f(i,1,1000){
    	flag=0;
    	f(j,1,8){
    		if(dp[j][i]){
    			flag=1;
    		}
    	}
    	if(!flag){
    		cout<<i-1<<endl;
    		return 0;
    	}
    }

    return 0;  
    
}