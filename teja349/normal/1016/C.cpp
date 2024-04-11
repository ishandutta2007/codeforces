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
ll a[2][312345],ans[3][312345],pre[312345];
int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll i;
    rep(i,n){
    	cin>>a[0][i];
    }
    rep(i,n){
    	cin>>a[1][i];
    }
    ans[0][n-1]=a[1][n-1];
    ans[1][n-1]=a[0][n-1];
    pre[n-1]=a[1][n-1]+a[0][n-1];
    fd(i,n-2,0){
    	ans[0][i]=ans[0][i+1]+pre[i+1]+a[1][i]*(2*(n-1-i)+1);
    	ans[1][i]=ans[1][i+1]+pre[i+1]+a[0][i]*(2*(n-1-i)+1);
    	pre[i]=pre[i+1]+a[0][i]+a[1][i];
    }
    ll maxi,sofar,adder;
    maxi=0;
    sofar=0;
    adder=0;
    rep(i,n){
    	maxi=max(sofar+adder*pre[i]+ans[i%2][i],maxi);
    	sofar+=a[i%2][i]*2*i + a[(i+1)%2][i]*(2*i+1);
    	adder+=2;
    }
    cout<<maxi<<endl;


    return 0;  
    
}