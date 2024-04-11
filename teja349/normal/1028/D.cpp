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


set<ll> buy,sell,doubt;
set<ll>::iterator it;
map<ll,ll> revmap;
ll amt[412345],offer[412345];
ll fix[412345];
int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll i;
    string str;
    rep(i,n){
    	cin>>str;
    	cin>>amt[i];
    	if(str[1]=='D'){
    		offer[i]=0;
    		revmap[amt[i]]=i;
    	}
    	else{
    		offer[i]=1;
    	}
    }
    ll val;
    ll ans=1;
    ll haha;
    rep(i,n){
    	if(!offer[i]){
    		if(!sell.empty()){
    			val=*(sell.begin());
    			if(val<amt[i]){
    				fix[i]=2;
    				sell.insert(amt[i]);
    			}
    		}
    		if(!buy.empty()){
    			it=buy.end();
    			it--;
    			val=*(it);
    			if(val>amt[i]){
    				fix[i]=1;
    				buy.insert(amt[i]);
    			}
    		}
    		if(fix[i]==0){
    			doubt.insert(amt[i]);
    		}
    	}
    	else{
    		if(fix[revmap[amt[i]]]==1){
    			it=buy.end();
    			it--;
    			if(*it!=amt[i]){
    				cout<<0<<endl;
    				return 0;
    			}
    			buy.erase(amt[i]);
    		}
    		if(fix[revmap[amt[i]]]==2){
    			it=sell.begin();
    			if(*it!=amt[i]){
    				cout<<0<<endl;
    				return 0;
    			}
    			sell.erase(amt[i]);
    		}
    		if(fix[revmap[amt[i]]]==0){
    			ans*=2;
    			ans%=mod;
    			
    		}
    		for(it=doubt.begin();it!=doubt.end();it++){
				val=*it;
				if(val==amt[i]){
					continue;
				}
				if(val<amt[i]){
					buy.insert(val);
					fix[revmap[val]]=1;
				}
				else{
					sell.insert(val);
					fix[revmap[val]]=2;
				}
			}
			doubt.clear();
    	}
    }
    haha=doubt.size();
    ans*=(haha+1);
    ans%=mod;
    cout<<ans<<endl;
    return 0;   
}