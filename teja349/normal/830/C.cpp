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
set<ll> seti;
ll n,k;
ll maxi=1;
ll a[1234];
int precomp(ll val){
	ll i;
	for(i=1;i*i<=val;i++){
		seti.insert(i);
	}
	double val1=val;
	val1*=1.00;
	i--;
	ll haha=ceil(val1/i);
	fd(i,haha,1){
		seti.insert(ceil(val*1.000/i));
	}
	return 0;
	
}
int calc(ll p,ll q){
	ll i;ll sumi=0;
	rep(i,n){
		sumi+=a[i]/p;
		if(a[i]%p)
			sumi++;
	}
	ll dlim=k/sumi;
	ll vald=min(dlim,q);
	if(vald<p)
		return 0;
	maxi=max(vald,maxi);
	return 0;

}
int main(){
    //std::ios::sync_with_stdio(false);
	vl vec;
	cin>>n>>k;
	ll i;
	rep(i,n){
		cin>>a[i];
		precomp(a[i]);
		k+=a[i];
	}
	ll iinf=inf;
	iinf*=100000;
	seti.insert(iinf);
	set<ll>::iterator it;
	for(it=seti.begin();it!=seti.end();it++){
		vec.pb(*it);
	}
	fd(i,vec.size()-2,0){
		calc(vec[i],vec[i+1]-1);
	}
	cout<<maxi<<endl;
    
}