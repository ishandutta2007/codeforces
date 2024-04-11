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
int seg[412345];
int a[123456];
int update(int node,int s,int e,int p,int val){
	if(s==e){
		seg[node]=max(seg[node],val);
		return 0;
	}
	int mid=(s+e)/2;
	if(p<=mid){
		update(2*node,s,mid,p,val);
	}
	else{
		update(2*node+1,mid+1,e,p,val);
	}
	seg[node]=max(seg[2*node],seg[2*node+1]);
	return 0;

}
int query(int node,int s,int e,int l,int r){
	if(e<l || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		return seg[node];
	}
	int mid=(s+e)/2;
	int val=query(2*node,s,mid,l,r);
	val=max(val,query(2*node+1,mid+1,e,l,r));
	return val;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    rep(i,n){
    	cin>>a[i];
    }
    int ans,maxi=1;
   	rep(i,n){
   		ans=query(1,1,n,1,a[i])+1;
   		update(1,1,n,a[i],ans);
   		maxi=max(ans,maxi);
   	}
   	cout<<maxi<<endl;

    return 0;      

}