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

// int seg[1234567];

// int update(int node,int s,int e,int pos,int val){
// 	int mid=(s+e)/2;
// 	if(s==e){
// 		seg[node]=val;
// 		return 0;
// 	}
// 	if(pos<=mid)
// 		update(2*node,s,mid,pos,val)
// 	else
// 		update(2*node+1,mid+1,e,pos,val);
// 	seg[node]=max(seg[2*node],seg[2*node+1]);
// 	return 0;
// }

// int query(int node,int s,int e,int l,int r){
// 	int mid=(s+e)/2;
// 	if(l<=s && e<=r){
// 		return seg[node];
// 	}
// 	if(r<s || e<l)
// 		return 0;
// 	return max(query(2*node,s,mid,l,r),query(2*node+1,mid+1,e,l,r));
// }

// int build(int node,int s,int e){
// 	if(s==e){
// 		seg[node]=max(0,a[s]-b[s]);
// 		return 0;
// 	}
// 	int mid=(s+e)/2;
// 	build(2*node,s,mid);
// 	build(2*node+1,mid+1,e);
// 	seg[node]=max(seg[2*node],seg[2*node+1]);
// 	return 0;
// }

int a[212345],b[212345];
int minb[212345],maxb[212345];

int wow[212345];
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    rep(i,n){
    	cin>>a[i];
    }
    vii vec;
    rep(i,n){
    	cin>>b[i];
    	vec.pb(mp(a[i],b[i]));
    }
    sort(all(vec));
    rep(i,n){
    	a[i]=vec[i].ff;
    	b[i]=vec[i].ss;
    	//vec1.pb(mp(b[i],i));
    }
    // sort(all(vec1));
    minb[n-1]=b[n-1];
    fd(i,n-2,0){
    	minb[i]=min(minb[i+1],b[i]);
    }
    maxb[0]=b[0];
    f(i,1,n){
    	maxb[i]=max(maxb[i-1],b[i]);
    }
    // int j=0;
    // build(1,0,n-1);
    // set<int> seti;
    vector<pii>::iterator it;
    int pos;
    int haha=0;

    rep(i,n){
    	wow[i]=0;
    }
    rep(i,n){
    	it=upper_bound(all(vec),mp(b[i],b[i]-inf));
    	pos=it-vec.begin();
    	if(pos<n){
    		wow[pos]=max(wow[pos],a[i]);
    	}
    }
    f(i,1,n){
    	wow[i]=max(wow[i-1],wow[i]);
    }
    

    rep(i,n){
    	if(b[i]<=a[i])
    		continue;
    	// while(j<vec1.size() && vec1[j].ff<=a[i]){
    	// 	update(1,0,n-1,vec1[j].ss,0);
    	// 	seti.insert()
    	// 	j++;
    	// }
    	it=lower_bound(all(vec),mp(b[i],b[i]-inf));
    	pos=it-vec.begin();	
    	if(pos<n){
    		haha=max(haha,2*(b[i]-max(minb[pos],a[i])));
    	}

    	haha=max(haha,2*(min(b[i],wow[i])-a[i]));

    }

    rep(i,n){
    	if(b[i]>=a[i])
    		continue;
    	it=upper_bound(all(vec),mp(b[i]+1,b[i]-inf));
    	pos=it-vec.begin();
    	if(pos!=0){
    		pos--;
    		haha=max(haha,2*(min(a[i],maxb[pos])-b[i]));
    	}
    }



    haha*=-1;
    // cout<<haha<<endl;
    rep(i,n){
    	haha+=abs(a[i]-b[i]);
    }
    cout<<haha<<endl;
    return 0;

}