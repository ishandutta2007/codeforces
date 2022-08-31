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
vi vec;
ll papa=0;
ll solve(ll n){
	if(n==0){
		vec.pb(0);
		return 0;
	}
	ll i,sumi=1;
	rep(i,24){
		sumi*=2;
		if(sumi>n){
			break;
		}
	}
	sumi/=2;
	sumi--;
	ll ans;
	//cout<<"Yoo"<<sumi<<endl;
	rep(i,sumi+1){
		//cout<<i<<endl;
		ans=sumi-i;
		if(sumi+1+ans<=n){
			vec.pb(sumi+1+ans);
			papa+=sumi+1+sumi;
		}
		else{
			vec.pb(ans);
			papa+=sumi;
		}
		//cout<<papa<<endl;
	}
	papa+=(n-sumi)*(sumi+1);
	solve(n-sumi-1);
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	ll i;
	solve(n);    
	cout<<papa<<endl;
	rep(i,vec.size()){
		cout<<vec[i]<<" ";
	}
}