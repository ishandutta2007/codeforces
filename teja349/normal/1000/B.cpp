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
ll haha[123456],onn[123456],off[123456];
ll a[123456],n;
ll compute(ll pos,ll lit){
	if(pos==n+1){
		haha[n+1]=0;
		onn[pos]=0;
		off[pos]=0;
		return 0;
	}
	
	compute(pos+1,lit^1);
	haha[pos]=lit;
	onn[pos]=onn[pos+1];
	off[pos]=off[pos+1];
	if(lit)
		onn[pos]+=a[pos+1]-a[pos];
	else
		off[pos]+=a[pos+1]-a[pos];
	return 0;
}

int main(){
    std::ios::sync_with_stdio(false);
    ll m;
    cin>>n>>m;
    ll i;
    f(i,1,n+1){
    	cin>>a[i];
    }
    a[n+1]=m;
    a[0]=0;
    compute(0,1);
    ll maxi=onn[0];
    if(a[n]+1!=a[n+1] && !haha[n]){
    	maxi=max(maxi,onn[0]+1);
    }
    if(a[0]+1!=a[1]){
    	maxi=max(maxi,off[0]+1);
    }
    f(i,1,n+1){
    	if(a[i-1]+1!=a[i]){
    		if(haha[i]){
    			maxi=max(onn[0]+off[i]+1-onn[i],maxi);
    		}
    		else{
    			maxi=max(onn[0]+off[i]-1-onn[i],maxi);
    		}
    	}
    	if(a[i]+1!=a[i+1]){
    		if(haha[i]){
    			maxi=max(onn[0]+off[i]+1-onn[i],maxi);
    		}
    		else{
    			maxi=max(onn[0]+off[i]-1-onn[i],maxi);
    		}
    	}

    }

    cout<<maxi<<endl;


}