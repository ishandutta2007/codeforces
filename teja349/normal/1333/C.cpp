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
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
#define int ll 
int a[212345]; 
signed main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	ll i;
	rep(i,n){
		cin>>a[i];
	}
	map<ll,ll> mapi;
	int sofar=-2;
	mapi[0]=-1;
	ll sumi=0;
	ll ans=0;
	rep(i,n){
		sumi+=a[i];
		if(mapi.find(sumi)==mapi.end())
			mapi[sumi]=-2;
		sofar=max(sofar,mapi[sumi]);
		ans+=i-sofar-1;
		mapi[sumi]=max(mapi[sumi],i);
	}
	cout<<ans<<endl;
}