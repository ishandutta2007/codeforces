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
ll n,l,y,x;  
ll a[123456];
map<ll,int> mapi;
int check(int val){
	int i;
	rep(i,n){
		if(mapi.find(a[i]+val)!=mapi.end()){
			return 1;
		}
	}
	return 0;
}
int check2(){
	int i;
	rep(i,n){
		if(a[i]+y<=l && mapi.find(a[i]+y-x)!=mapi.end()){
			return a[i]+y;
		}
		if(a[i]-x>=0 && mapi.find(a[i]+y-x)!=mapi.end()){
			return a[i]-x;
		}

	}
	rep(i,n){
		if(a[i]+y+x<=l && mapi.find(a[i]+y+x)!=mapi.end()){
			return a[i]+x;
		}
	}
	return -1;
}
int main(){
    std::ios::sync_with_stdio(false);
    
    cin>>n>>l>>x>>y;
    int i;
    rep(i,n){
    	cin>>a[i];
    	mapi[a[i]]++;
    }
    int val1=check(x);
    int val2=check(y);
    val1+=val2;
    if(val1==2){
    	cout<<0<<endl;
    }
    else if(val1==1){
    	if(val2==1){
    		cout<<1<<endl;
    		cout<<x<<endl;
    	}
    	else{
    		cout<<1<<endl;
    		cout<<y<<endl;
    	}
    }
    else{
    	if(check2()!=-1){
    		cout<<1<<endl;
    		cout<<check2()<<endl;
    	}
    	else{
    		cout<<2<<endl;
    		cout<<x<<" "<<y<<endl;
    	}
    }
    
}