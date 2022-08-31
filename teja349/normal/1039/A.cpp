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
#define inf (1000*1000*1000)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
ll bit[212345];
ll update(ll pos,ll val){
	pos++;
	while(pos<212345){
		bit[pos]+=val;
		pos+=pos&(-pos);
	}
	return 0;
}
ll query(ll pos){
	ll ans=0;
	pos++;
	while(pos>0){
		ans+=bit[pos];
		pos-=pos&(-pos);
	}
	return ans;
}
ll a[212345],bmin[212345],bmax[212345],b[212345];
ll x[212345];
int main(){
    std::ios::sync_with_stdio(false);
    ll n,t;
    cin>>n>>t;
    ll iinf=inf;
    iinf*=inf;
    iinf*=3;
    ll i;
    rep(i,n){
    	cin>>a[i];
    }
    rep(i,n){
    	cin>>x[i];
    	x[i]--;
    }
    rep(i,n){
    	bmin[i]=a[i]+t;
    	bmax[i]=iinf;
    }
    rep(i,n){
    	//cout<<query(i)<<endl;
    	if(query(i)){
    		bmin[i-1]=a[i]+t;
    	}
    	if(x[i]<i){
    		cout<<"No"<<endl;
    		return 0;
    	}
    	if(x[i]>=i){
    		if(x[i]!=n-1)
    			bmax[x[i]]=min(bmax[x[i]],a[x[i]+1]+t-1);
    		update(i+1,1);
    		update(x[i]+1,-1);
    	}
    	

    }
    ll counter=1;
    rep(i,n){
    	counter=max(counter,bmin[i]);
    	if(counter>bmax[i]){
    		cout<<"No"<<endl;
    		return 0;
    	}
    	else{
    		b[i]=counter;
    		counter++;
    	}
    }
    cout<<"Yes"<<endl;
    rep(i,n){
    	cout<<b[i]<<" ";
    }

    return 0;   
}