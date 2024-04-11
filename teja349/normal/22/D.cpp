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
vi vec;
vii arr;
int bit[233456]={0};
int update(int pos){
	while(pos<223456){
		bit[pos]++;
		pos+=pos&(-pos);
	}
}
int query(int pos){
	int sumi=0;
	while(pos>0){
		sumi+=bit[pos];
		pos-=pos&(-pos);
	}
	return sumi;
}
int main(){
	int n;
	int i,u,v;
	cin>>n;
	rep(i,n){
		cin>>u>>v;
		if(u>v){
			swap(u,v);
		}
		u+=50000;
		v+=50000;
		arr.pb(mp(v,u));
	}
	sort(arr.begin(),arr.end());
	rep(i,n){
		if(query(arr[i].ff)-query(arr[i].ss-1) == 0){
			vec.pb(arr[i].ff-50000);
			update(arr[i].ff);
		}

	}
	cout<<vec.size()<<endl;
	rep(i,vec.size()){
		cout<<vec[i]<<" ";
	}
}