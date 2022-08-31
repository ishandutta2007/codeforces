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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define int ll

int seg[412345];
int segmin[412345];
int lazy[412345];
int a[123456],kk[123456];
int updatesum(int node,int s,int e,int l,int r,int val){
	if(lazy[node]){
		seg[node]+=(e-s+1)*lazy[node];
		if(s!=e){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(r<s || e<l)
		return 0;
	if(l<=s && e<=r){
		lazy[node]=val;
		seg[node]+=(e-s+1)*lazy[node];
		if(s!=e){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
		return 0;
	}
	int mid=(s+e)/2;
	updatesum(2*node,s,mid,l,r,val);
	updatesum(2*node+1,mid+1,e,l,r,val);
	seg[node]=seg[2*node]+seg[2*node+1];
	return 0;
}

int querysum(int node,int s,int e,int l,int r){
	if(lazy[node]){
		seg[node]+=(e-s+1)*lazy[node];
		if(s!=e){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(r<s || e<l)
		return 0;
	if(l<=s && e<=r){
		return seg[node];
	}
	int mid=(s+e)/2;
	int res=querysum(2*node,s,mid,l,r);
	res+=querysum(2*node+1,mid+1,e,l,r);
	return res;
}

int buildsum(int node,int s,int e){
	if(s==e){
		seg[node]=a[s];
		return 0;
	}
	int mid=(s+e)/2;
	buildsum(2*node,s,mid);
	buildsum(2*node+1,mid+1,e);
	seg[node]=seg[2*node]+seg[2*node+1];
	return 0;
}

int update(int node,int s,int e,int pos,int val){
	if(s==e){
		if(val==0){
			segmin[node]=s;
		}
		else{
			segmin[node]=inf;
		}
		return 0;
	}
	int mid=(s+e)/2;
	if(pos<=mid){
		update(2*node,s,mid,pos,val);
	}
	else{
		update(2*node+1,mid+1,e,pos,val);
	}
	segmin[node]=min(segmin[2*node],segmin[2*node+1]);
	return 0;
}

int query(int node,int s,int e,int l,int r){
	if(e<l || r<s){
		return inf;
	}
	if(l<=s && e<=r){
		return segmin[node];
	}
	int mid=(s+e)/2;
	int res=query(2*node,s,mid,l,r);
	res=min(res,query(2*node+1,mid+1,e,l,r));
	return res;
}
int build(int node,int s,int e){
	if(s==e){
		segmin[node]=s;
		return 0;
	}
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	segmin[node]=min(segmin[2*node],segmin[2*node+1]);
	return 0;
}
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n;
  	cin>>n;
  	int i;
  	rep(i,n){
  		cin>>a[i];
  	}
  	rep(i,n-1){
  		cin>>kk[i];
  	}
  	int q;
  	cin>>q;
  	char ch;
  	int pos,val;
  	build(1,0,n-1);
  	buildsum(1,0,n-1);
  	int diff,nex,gg,haha,wow,l,r;
  	rep(i,q){
  		cin>>ch;
  		if(ch=='+'){
  			cin>>pos>>val;
  			pos--;
  			updatesum(1,0,n-1,pos,pos,val);
  			diff=val;
  			nex=pos+1;
  			update(1,0,n-1,pos,0);
  			while(nex<n){
  				gg=query(1,0,n-1,nex,n-1);
  				//cout<<nex<<" "<<gg<<endl;
  				if(gg==inf)
  					gg=n;
  				if(nex<=gg-1){
  					//cout<<nex<<" "<<gg-1<<" "<<diff<<endl; 
  					updatesum(1,0,n-1,nex,gg-1,diff);
  				}
  				if(gg==n)
  					break;
  				haha=querysum(1,0,n-1,gg-1,gg-1);
  				wow=querysum(1,0,n-1,gg,gg);
  				if(haha+kk[gg-1]<=wow)
  					break;
  				diff=haha+kk[gg-1]-wow;
  				update(1,0,n-1,gg,1);
  				nex=gg;
  			}
  		}
  		else{
  			cin>>l>>r;
  			l--;
  			r--;
  			cout<<querysum(1,0,n-1,l,r)<<endl;
  		}
  	}
    return 0;   
}