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
int dp[5009][5009];
ll ans[10000];
int main(){
    std::ios::sync_with_stdio(false);
    int i,j;
    string s;
    cin>>s;
    int n=s.length();
    rep(i,n){
    	dp[i][i]=1;
    	ans[1]++;

    }
    rep(i,n-1){
    	if(s[i]==s[i+1]){
    		dp[i][i+1]=2;
    		ans[2]++;
    	}
    }
    int lol;
    f(i,2,n){
    	rep(j,n-i){
    		lol=(i+1)/2;
    		if(dp[j+1][j+i-1] && s[j]==s[j+i]){
    			dp[j][j+i]=1+min(dp[j][j+lol-1],dp[j+i-lol+1][j+i]);
    			ans[dp[j][j+i]]++;
    		}
    	}
    }
    //cout<<dp[0][3]<<endl;
    fd(i,n+2,0){
    	ans[i]+=ans[i+1];
    }
    f(i,1,n+1){
    	cout<<ans[i]<<" ";
    }


    



    return 0;      

}