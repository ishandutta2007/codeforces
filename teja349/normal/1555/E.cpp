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

int seg[4123456],lazy[4123456];
int update(int node,int s,int e,int l,int r,int val){
	if(lazy[node]){
		seg[node]+=lazy[node];
		if(s!=e){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(r<s|| e<l){
		return 0;
	}
	if(l<=s && e<=r){
		lazy[node]=val;
		seg[node]+=lazy[node];
		if(s!=e){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
		return 0;
	}
	int mid=(s+e)/2;
	update(2*node,s,mid,l,r,val);
	update(2*node+1,mid+1,e,l,r,val);
	seg[node]=min(seg[2*node],seg[2*node+1]);
	return 0;
}


int query(int node,int s,int e,int l,int r){
	// cout<<node<<" "<<s<<" "<<e<<endl;
	if(lazy[node]){
		seg[node]+=lazy[node];
		if(s!=e){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(r<s|| e<l){
		return 1;
	}
	if(l<=s && e<=r){
		return seg[node];
	}
	int mid=(s+e)/2;
	int haha = query(2*node,s,mid,l,r);
	int lol = query(2*node+1,mid+1,e,l,r);
	return min(haha,lol);
}

int l[1234567],r[1234567],w[1234567];

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int i;
    vii vec;
    rep(i,n){
    	cin>>l[i]>>r[i]>>w[i];
    	l[i]++;
    	vec.pb(mp(w[i],i));
    }	
    sort(all(vec));
    i=0;
    int j=-1;
    int ans=inf;
    while(j<n){
    	int val=query(1,0,m,2,m);
    	if(val>0){
    		// cout<<i<<" "<<j<<endl;
    		ans=min(ans,vec[j].ff-vec[i].ff);
    		int ind = vec[i].ss;
    		update(1,0,m,l[ind],r[ind],-1);	
    		i++;
    	}
    	else{
    		j++;
    		if(j==n){
    			break;
    		}
    		// cout<<j<<endl;
    		int ind=vec[j].ss;
    		update(1,0,m,l[ind],r[ind],1);
    	}
    }
    cout<<ans<<endl;
    return 0;
}