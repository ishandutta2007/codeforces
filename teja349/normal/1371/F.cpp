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
#define tri pair<int, total >
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
struct total{
	int maxi,lef,rig,maxl,maxr;
};

total seg[2][2123456];
int lazy[2123456];
int a[512345];
total merger(total a,total b,int sizl,int sizr){
	total c;
	c.maxi=max(a.maxi,b.maxi);
	c.maxi=max(c.maxi,a.maxr+b.lef);
	c.maxi = max(c.maxi,a.rig+b.maxl);
	c.rig=b.rig;
	c.lef=a.lef;
	c.maxl=a.maxl;
	c.maxr=b.maxr;
	if(c.maxl == sizl){
		c.maxl+=b.lef;
	}
	if(c.maxr == sizr){
		c.maxr+=a.rig;
	}

	if(b.rig==sizr){
		c.rig+=a.rig;
	}
	if(b.lef==sizr){
		c.maxr = b.lef + a.maxr;
	}
	if(a.lef==sizl){
		c.lef+=b.lef;
	}
	if(a.rig == sizl){
		c.maxl = a.rig + b.maxl;
	}
	assert(c.maxl<=c.maxi);
	assert(c.maxr<=c.maxi);
	// if(c.maxl<c.lef){
	// 	cout<<seg[1][4].maxl<<" "<<seg[1][4].lef<<" "<<sizl<<" "<<sizr<<endl;
	// 	exit(0);
	// }
	// else{
	// 	cout<<c.maxl<<" "<<c.lef<<endl;
	// }
	assert(c.maxl>=c.lef);
	assert(c.maxr>=c.rig);
	return c;
}
int build(int node,int s,int e){
	if(s==e){
		seg[0][node].maxi=1;
		seg[1][node].maxi=1;
		seg[0][node].maxr=1;
		seg[0][node].maxl=1;
		seg[1][node].maxr=1;
		seg[1][node].maxl=1;
		if(a[s]==1){
			seg[0][node].rig=1;
			seg[1][node].lef=1;
		}
		else{
			seg[0][node].lef=1;
			seg[1][node].rig=1;
		}
		return 0;
	}
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	int sizl=mid-s+1;
	int sizr=e-mid;
	int i;
	//cout<<node<<" "<<s<<" "<<e<<endl;
	f(i,0,2){
		total c = merger(seg[i][2*node],seg[i][2*node+1],sizl,sizr);
		seg[i][node]=c;
	}
	return 0;
}

tri query(int node,int s,int e,int l,int r){
	if(lazy[node]){
		if(s!=e){
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
		lazy[node]=0;
		
		swap(seg[0][node],seg[1][node]);
	}
	if(r<s || e<l){
		total a;
		a.maxi=0;
		a.lef=0;
		a.rig=0;
		a.maxl=0;
		a.maxr=0;
		return mp(0,a);
	}
	if(l<=s && e<=r){
		
		return mp(e-s+1,seg[0][node]);
	}
	int mid=(s+e)/2;
	tri a=query(2*node,s,mid,l,r);
	tri b=query(2*node+1,mid+1,e,l,r);
	int sizl=a.ff;
	int sizr=b.ff;
	total c = merger(a.ss,b.ss,sizl,sizr);
	//cout<<node<<" "<<s<<" "<<e<<" "<<c.maxi<<endl;
	return mp(sizl+sizr,c);
}
int update(int node,int s,int e,int l,int r){
	if(lazy[node]){
		if(s!=e){
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
		lazy[node]=0;
		
		swap(seg[0][node],seg[1][node]);
	}
	if(r<s || e<l){
		return 0;
	}
	if(l<=s && e<=r){
		swap(seg[0][node],seg[1][node]);
		if(s!=e){
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
		return 0;
	}
	int mid=(s+e)/2;
	update(2*node,s,mid,l,r);
	update(2*node+1,mid+1,e,l,r);
	int sizl=mid-s+1;
	int sizr=e-mid;
	int i;
	rep(i,2){
		total c = merger(seg[i][2*node],seg[i][2*node+1],sizl,sizr);
		seg[i][node]=c;
	}
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    int i;
    string s;
    cin>>s;
    rep(i,n){
    	if(s[i]=='>')
    		a[i]=1;
    	else
    		a[i]=0;
    }
    build(1,0,n-1);
    //return 0;
    int l,r;
    rep(i,q){
    	cin>>l>>r;
    	l--;
    	r--;
    	update(1,0,n-1,l,r);
    	tri a = query(1,0,n-1,l,r);
    	cout<<a.ss.maxi<<endl;
    }
    return 0;   
}