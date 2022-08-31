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
ll getpow(ll val){
	ll ans=1,haha=2;
	while(val>0){
		if(val%2){
			ans*=haha;
			ans%=mod;
		}
		haha*=haha;
		haha%=mod;
		val/=2;
	}
	return ans;
}
set<int> seti;
vl vec;
map<int,ll> mapi;
int main(){
    std::ios::sync_with_stdio(false);
    ll x,y;
    cin>>x>>y;
    if(y%x!=0){
    	cout<<0<<endl;
    	return 0;
    }
    y/=x;
    ll i,j;
    for(i=1;i*i<=y;i++){
    	if(y%i==0){
    		seti.insert(i);
    		seti.insert(y/i);
    	}
    }
    set<int>::iterator it;
    for(it=seti.begin();it!=seti.end();it++){
    	vec.pb(*it);
    }
    ll ans;
    rep(i,vec.size()){
    	ans=getpow(vec[i]-1);
    	rep(j,i+1){
    		if(vec[i]%vec[j]==0){
    			ans-=mapi[vec[j]];
    			
    		}
    	}
    	ans%=mod;
    	ans+=mod;
    	ans%=mod;
    	mapi[vec[i]]=ans;
    	//cout<<vec[i]<<" "<<ans<<endl;
    }
    cout<<mapi[y]<<endl;

    return 0;  
    
}