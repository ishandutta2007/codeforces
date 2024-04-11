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
map<ll ,ll > siz;
ll compute(ll n){
	
	if(n==1){
		siz[n]=1;
		return 1;
	}
	ll val=compute(n/2);
	siz[n]=val*2+1;
	return siz[n];

}

int calc(ll l,ll r,ll n){
	//cout<<n/2<<endl;
	ll ans=0;
	if(l>r)
		return 0;
	if(n==1)
		return 1;

	if(siz[n/2]+1<l){
		
		return calc(l-siz[n/2]-1,r-siz[n/2]-1,n/2);
	}
	else if(siz[n/2]+1==l){
		//cout<<"sfsd";
		//cout<<l<<n/2<<endl;
		ans=calc(1,r-siz[n/2]-1,n/2);
		if(n%2)
			ans++;
		return ans;
	}
	else if(siz[n/2]+1>r){
		//cout<<l<<n/2<<endl;
		return calc(l,r,n/2);
	}
	else if(siz[n/2]+1==r){

		ans=calc(l,siz[n/2],n/2);
		if(n%2)
			ans++;
		return ans;

	}
	else{
		//cout<<"hii"<<n/2<<endl;
		ans=calc(l,siz[n/2],n/2)+calc(1,r-siz[n/2]-1,n/2);
		if(n%2)
			ans++;
		return ans;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	ll n,l,r;
	cin>>n>>l>>r;
	if(n==0){
		cout<<0<<endl;
		return 0;
	}

	compute(n);
	//cout<<siz[3]<<endl;
	//cout<<n<<endl;
	cout<<calc(l,r,n)<<endl;
	return 0;

}