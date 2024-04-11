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

ll dsu[512345];
ll u[512345],v[512345];
ll par(ll cu){

	if(dsu[cu]<0)
		return cu;
	dsu[cu]=par(dsu[cu]);
	return dsu[cu];
}
ll haha;
ll merge(ll edg){
	ll l=u[edg];
	ll r=v[edg];
	l=par(l);
	r=par(r);
	//cout<<l<<" "<<r<<endl;
	if(l==r){
		return 0;
	}
	if(dsu[l]>dsu[r]){
		swap(l,r);
	}
	dsu[l]+=dsu[r];
	dsu[r]=l;
	haha--;
	return 0;
}
ll c[512345];
vector<vl> vec(512345);
ll two[512345];
map<ll,ll> mapi;
map<ll,ll>::iterator it;
int main(){
    std::ios::sync_with_stdio(false);
    ll n,m,k;
    cin>>n>>m>>k;
    ll i;
    rep(i,n){
    	cin>>c[i];
    }

    rep(i,m){
    	cin>>u[i]>>v[i];
    	u[i]--;
    	v[i]--;
    	mapi[(c[u[i]]^c[v[i]])]=1;
    }
    ll ans,val,total=0,j;
    two[0]=1;
    dsu[0]=-1;
    f(i,1,n+10){
    	two[i]=two[i-1]*2;
    	two[i]%=mod;
    	dsu[i]=-1;
    }
    ans=two[k];
    val=mapi.size();
    ans-=val;
    
    //cout<<ans<<endl;
    ans%=mod;
    ans*=two[n];
    ans%=mod;
    total+=ans;
    ll counter=0;
    for(it=mapi.begin();it!=mapi.end();it++){
    	it->ss=counter++;
    }
    rep(i,m){
    	vec[mapi[(c[u[i]]^c[v[i]])]].pb(i);
    }
  
    //cout<<total<<endl;
    //return 0;
    haha=n;
    ll edg;
    rep(i,counter){
    	haha=n;
    	rep(j,vec[i].size()){
    		merge(vec[i][j]);
    	}
    	total+=two[haha];
    	total%=mod;
    	rep(j,vec[i].size()){
    		edg=vec[i][j];
    		dsu[u[edg]]=-1;
    		dsu[v[edg]]=-1;
    	}
    }
    total%=mod;
    total+=mod;
    total%=mod;
    cout<<total<<endl;
    return 0;   
}