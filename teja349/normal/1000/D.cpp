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
#define mod (998244353)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

 
ll inv[400003],mult[400003],invmult[400003];
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
 
ll combination(ll n,ll r){
	if(r==0)
		return 1;
	if(n<r)
		return 0;
	ll ans=1;
	ans*=mult[n];
	ans%=mod;
	ans*=invmult[r];
	ans%=mod;
	ans*=invmult[n-r];
	ans%=mod;
	return ans;
}
 
ll initcombi(){
	int i;
	f(i,1,400001){
		ll x,y;
		ll val=extend_gcd(mod,i,x,y);
		if(y>0)
			inv[i]=y%mod;
		else{
				inv[i]=(y+mod)%mod;
		}
	}
	mult[0]=1;
	f(i,1,400001){
		mult[i]=mult[i-1]*i;
		mult[i]%=mod;
	}
	invmult[0]=1;
	f(i,1,400001){
		invmult[i]=invmult[i-1]*inv[i];
		invmult[i]%=mod;
	}
	return 0;
}
 
 
// do initcombi();
ll visit[12345],dp[12345],a[12345];
 int n;
//std::ios::sync_with_stdio(false);
int compute(int pos){
	if(pos>n)
		return 0;
	if(visit[pos])
		return dp[pos];
	visit[pos]=1;
	if(a[pos]<=0){
		dp[pos]=0;
		return dp[pos];
	}
	dp[pos]=0;
	int i;
	f(i,pos+a[pos]+1,n+1){
		dp[pos]+=combination(i-pos-1,a[pos])*compute(i);
		dp[pos]%=mod;
	}
	dp[pos]%=mod;
	return dp[pos];
}
int main(){
    std::ios::sync_with_stdio(false);
   	initcombi();
    cin>>n;
    int i;
    rep(i,n){
    	cin>>a[i];
    }
    dp[n]=1;
    visit[n]=1;
    ll ans=0;
    rep(i,n){
    	ans+=compute(i);
    	//cout<<compute(i)<<endl;
    	ans%=mod;
    }
    cout<<ans<<endl;

}