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
ll bite[212345]={0},lol[212345],a[212345];
int update(int ind,int val){
	while(ind<212333){
		bite[ind]+=val;
		ind+=ind&(-ind);

	}
	return 0;
}
int query(int ind){
	int sumi=0;
	while(ind>0){
		sumi+=bite[ind];
		ind-=ind&(-ind);
	}
	return sumi;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,aa,b;
	cin>>n>>m;
	rep(i,n){
		cin>>a[i];
	}
	rep(i,m){
		cin>>aa>>b;
		update(aa,1);
		update(b+1,-1);
	}
	rep(i,n){
		lol[i]=query(i+1);
		//cout<<lol[i]<<endl;
	}
	sort(lol,lol+n);
	sort(a,a+n);
	ll hahava=0;
	rep(i,n){
		hahava+=a[i]*lol[i];
	}
	cout<<hahava<<endl;

}