
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
#define mod (1000*1000*1000+9)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);
ll power(ll a,ll b){
	ll ans=1;
	if(b%2==1)
		ans*=a;
	while(b!=0){
		b=b/2;
		a=a*a;
		a%=mod;
		if(b%2==1)
			ans*=a;
		ans%=mod;
	}
	return ans;
}   
int main(){
	ll n,m,k,sum=0;
	cin>>n>>m>>k;
	ll val=n/k;
	ll wrong=n-m;
	//cout<<val<<" "<<wrong;
	if(val<=wrong){
		//cout<<"hiii";
		cout<<m<<endl;
		return 0;
	}
	sum+=(((2*(power(2,val-wrong)+mod-1))%mod)*k)%mod;
	
	sum+=(k-1)*wrong+n%k;
	sum%=mod;
	cout<<sum<<endl;
}