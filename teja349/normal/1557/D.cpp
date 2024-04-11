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


pii seg[2434567],lazy[2434567];

vector<vi> adj(312345);

int build(int node,int s,int e){
	seg[node]=mp(0,0);
	lazy[node]=mp(0,0);
	if(s==e)
		return 0;
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	return 0;
}

int update(int node,int s,int e,int l,int r,pii val){
	//cout<<l<<" "<<r<<" "<<val.ff<<endl;
	if(lazy[node].ff){
		seg[node]=max(lazy[node],seg[node]);
		if(s!=e){
			lazy[2*node]=max(lazy[2*node],lazy[node]);
			lazy[2*node+1]=max(lazy[2*node+1],lazy[node]);
		}
		lazy[node]=mp(0,0);
	}
	if(e<l || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		lazy[node]=val;
		if(lazy[node].ff){
			seg[node]=max(lazy[node],seg[node]);
			if(s!=e){
				lazy[2*node]=max(lazy[2*node],lazy[node]);
				lazy[2*node+1]=max(lazy[2*node+1],lazy[node]);
			}
			lazy[node]=mp(0,0);
		}
		return 0;
	}

	int mid=(s+e)/2;
	update(2*node,s,mid,l,r,val);
	update(2*node+1,mid+1,e,l,r,val);

	seg[node]=max(seg[2*node],seg[2*node+1]);
	return 0;
}

pii query(int node,int s,int e,int l,int r){
	if(lazy[node].ff){
		seg[node]=max(lazy[node],seg[node]);
		if(s!=e){
			lazy[2*node]=max(lazy[2*node],lazy[node]);
			lazy[2*node+1]=max(lazy[2*node+1],lazy[node]);
		}
		lazy[node]=mp(0,0);
	}
	if(e<l || r<s){
		return mp(0,0);
	}
	if(l<=s && e<=r){
		return seg[node];
	}
	int mid=(s+e)/2;
	pii aa=query(2*node,s,mid,l,r);
	pii bb=query(2*node+1,mid+1,e,l,r);
	return max(aa,bb);
}

int row[312345],l[312345],r[312345];
pii dp[312345];
int ans[312345];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
    	int n,m;
    	cin>>n>>m;
    	int i,j;
    	vii vec;
    	rep(i,m){
    		cin>>row[i]>>l[i]>>r[i];
    		vec.pb(mp(l[i],0));
    		vec.pb(mp(r[i],1));
    		row[i]--;
    		adj[row[i]].pb(i);
    		
    	}
    	sort(all(vec));
    	int curr=1;
    	vii haha;
    	rep(i,vec.size()){
    		if(vec[i].ss==1){
    			if(curr==vec[i].ff+1)
    				continue;
    			haha.pb(mp(curr,vec[i].ff));
    			curr=vec[i].ff+1;
    		}
    		else{
    			if(curr==vec[i].ff)
    				continue;
    			haha.pb(mp(curr,vec[i].ff-1));
    			curr=vec[i].ff;
    		}
    	}
    	map<int,int> st;
    	map<int,int> en;
    	rep(i,haha.size()){
    		//cout<<haha[i].ff<<" "<<haha[i].ss<<endl;
    		st[haha[i].ff]=i;
    		en[haha[i].ss]=i;
    	}
    	int boo = haha.size();
    	boo+=2;
    	build(1,0,boo);
    	int maxi=0;
    	int rem=0;
    	fd(i,n-1,0){
    		dp[i]=mp(0,0);
    		rep(j,adj[i].size()){
    			int ind = adj[i][j];

    			dp[i]=max(query(1,0,boo,st[l[ind]],en[r[ind]]),dp[i]);
    		}
    		dp[i].ff++;
    		
    		//cout<<i+1<<" "<<dp[i].ff<<endl;
    		if(maxi<dp[i].ff){
    			maxi=dp[i].ff;
    			rem	=i;
    		}
    		rep(j,adj[i].size()){
    			int ind = adj[i][j];
    			update(1,0,boo,st[l[ind]],en[r[ind]],mp(dp[i].ff,i));
    		}
    	}
    	cout<<n-maxi<<endl;
	    while(1){
	    	ans[rem]=1;
	    	if(dp[rem].ff==1)
	    		break;
	    	rem=dp[rem].ss;
	    }

	    rep(i,n){
	    	if(ans[i]==0)
	    		cout<<i+1<<" ";
	    }
	    cout<<endl;
    }

    

    return 0;
}