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
int dp[123456][3],n,k;
string s;
int check(int val){
	int i,value;
	rep(i,n-val+1){
		if(i==0){
			value=min(dp[i+val-1][0],dp[i+val-1][1]);
		}
		else{
			value=min(dp[i+val-1][0]-dp[i-1][0],dp[i+val-1][1]-dp[i-1][1]);
		}
		if(value<=k)
			return 1;
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
  	int i,j;
    cin>>n>>k;
    cin>>s;
    dp[0][s[0]-'a']++;
    f(i,1,n){
    	dp[i][0]=dp[i-1][0];
    	dp[i][1]=dp[i-1][1];
    	dp[i][s[i]-'a']++;
    }
    int low=0;
    int high=n;
    int mid;
    int ans=-1;
    while(low<=high){
    	mid=(low+high)/2;
    	if(check(mid)){
    		ans=mid;
    		low=mid+1;
    	}
    	else{
    		high=mid-1;
    	}
    }
    cout<<ans<<endl;
}