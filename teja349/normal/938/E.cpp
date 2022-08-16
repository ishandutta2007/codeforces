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
ll gcd(ll a,ll b){
	while(b!=0){
		
		a=a%b;
		swap(a,b);
	}
	return a;
}

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
ll inverse(ll a){
	ll x,y;
	extend_gcd(mod,a,x,y);
	y%=mod;
	y+=mod;
	y%=mod;
	return y;
}
ll dp[1234567],cnt[1234567];
ll counter=0;
map<ll,ll> mapi,inv;
map<ll,ll>::iterator it;
ll a[1234567];
int main(){
    std::ios::sync_with_stdio(false);
    ll n,i;
    cin>>n;
    rep(i,n){
    	cin>>a[i];
    	mapi[a[i]]=0;
    }
    for(it=mapi.begin();it!=mapi.end();it++){
    	it->ss=counter++;
    	inv[it->ss]=it->ff;
    }
    rep(i,n){
    	cnt[mapi[a[i]]]++;
    }
    dp[counter-1]=0;
    ll ans=0;
    ll wow=0;
    ll elems=cnt[counter-1];
    fd(i,counter-2,0){
    	dp[i]=ans;
    	dp[i]*=inverse(elems);
    	dp[i]%=mod;
    	dp[i]+=inv[i];
    	dp[i]%=mod;
    	wow+=cnt[i]*dp[i];
    	wow%=mod;
    	elems+=cnt[i];
    	ans+=dp[i]*cnt[i];
    	ans%=mod;

    }
    f(i,1,n){
    	wow*=i;
    	wow%=mod;
    }
    cout<<wow<<endl;
    //sort(a,a+n);

    return 0;  
    
}