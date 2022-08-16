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
int total=0;
int dsu[123456],a[123456];
int n,m,l;
int valid(int pos){
	if(pos<0 || pos>=n)
		return 0;
	return (a[pos]>l);
}
int dom(int u,int v){
	if(dsu[u]<dsu[v]){
		swap(u,v);
	}
	dsu[v]+=dsu[u];
	dsu[u]=v;
	return 0;
}
int par(int cur){
	if(dsu[cur]<0)
		return cur;
	dsu[cur]=par(dsu[cur]);
	return dsu[cur];
}
int merge(int pos){
	if(a[pos]<=l)
		return 0;
	int val,val1;
	if(valid(pos+1)){
		val=par(pos);
		val1=par(pos+1);
		if(val!=val1){
			total--;
			dom(val,val1);
		}
	}
	if(valid(pos-1)){
		val=par(pos);
		val1=par(pos-1);
		if(val!=val1){
			total--;
			dom(val,val1);
		}
	}

	return 0;

}
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    //int n,m,l;
    cin>>n>>m>>l;
    int i;
    rep(i,n+10){
    	dsu[i]=-1;
    }
    rep(i,n){
    	cin>>a[i];
    	if(a[i]>l)
    		total++;

    }
    rep(i,n){
    	if(a[i]>l){
    		merge(i);
    	}
    }
    int t,p,d;
    rep(i,m){
    	cin>>t;
    	if(t==0){
    		cout<<total<<endl;
    	}
    	else{
    		cin>>p>>d;
    		p--;
    		if(a[p]>l)
    			continue;
    		a[p]+=d;
    		if(a[p]>l){
    			total++;
    			merge(p);
    		}
    	}
    }
    return 0;
}