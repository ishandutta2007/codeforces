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
vll vec;
set<ll> seti;
ll c[312345],ans[312345];
int main(){
    std::ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    ll i;
    rep(i,n){
    	cin>>c[i];
    	vec.pb(mp(c[i],i+1));
    }
    set<ll>::iterator it;
    f(i,k+1,k+n+1){
    	seti.insert(i);
    }
    ll val,cost=0;
    sort(vec.begin(),vec.end());
    fd(i,vec.size()-1,0){
    	val=vec[i].ss;
    	it=seti.lower_bound(val);
    	ans[val]=*it;
    	cost+=(*it-val)*vec[i].ff;
    	seti.erase(*it);
    }
    cout<<cost<<endl;
    f(i,1,n+1){
    	cout<<ans[i]<<" ";
    }
    return 0;  
    
}