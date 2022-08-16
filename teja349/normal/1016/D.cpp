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
ll a[1234],b[1234],lol[123][123];
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i;
    ll haha=0;
    int j;
    rep(i,n){
    	cin>>a[i];
    	haha^=a[i];
    }
    rep(i,m){
    	cin>>b[i];
    	haha^=b[i];
    }
    if(haha!=0){
    	cout<<"NO"<<endl;
    	return 0;
    }
    cout<<"YES"<<endl;
    rep(i,n-1){
    	rep(j,m-1){
    		lol[i][j]=0;
    	}
    	lol[i][m-1]=a[i];
    }
    haha=a[n-1];
    rep(j,m-1){
    	lol[n-1][j]=b[j];
    	haha^=b[j];
    }
    lol[n-1][m-1]=haha;
    rep(i,n){
    	rep(j,m){
    		cout<<lol[i][j]<<" ";
    	}
    	cout<<endl;
    }

    return 0;  
    
}