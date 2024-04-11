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
int compute(int val){
	int ans=1;
	while(val>0){
		if(val%10)
			ans*=(val%10);
		val/=10;
	}
	return ans;
}
int dp[1234567];
int ans[10][1234567];
int main(){
    std::ios::sync_with_stdio(false);
    int i;
    rep(i,10){
    	dp[i]=i;
    	ans[dp[i]][i]=1;
    }
    int j,l,r,k;
    f(i,10,1234567){
    	dp[i]=dp[compute(i)];
    	ans[dp[i]][i]=1;
    }
    rep(i,10){
    	f(j,1,1234567){
    		ans[i][j]+=ans[i][j-1];
    	}
    }
    int q;
    cin>>q;
    rep(i,q){
    	cin>>l>>r>>k;
    	cout<<ans[k][r]-ans[k][l-1]<<endl;
    	
    }
    return 0;  
    
}