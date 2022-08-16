// teja349
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


//helper functions
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

ll a[2234567],haha[2234567];
int main(){
	std::ios::sync_with_stdio(false);
	ll n,x,y;
	cin>>n>>x>>y;
	ll d=x/y;
	ll i,j,val;
	rep(i,n){
		cin>>val;
		a[val]++;
	}
	f(i,1,2000*1000+100){
		
		haha[i]=haha[i-1]+a[i]*i;
		a[i]+=a[i-1];
	}
	ll iinf=inf;
	iinf*=inf;
	ll lolo=iinf;
	ll counti=0,ans=0;
	for(i=2;i<=1000*1000+10;i++){
		val=min(d+1,i);
		ans=0;
		counti=0;
		for(j=i;j<=2000*1000+10;j+=i){
			counti+=a[j]-a[j-val];
			ans+=((a[j]-a[j-val])*j-haha[j]+haha[j-val]);

		}
		ans*=y;
		ans+=(n-counti)*x;
		
		lolo=min(lolo,ans);
	}
	cout<<lolo<<endl;


	return 0;  
}