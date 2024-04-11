// teja349
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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

using namespace std;


//helper functions
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
ll a[21234];int dp[2009][2009];
int pushall(int i){
	dp[i+1][a[i+1]]+=dp[i][a[i+1]];
	dp[i+1][a[i+1]]%=mod;
	if(a[i+1]!=0){
		dp[i+1][a[i+1]-1]+=(1LL*(a[i+1])*dp[i][a[i+1]-1])%mod;
		dp[i+1][a[i+1]-1]%=mod;
		dp[i+1][a[i+1]-1]+=(1LL*(a[i+1])*dp[i][a[i+1]])%mod;
		dp[i+1][a[i+1]-1]%=mod;
		dp[i+1][a[i+1]]+=dp[i][a[i+1]-1];
		dp[i+1][a[i+1]]%=mod;
	}
	return 0;
	

}
int main(){
	int n,h;
	cin>>n>>h;
	int i;
	f(i,1,n+1){
		cin>>a[i];
		if(a[i]>h){
			cout<<0<<endl;
			return 0;
		}
		a[i]=h-a[i];

	}
	dp[0][0]=1;
	rep(i,n){
		pushall(i);
	}
	cout<<dp[n][0]<<endl;

}