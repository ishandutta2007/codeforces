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
ll dp[1234],l,c[1234]; 
ll compute(ll val){
	if(val==-1){
		return 0;
	}
	if(dp[val]>0)
		return dp[val];
	if(l&(1<<val))
		dp[val]=min(c[val+1],c[val]+compute(val-1));
	else{
		dp[val]=compute(val-1);
	}
	return dp[val];
}
int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n>>l;
    ll i,iinf;
    iinf=inf;
    iinf*=inf;
    rep(i,n){
    	cin>>c[i];
    }
    f(i,n,100){
    	c[i]=iinf;
    }
    f(i,1,31){
    	c[i]=min(c[i],2*c[i-1]);
    }
    fd(i,29,0){
    	c[i]=min(c[i+1],c[i]);
    }
    //return 0;
    ll val=0;
    ll l1=l;
    while(l1>0){
    	val++;
    	l1/=2;
    }
    val--;
    //return 0;
    cout<<compute(val)<<endl;

    return 0;  
    
}