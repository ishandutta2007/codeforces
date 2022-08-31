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
vl vec;
map<ll,ll> mapi;
map<ll,ll>::iterator it;
int main(){
    std::ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    ll haha=0,n1=n,i;
    while(n1){
    	if(n1%2){
    		mapi[haha]++;
    	}
    	haha++;
    	n1/=2;
    }
    if(mapi.size()>k){
    	cout<<"No"<<endl;
    	return 0;
    }
    cout<<"Yes"<<endl;
    ll val,vali,left=k-mapi.size();
    while(1){
    	it=mapi.end();
    	it--;
    	val=it->ff;
    	vali=it->ss;
    	if((vali)<=left){
    		mapi.erase(it);
    		mapi[val-1]+=2*vali;
    		left-=vali;
    	}
    	else{
    		break;
    	}
    }
    while(1){
    	it=mapi.begin();
    	val=it->ff;
    	vali=it->ss;
    	if(left==0)
    		break;
    	left--;
    	mapi[val]--;
    	mapi[val-1]=2;
    }
    for(it=mapi.begin();it!=mapi.end();it++){
    	rep(i,it->ss){
    		vec.pb(it->ff);
    	}
    }
    fd(i,vec.size()-1,0){
    	cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;  
    
}