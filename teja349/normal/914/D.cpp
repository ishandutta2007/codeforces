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
int seg[2012345],a[512345];

int build(int node,int s,int e){
	if(s==e){
		seg[node]=a[s];
		return 0;
	}
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	seg[node]=__gcd(seg[2*node],seg[2*node+1]);
	return 0;
}
int update(int node,int s,int e,int pos,int val){
	if(s==e){
		seg[node]=val;
		return 0;
	}
	int mid=(s+e)/2;
	if(pos<=mid){
		update(2*node,s,mid,pos,val);
	}
	else{
		update(2*node+1,mid+1,e,pos,val);
	}
	seg[node]=__gcd(seg[2*node],seg[2*node+1]);
	return 0;
}
int query(int node,int s,int e,int l,int r,int val){
	if(e<l || r<s)
		return 0;

	if(l<=s && e<=r)
		return seg[node];
	int mid=(s+e)/2;
	int a=query(2*node,s,mid,l,r,val);
	int b=query(2*node+1,mid+1,e,l,r,val);
	return __gcd(a,b);
}
int checkit(int &ans,int node,int s,int e,int l,int r,int val){
	if(e<l || r<s){
		return 0;
	}
	if(s==e){
		return 0;
	}
	int mid=(s+e)/2;
	int a=query(2*node,s,mid,l,r,val);
	int b=query(2*node+1,mid+1,e,l,r,val);
	//cout<<val<<" "<<b<<endl;
	if(a%val && b%val){
		ans=0;
	}
	else if(a%val){
		checkit(ans,2*node,s,mid,l,min(r,mid),val);
	}
	else if(b%val){
		checkit(ans,2*node+1,mid+1,e,max(l,mid+1),r,val);
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    rep(i,n){
    	cin>>a[i];
    }
    build(1,0,n-1);
    int q,typ,l,r,x,pos,val;
    cin>>q;
    int ans=1;
    while(q--){
    	cin>>typ;
    	if(typ==1){
    		cin>>l>>r>>x;
    		l--;
    		r--;
    		ans=1;
    		val=checkit(ans,1,0,n-1,l,r,x);
    		if(ans){
    			cout<<"YES"<<endl;
    		}
    		else{
    			cout<<"NO"<<endl;
    		}
    	}
    	else{
    		cin>>pos>>val;
    		pos--;
    		update(1,0,n-1,pos,val);
    	}
    }
    return 0;  
    
}