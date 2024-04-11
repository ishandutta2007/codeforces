
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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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
ll inv[100003],mult[100003],invmult[100003];
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
	f(i,1,100001){
		ll x,y;
		ll val=extend_gcd(mod,i,x,y);
		if(y>0)
			inv[i]=y%mod;
		else{
				inv[i]=(y+mod)%mod;
		}
	}
	mult[0]=1;
	f(i,1,100001){
		mult[i]=mult[i-1]*i;
		mult[i]%=mod;
	}
	invmult[0]=1;
	f(i,1,100001){
		invmult[i]=invmult[i-1]*inv[i];
		invmult[i]%=mod;
	}
}

ll power(ll a,ll b){
	ll ans=1;
	if(b&1){
		ans*=a;
	}
	while(b/2>0){
		b=b/2;
		a*=a;
		a%=mod;
		if(b&1) {
			ans*=a;
			ans%=mod;
		}
	}
	ans%=mod;
	return ans;
}
ll ans[1000];
ll dp[105][10020];
ll computedp(int pos,int num);
ll n,m,k,modofn;
int main(){
	std::ios::sync_with_stdio(false);
	ll i,j;
	cin>>n>>m>>k;
	initcombi();
	ll value=m/n;

	rep(i,n+1){
		ans[i]=combination(n,i);
	}
	rep(i,n+1){
		ans[i]=power(ans[i],value);
	}
	rep(i,n+2){
		rep(j,k+10){
			dp[i][j]=-1;
		}
	}
	modofn=m%n;
	computedp(1,k);
	cout<<dp[1][k]<<endl;

}

ll computedp(int pos,int num){
	

	if(num==0){
		//cout<<"hii";
		dp[pos][num]=1;
		return 1;
	}
	if(num<0)
		return 0;
	if(pos==n+1)
		return 0;
	if(dp[pos][num]!=-1)
		return dp[pos][num];
	int i;
	dp[pos][num]=0;
	ll value;
	rep(i,n+1){ 
		value=computedp(pos+1,num-i);
		value*=ans[i];
		value%=mod;
		if(pos<=modofn){
			value*=combination(n,i);
			value%=mod;
		}
		dp[pos][num]+=value;
		dp[pos][num]%=mod;
	}
	dp[pos][num]%=mod;
	return dp[pos][num];
}