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
int dp[123456][2][2];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    ll ans=0;
    int i,k,j;
    fd(i,n-1,0){
    	if(a[i]=='0' && b[i]=='0'){
    		ans+=dp[i+1][1][0]+dp[i+1][1][1];
    	}
    	else if(a[i]=='0' && b[i]=='1'){
    		ans+=dp[i+1][1][0];
    	}
    	else if(a[i]=='1' && b[i]=='0'){
    		ans+=dp[i+1][0][0]+dp[i+1][0][1];
    	}
    	else{
    		ans+=dp[i+1][0][0];
    	}
    	dp[i][a[i]-'0'][b[i]-'0']++;
    	rep(j,2){
    		rep(k,2){
    			dp[i][j][k]+=dp[i+1][j][k];
    		}
    	}

    }
    cout<<ans<<endl;

    return 0;     
}