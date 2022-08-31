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
vl vec1,vec2,seti;
int main(){
    std::ios::sync_with_stdio(false);
    ll x,y,l,r;
    cin>>x>>y>>l>>r;
    ll iinf=inf;
    iinf*=inf;
    ll res=1;
    ll i,j;
    while(1){
    	vec1.pb(res);
    	if(iinf/x <res)
    		break;
    	res*=x;
    }
    res=1;
    while(1){
    	vec2.pb(res);
    	if(iinf/y <res)
    		break;
    	res*=y;
    }
    rep(i,vec1.size()){
    	rep(j,vec2.size()){  

    		seti.pb(vec1[i]+vec2[j]);
    	}
    }
    seti.pb(l-1);
    seti.pb(r+1);
    sort(seti.begin(),seti.end());
    rep(i,seti.size()){
    	if(seti[i]==l-1){
    		break;
    	}
    }
    ll maxi=1;
    f(j,i,seti.size()){
    	if(seti[j]==r+1)
    		break;
    	maxi=max(seti[j+1]-seti[j],maxi);
    }
    maxi--;
    cout<<maxi<<endl;


}