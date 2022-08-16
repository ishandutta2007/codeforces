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
vll vec;
ll a[212345];
ll k;
ll calc(ll s,ll p,ll pos){
	ll i;
	ll iinf=inf;
	iinf*=inf;
	ll val;
	ll cnt=0;
	//cout<<s<<" "<<p<<endl;
	f(i,pos,vec.size()){
		if(vec[i].ss==1){
			if(iinf/p<vec[i].ff){
				return cnt;
			}
			p*=vec[i].ff;
			s+=vec[i].ff;
			if(p%s==0 && p/s==k){
				cnt++;
			}
		}
		else{
			val=p-k*s;
			if(val>0 && val%k==0 && val/k<=vec[i].ss){
				cnt++;
			}
			s+=vec[i].ss;
		}
	}
	return cnt;
}
int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n>>k;
    ll i;
    rep(i,n){
    	cin>>a[i];
    }
    i=0;
    ll finale=0;
    ll cnt=0;
    while(i<n){
    	if(a[i]==1){
    		cnt++;
    		
    	}
    	if(a[i]!=1){
    		if(cnt!=0){
    			vec.pb(mp(1,cnt));
    			cnt=0;

    		}
    		vec.pb(mp(a[i],1));
    	}
    	i++;
    }
    if(cnt){
    	vec.pb(mp(1,cnt));
    }
    ll j;
    rep(i,vec.size()){
    	if(vec[i].ff!=1){

    		finale+=calc(vec[i].ff,vec[i].ff,i+1);
    	}
    	else{
    		rep(j,vec[i].ss){
    			finale+=calc(vec[i].ss-j,1,i+1);
    		}
    	}

    }
    if(k==1){
    	finale+=n;
    }
    cout<<finale<<endl;

    return 0;  
    
}