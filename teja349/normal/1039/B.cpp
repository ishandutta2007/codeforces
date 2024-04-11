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

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

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

ll check(ll l,ll r){
	cout<<l<<" "<<r<<endl;
	string s;
	cin>>s;
	if(s[0]=='Y'){
		if(l==r){
			exit(0);
		}

		return 1;
	}
	else{
		return 0;
	}
}
int main(){
    std::ios::sync_with_stdio(false);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    //cout<<rng()<<endl;
    //return 0;
    ll n,k;
    cin>>n>>k;
    ll low=1;
    ll high=n;
    ll mid,val;
    ll len;
    while(1){
    	mid=(high+low)/2;
    	 val=check(low,mid);
    	if(val){
    		low=low-10;
    		high=mid+10;
    		low=max(low,1LL);
    		high=min(high,n);

    	}
    	else{
    		low=mid-10;
    		high=high+10;
    		low=max(low,1LL);
    		high=min(high,n);
    	}
    	if(high-low<60){
    		len=high-low+1;
    		len=rng()%len;
    		len+=low;
    		check(len,len);
    		low-=10;
    		high+=10;
    		low=max(low,1LL);
    		high=min(high,n);
    	}
    }

    return 0;   
}