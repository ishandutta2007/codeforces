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
pii seg[8123456];

int build(int node,int s,int e){
	if(s==e){
		seg[node]=mp(inf,s);
		return 0;
	}
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	seg[node]=min(seg[2*node],seg[2*node+1]);
	return 0;
}
int update(int node,int s,int e,int pos,int val){
	if(s==e){
		seg[node]=mp(val,s);
		return 0;
	}
	int mid=(s+e)/2;
	if(pos<=mid){
		update(2*node,s,mid,pos,val);
	}
	else{
		update(2*node+1,mid+1,e,pos,val);
	}
	seg[node]=min(seg[2*node],seg[2*node+1]);
	return 0;
}
pii query(int node,int s,int e,int l,int r){
	if(e<l || r<s){
		return mp(inf,1);
	}
	if(l<=s && e<=r){
		return seg[node];
	}
	int mid=(s+e)/2;
	return min(query(2*node,s,mid,l,r),query(2*node+1,mid+1,e,l,r));

}
int a[512345],lastoccur[512345],ans[512345],l[512345],r[512345];
vector<vii> haha(512345);
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    rep(i,n){
    	cin>>a[i];
    	lastoccur[a[i]]=-1;
    }
    int q;
    cin>>q;
    rep(i,q){
    	cin>>l[i]>>r[i];
    	l[i]--;
    	r[i]--;
    	haha[r[i]].pb(mp(l[i],i));
    }
    build(1,0,n-1);
    int j;

    rep(i,n){
    	if(lastoccur[a[i]]!=-1){
    		update(1,0,n-1,lastoccur[a[i]],inf);

    	}
    	update(1,0,n-1,i,lastoccur[a[i]]);
    	lastoccur[a[i]]=i;
    	rep(j,haha[i].size()){
    		pii papa = query(1,0,n-1,haha[i][j].ff,i);
    		if(papa.ff>=haha[i][j].ff)
    			papa.ss=n; 
    		ans[haha[i][j].ss]=a[papa.ss];
    	}
    }
    rep(i,q){
    	cout<<ans[i]<<endl;
    }

}