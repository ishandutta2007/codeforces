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
ll sumseg[1212345],maxseg[1212345],haha[1234568],a[1234567];

ll build(ll node,ll s,ll e){
	if(s==e){
		sumseg[node]=a[s];
		maxseg[node]=a[s];
		return 0;
	}
	ll mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	sumseg[node]=sumseg[2*node]+sumseg[2*node+1];
	maxseg[node]=max(maxseg[2*node],maxseg[2*node+1]);
	return 0;

}
ll query(ll node,ll s,ll e,ll l,ll r){
	if(e<l || r<s)
		return 0;
	if(l<=s && e<=r)
		return sumseg[node];
	ll mid=(s+e)/2;
	return query(2*node,s,mid,l,r)+query(2*node+1,mid+1,e,l,r);
}
ll update(ll node,ll s,ll e,ll l,ll r){
	if(e<l || r<s)
		return 0;
	if(maxseg[node]<=2)
		return 0;
	if(s==e){
		sumseg[node]=haha[sumseg[node]];
		maxseg[node]=sumseg[node];
		return 0;
	}
	ll mid=(s+e)/2;
	update(2*node,s,mid,l,r);
	update(2*node+1,mid+1,e,l,r);
	sumseg[node]=sumseg[2*node]+sumseg[2*node+1];
	maxseg[node]=max(maxseg[2*node],maxseg[2*node+1]);
	return 0;

}
int main(){
    std::ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    ll i,j;
    f(i,1,1234567){
    	for(j=i;j<1234567;j+=i){
    		haha[j]++;
    	}
    }

    rep(i,n){
    	cin>>a[i];
    }
    ll l,r,t;
    build(1,0,n-1);
    //cout<<sumseg[1]<<endl;
    rep(i,m){
    	cin>>t>>l>>r;
    	l--;
    	r--;
    	if(t==1){
    		update(1,0,n-1,l,r);
    	}
    	else{
    		cout<<query(1,0,n-1,l,r)<<endl;
    	}
    }
    return 0;  
    
}