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
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (998244353)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
#define int ll 
 
 int powe(int a,int b){
 	int ans=1;
 	while(b){
 		if(b%2){
 			ans*=a;
 			ans%=mod;
 		}
 		a*=a;
 		a%=mod;
 		b/=2;
 	}
 	return ans;
 }
 int a[12345],b[12345],fact[12345];
signed main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);

	int d;
	cin>>d;
	int q;
	cin>>q;
	int i;
	vi prim;
	int dd=d;
	for(i=2;i*i<=d;i++){
		if(dd%i==0)
			prim.pb(i);
		while(dd%i==0)
			dd/=i;
	}
	fact[0]=1;
	f(i,1,12345){
		fact[i]=fact[i-1]*i;
		fact[i]%=mod;
	}
	if(dd!=1){
		prim.pb(dd);
	}
	int u,v;
	int j;
	rep(j,q){
		cin>>u>>v;
		rep(i,prim.size()){
			a[i]=0;
			while(u%prim[i]==0){
				u/=prim[i];
				a[i]++;
			}
			b[i]=0;
			while(v%prim[i]==0){
				v/=prim[i];
				b[i]++;
			}
		}
		int dec=0,inc=0;
		int gg=1,lol=1;
		rep(i,prim.size()){
			if(a[i]<b[i]){
				inc+=b[i]-a[i];
				lol*=fact[b[i]-a[i]];
				lol%=mod;
			}
			else if(b[i]<a[i]){
				dec+=a[i]-b[i];
				gg*=fact[a[i]-b[i]];
				gg%=mod;
			}
			
		}
		int ans=1;
		gg=powe(gg,mod-2);
		lol=powe(lol,mod-2);
		ans=fact[dec]*gg;
		ans%=mod;
		ans*=(fact[inc]*lol)%mod;
		ans%=mod;
		cout<<ans<<endl;
	}
}