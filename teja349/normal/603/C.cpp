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
int dp[100];
int compute(int val){
	if(val<8){
		return dp[val];
	}
	if(val%2){
		return 0;
	}
	val=compute(val/2);
	if(val==1){
		return 2;
	}
	else{
		return 1;
	}
}
int a[123456];
int main(){
    std::ios::sync_with_stdio(false);
    int n,k,i;
    cin>>n>>k;
    rep(i,n){
    	cin>>a[i];
    }
    k%=2;
    ll ans=0;
    if(k==0){
    	dp[0]=0;
    	dp[1]=1;
    	dp[2]=2;
    	dp[3]=0;
    	
    	rep(i,n){
    		if(a[i]>3){
    			if(a[i]%2==0){
    				ans^=1;
    			}
    		}
    		else{
    			ans^=dp[a[i]];
    		}
    	}
    }
    else{
    	dp[0]=0;
    	dp[1]=1;
    	dp[2]=0;
    	dp[3]=1;
    	dp[4]=2;
    	dp[5]=0;
    	dp[6]=2;
    	dp[7]=0;
    	rep(i,n){
    		ans^=compute(a[i]);
    		
    	}
    }
    if(ans){
    	cout<<"Kevin"<<endl;
    }
    else
    	cout<<"Nicky"<<endl;

}