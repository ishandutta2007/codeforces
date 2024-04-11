
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
ll a[40];
int n;
ll maxi=0;
vll vec(2000);
string s;
pll compute(ll pos);
int main(){
	std::ios::sync_with_stdio(false);
	int i;
	
	cin>>n>>s;
	rep(i,26){
		cin>>a[i];
	}
	rep(i,n+10){
		vec[i]=mp(-1,-1);
	}
	pll value=compute(0);
	cout<<value.ff<<endl;
	cout<<maxi<<endl;
	cout<<value.ss<<endl;
}
pll compute(ll pos){
	if(pos==n){

		return mp(1,0);
	}
	if(vec[pos].ff!=-1 && vec[pos].ss!=-1)
		return vec[pos];
	ll val=1;
	ll i=0;
	val=a[s[i+pos]-'a'];
	ll mini=20000,answ=0;
	while(i<val && i+pos<n){
		pll value=compute(i+pos+1);
		answ+=value.ff;
		answ%=mod;
		mini=min(mini,value.ss + 1);
		i++;
		
			val=min(val,a[s[i+pos]-'a']);

	}
	answ%=mod;
	maxi=max(maxi,i);
	vec[pos]=mp(answ,mini);
	return vec[pos];
}