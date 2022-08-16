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
ll cnt[12345];
int main(){
    std::ios::sync_with_stdio(false);
    ll n,ans=0,wow=0;
    cin>>n;
    string s,t;
    cin>>s>>t;
    ll i;
    ll j=n;
    rep(i,n){
    	wow+=j*j;
    	j--;
    }
    ll iinf = inf;
    iinf*=inf;
    long double total=0;
    rep(i,s.length()){
    	cnt[s[i]]+=i+1;
    	ans+=(n-i)*cnt[t[i]];
    	if(ans>iinf){
    		total+=ans*1.00/wow;
    		ans=0;
    	}
    }

    rep(i,1000){
    	cnt[i]=0;
    }
    rep(i,s.length()){
    	ans+=(n-i)*cnt[s[i]];
    	cnt[t[i]]+=i+1;
    	if(ans>iinf){
    		total+=ans*1.00/wow;
    		ans=0;
    	}

    }
    total+=ans*1.00/wow;
    cout<<setprecision(30)<<total<<endl;
    return 0;   
}