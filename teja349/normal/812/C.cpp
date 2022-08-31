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
ll n,s;
ll a[123456];  
ll check(ll val){
	ll i;
	vl vec;
	vec.clear();
	ll sumi=0;
	f(i,1,n+1){
		vec.pb(a[i]+i*val);
	}
	sort(vec.begin(),vec.end());
	rep(i,val){
		sumi+=vec[i];
	}
	if(sumi<=s){
		return sumi;
	}
	return -1;
}
int main(){
    std::ios::sync_with_stdio(false);
    
    cin>>n>>s;
    ll i;
    f(i,1,n+1){
    	cin>>a[i];
    }
    ll low=0;
    ll high=n,mid;
    ll ans=0;
    ll valed=0,val;
    //cout<<check(3)<<endl;
    while(low<=high){
    	mid=(high+low)/2;
    	val=check(mid);
    	if(val!=-1){
    		ans=mid;
    		valed=val;
    		low=mid+1;
    	}
    	else{
    		high=mid-1;
    	}

    }
    cout<<ans<<" "<<valed<<endl;

}