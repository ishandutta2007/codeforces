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

// ll inv[100003],mult[100003],invmult[100003];
// ll gcd(ll a,ll b){
// 	while(b!=0){
		
// 		a=a%b;
// 		swap(a,b);
// 	}
// 	return a;
// }

// ll extend_gcd(ll a,ll b,ll &x,ll &y){
// 	if(b==0){
// 		x=1;
// 		y=0;
// 		return a;
// 	}
// 	ll x1,y1;
// 	ll ans =extend_gcd(b,a%b,x1,y1);
// 	x=y1;
// 	y=x1-(a/b)*y1;

// 	return ans;
// }
// ll combination(ll n,ll r){
// 	if(r==0)
// 		return 1;
// 	if(n<r)
// 		return 0;
// 	ll ans=1;
// 	ans*=mult[n];
// 	ans%=mod;
// 	ans*=invmult[r];
// 	ans%=mod;
// 	ans*=invmult[n-r];
// 	ans%=mod;
// 	return ans;
// }

// ll initcombi(){
// 	int i;
// 	f(i,1,100001){
// 		ll x,y;
// 		ll val=extend_gcd(mod,i,x,y);
// 		if(y>0)
// 			inv[i]=y%mod;
// 		else{
// 				inv[i]=(y+mod)%mod;
// 		}
// 	}
// 	mult[0]=1;
// 	f(i,1,100001){
// 		mult[i]=mult[i-1]*i;
// 		mult[i]%=mod;
// 	}
// 	invmult[0]=1;
// 	f(i,1,100001){
// 		invmult[i]=invmult[i-1]*inv[i];
// 		invmult[i]%=mod;
// 	}
// 	return 0;
// }
ll dp[110][2512]={0};
int main(){
	int t;
	cin>>t;

	//initcombi();
	int i,j,k;
	rep(i,26){
		dp[1][i]=1;
	}
	f(i,2,101){
		rep(j,2504){
			rep(k,26){
				if(j-k>=0){
					dp[i][j]+=dp[i-1][j-k];
					dp[i][j]%=mod;
				}
			}
		}
	}

	while(t--){
		string str;
		ll sumi=0;
		cin>>str;
		rep(i,str.length()){
			sumi+=(str[i]-'a');

		}
		if(dp[str.length()][sumi]!=0)
			cout<<dp[str.length()][sumi]-1<<endl;
		else
			cout<<mod-1<<endl;
	}
}