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
vl vec,vec1;
ll iinf;
ll remov(ll val){
	ll i;
	vec1.clear();
	rep(i,vec.size()){
		if(val%vec[i]==0){
			
			val/=vec[i];
		}
		else{
			vec1.pb(vec[i]);
		}

	}
	vec.clear();
	rep(i,vec1.size()){
		vec.pb(vec1[i]);
	}
}
//int flag=0;
ll compute(ll x,ll y){
	if(y==0){
		return 0;
	}
	
	ll i;
	ll val=__gcd(x,y);
	remov(val);
	y/=val;
	x/=val;
	y--;
	ll mini=iinf;
	if(x==1){
		return y+1;
	}
	rep(i,vec.size()){
		if(y%vec[i]<mini){
			//cout<<"DAd";
			mini=y%vec[i];
		}
	}
	//cout<<mini<<" "<<x<<" "<<0%3<<endl;
	//return 0;
	return mini+1+compute(x,y-mini);

}
int main(){
    std::ios::sync_with_stdio(false);
    ll x,y;
    cin>>x>>y;
    iinf=inf;
    iinf*=inf;
    ll i,val;
    val=x;
    for(i=2;i*i<=val;i++){
    	while(val%i==0){
    		vec.pb(i);
    		val/=i;
    	}

    }
    if(val!=1){
    	vec.pb(val);
    }
    cout<<compute(x,y)<<endl;
    //cout<<"das";
    return 0;      

}