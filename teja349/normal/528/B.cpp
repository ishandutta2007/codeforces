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
map<int,int> mapi;
vii vec;
int a[412345],arr[412345];
int main(){
	std::ios::sync_with_stdio(false);
	int n,i,u,v;
	cin>>n;
	rep(i,n){
		cin>>u>>v;
		vec.pb(mp(u-v,u+v));
		mapi[u-v]=0;
		mapi[u+v]=0;
	}
	rep(i,412345){
		a[i]=inf;
		arr[i]=inf;
	}
	int counter=1;
	map<int,int> :: iterator it;
	for(it=mapi.begin();it!=mapi.end();it++){
		it->ss=counter++;
	}
	rep(i,n){
		vec[i].ff=mapi[vec[i].ff];
		vec[i].ss=mapi[vec[i].ss];
	}
	rep(i,n){
		a[vec[i].ff]=min(a[vec[i].ff],vec[i].ss);
	}
	fd(i,400010,0){
		arr[i]=min(arr[i+1],a[i]);
	}
	i=0;
	int haha=0;
	while(arr[i]!=inf){
		haha++;
		i=arr[i];	

	}
	cout<<haha<<endl;



}