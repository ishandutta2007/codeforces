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
ll compute(ll val){
	ll ans=0;
	val++;
	if(val%4==0 || val%4==1){
		ans=0;
	}
	else{
		ans=1;
	}
	
	ll haha=2,lol;
	while(1){
		lol=val/haha;
		if(lol==0){
			break;
		}
		if(lol%2){
			if(val%2){
				ans|=haha;
			}
		}
		haha*=2;	
	}
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n,i;
    cin>>n;
    //cout<<compute(n)<<endl;
    //return 0;
    ll lol=0,a,b;
    rep(i,n){
    	cin>>a>>b;
    	//ll a,b;
    	lol^=compute(a-1);
    	lol^=compute(a+b-1);
    }
    if(lol){
    	cout<<"tolik"<<endl;
    }
    else{
    	cout<<"bolik"<<endl;
    }
    return 0;
}