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
int isprime(int val){
	int i;
	if(val==2)
		return 1;
	if(val%2==0)
		return 0;
	for(i=2;i*i<=val;i++){
		if(val%i==0)
			return 0;
	}
	return 1;
}
int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,i;
		cin>>n;
		fd(i,n,0){
			if(isprime(i))
				break;
		}
		ll haha=i;
		f(i,n+1,n+100000){
			if(isprime(i))
				break;
		}
		ll lol = haha*i;
		ll a=__gcd(i+haha-n-1,lol);
		lol/=a;
		haha=(i+haha-n-1)/a;
		haha=lol-2*haha;
		lol*=2;
		a=__gcd(haha,lol);
		cout<<haha/a<<"/"<<lol/a<<endl;
	}
}