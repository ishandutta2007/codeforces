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
ll powe(ll a,ll b){
	ll ans=1;
	while(b){
		if(b%2){
			ans*=a;
			ans%=mod;
		}
		a*=a;
		b/=2;
		a%=mod;
	}
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    ll x,k;
    cin>>x>>k;
    if(x==0){
    	cout<<0<<endl;
    	return 0;
    }
    ll val,val1,val2;
    val=powe(2,k);
    val1=val-1;
    val2=val*2;
    val2%=mod;
    x%=mod;
    val2*=x;
    val2%=mod;
    val2-=val1;
    val2%=mod;
    val2+=mod;
    val2%=mod;
    cout<<val2<<endl;
    return 0;  
    
}