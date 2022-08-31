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
ll check(ll val1,ll val2){
	ll st=val2/(val1+1);
	ll en=val2/val1;
	st++;
	if(st<=en)
		return st;
	return -1;
}
map<ll,ll> mapi;
int main(){
    std::ios::sync_with_stdio(false);
    ll t;
    cin>>t;
    ll i;
    rep(i,123456){
    	mapi[i*i]=i;
    }
    ll j;
    rep(j,t){
    	ll val,haha,ans,flag=0;
    	cin>>val;
    	f(i,1,123456){
    		haha=i*i-val;
    		if(haha<=0)
    			continue;
    		if(mapi.find(haha)!=mapi.end()){
    			haha=mapi[haha];
    			ans=check(haha,i);
    			if(ans!=-1){
    				flag=1;
    				cout<<i<<" "<<ans<<endl; 
    				break;
    			}
    		}
    	}
    	if(flag==0){
    		cout<<-1<<endl;
    	}
    }
    return 0;  
    
}