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
ll dp[123456];
vl vec;
ll sumi=0;
int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    dp[1]=1;
    dp[2]=2;
    //dp[3]=4;
    //dp[4]=8;
    ll i,j,lol;
    f(i,3,123456){
    	if(i%2){
    		dp[i]=(i-1)*(i-1)/2;
    		dp[i]+=(i-3)/2+2;
    	}
    	else{
    		dp[i]=(i-2)+2+(i-2)*(i/2);
    	}

    }
    f(i,1,123453){
    	if(dp[i]<=n && dp[i+1]>n){
    		break;
    	}
    }
    lol=i;
    int m;
    ll val;
    cin>>m;
    rep(i,m){
    	cin>>val;
    	cin>>val;
    	vec.pb(val);
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    rep(i,min(lol,(ll)vec.size())){
    	sumi+=vec[i];
    }
    cout<<sumi<<endl;
    //cout<<dp[3]<<endl;
    
}