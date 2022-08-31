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
ll arr[1234569]={0},a[1234567];
ll ans[1234567]={0},fact[1234567];
ll all;
ll n;
ll update(ll ind){
	while(ind<1234567){
		arr[ind]++;
		ind+=ind&(-ind);
	}
	return 0;
}   
ll query(ll ind){
	ll sumi=0;
	while(ind>0){
		sumi+=arr[ind];
		ind-=ind&(-ind);
	}
	return sumi;
}
ll compute(ll ind){
	if(ind==n){
		ans[ind]=0;
		return 0;
	}
	if(ans[ind]!=0)
		return ans[ind];
	ll haha=compute(ind+1)*(n-ind+1);
	haha%=mod;
	ans[ind]=((n-ind)*(n-ind+1)/2);
	ans[ind]%=mod;
	ans[ind]*=fact[n-ind];
	ans[ind]%=mod;
	ans[ind]+=haha;
	ans[ind]%=mod;
	return ans[ind];

}
ll counted(ll val){
	if(val==n){
		all=1;
		return 0;
	}
	update(a[val]);
	ll i=val;
	ll lol=a[val]-1-query(a[val]-1);
	ll answ=counted(val+1);
	ll haha=lol*ans[val+1];
	haha%=mod;
	ll value=lol*(lol-1)/2;
	value%=mod;
	value*=fact[n-i];
	haha+=(value);

	haha%=mod;

	haha+=answ;
	haha%=mod;
	//cout<<all<<"  "<<lol<<endl;
	haha+=all*lol;
	haha%=mod;
	all=lol*fact[n-i]+all;
	all%=mod;
	return haha;

}
int main(){
	std::ios::sync_with_stdio(false);
	ll i;
	fact[0]=1;
	f(i,1,1000003){
		fact[i]=fact[i-1]*i;
		fact[i]%=mod;
	}
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		//update(i,1);
	}
	compute(1);
	cout<<counted(1)<<endl;
	//cout<<ans[3]<<endl;

}