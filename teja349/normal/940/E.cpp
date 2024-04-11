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
multiset<ll> seti;
//std::ios::sync_with_stdio(false);   
ll dp[123456],pre[123456],a[123456];
int main(){
    std::ios::sync_with_stdio(false);
    ll n,c;
    cin>>n>>c;
    ll i,j,val;
    f(i,1,n+1){
    	cin>>a[i];
    	pre[i]=pre[i-1]+a[i];
    }
    if(c>n){
    	cout<<pre[n]<<endl;
    	return 0;
    }
    seti.insert(a[0]);
    f(i,1,c){
    	dp[i]=dp[i-1]+a[i];
    	seti.insert(a[i]);
    	//seti.insert(a[i]);
    	
    }
    //cout<<dp[c-1]<<endl;
    f(i,c,n+1){
    	seti.erase(seti.find(a[i-c]));
    	seti.insert(a[i]);
    	val=*(seti.begin());
    	dp[i]=dp[i-1]+a[i];
    	dp[i]=min(dp[i],pre[i]-pre[i-c]-val+dp[i-c]);

    }
    cout<<dp[n]<<endl;
    return 0;  
    
}