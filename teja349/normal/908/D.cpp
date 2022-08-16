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
ll extend_gcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll x1,y1;
	ll ans =extend_gcd(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;

	return ans;
}

ll k,expect;
ll check(ll i,ll j){
	if(j+i>=k){
		return j+i+expect;
	}
	return 0;
}
ll ans[2223456],prob[2234567],indeg[2234567];
vector<vi> adj(2234567);
int main(){
    std::ios::sync_with_stdio(false);
    ll a,b,i,j;
    cin>>k>>a>>b;
    ll x,y;
    ll tot=extend_gcd(mod,a+b,x,y);
    tot=y;
    tot%=mod;
    tot+=mod;
    tot%=mod;
    //cout<<tot<<"sas"<<endl;
    expect=extend_gcd(mod,b,x,y);
    expect=y;
    expect%=mod;
    expect+=mod;
    expect%=mod;
    expect*=(a+b);
    expect%=mod;
    expect--;
    expect+=mod;
    expect%=mod;
    a*=tot;
    a%=mod;
    b*=tot;
    b%=mod;
    ll val;
    prob[1001]=1;
    f(i,1,1001){
    	rep(j,1001){
    		val=check(i,j);
    		if(val){
    			ans[i*1001+j]=val;
    			continue;
    		}
    		adj[i*1001+j].pb((i+1)*1001+j);
    		adj[i*1001+j].pb(i*1001+j+i);
    		indeg[i*1001+j+i]++;
    		indeg[(i+1)*1001+j]++;
    	}
    }
    stack<ll> st;
    ll wow=0;
    st.push(1001);
    while(!st.empty()){
    	val=st.top();
    	st.pop();
    	if(ans[val]){
    		wow+=prob[val]*ans[val];
    		wow%=mod;
    		continue;
    	}
    	prob[adj[val][0]]+=prob[val]*a;
    	prob[adj[val][0]]%=mod;
    	prob[adj[val][1]]+=prob[val]*b;
    	prob[adj[val][1]]%=mod;
    	indeg[adj[val][0]]--;
    	if(!indeg[adj[val][0]]){
    		st.push(adj[val][0]);
    	}
    	indeg[adj[val][1]]--;
    	if(!indeg[adj[val][1]]){
    		st.push(adj[val][1]);
    	}
    }

    cout<<wow<<endl;
    return 0;  
    
}