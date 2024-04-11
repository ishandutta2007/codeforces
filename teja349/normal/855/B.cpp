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
ll haha[123456],lol[123456];
ll a[123456];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    ll p,q,r;
    cin>>p>>q>>r;
    int i;
    rep(i,n){
    	cin>>a[i];	
    	lol[i]=a[i]*r;
    }
    fd(i,n-2,0){
    	lol[i]=max(lol[i+1],lol[i]);
    }
    rep(i,n){
    	haha[i]=a[i]*q;
    }
    haha[n-1]+=lol[n-1];
    fd(i,n-2,0){
    	haha[i]=max(haha[i]+lol[i],haha[i+1]);
    }
    fd(i,n-1,0){
    	lol[i]=haha[i];
    	haha[i]=p*a[i];
    }
    haha[n-1]+=lol[n-1];
    fd(i,n-2,0){
    	haha[i]=max(haha[i]+lol[i],haha[i+1]);
    }
    cout<<haha[0]<<endl;
    return 0;


    return 0;  
    
}