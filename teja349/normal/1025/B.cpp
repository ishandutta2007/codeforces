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
ll aa[212345],bb[212345];
int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll i;
    ll a,b,gg;
    rep(i,n){
    	cin>>aa[i]>>bb[i];
    	a=aa[i]*bb[i];
    	if(i==0)
    		gg=a;
    	else
    		gg=__gcd(gg,a);
    }
    if(gg==1){
    	cout<<-1<<endl;
    	return 0;
    }
    for(i=2;i<123456;i++){
    	if(gg%i==0){
    		cout<<i<<endl;
    		return 0;
    	}
    }
    a=__gcd(aa[0],gg);
    if(a!=1){
    	cout<<a<<endl;
    }
    else{
    	b=__gcd(bb[0],gg);
    	cout<<b<<endl;
    }

    return 0;  
    
}