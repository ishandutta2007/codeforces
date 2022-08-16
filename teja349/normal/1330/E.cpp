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

int a[5123456];

int h,g;
int update(int cur,int lev){
	int boo = a[cur];
	a[cur]=max(a[cur*2],a[cur*2+1]);

	if(a[cur]==0){
		if(lev<g){
			a[cur]=boo;
			return 0;
		}
		return 1;
	}
	int val;
	if(a[2*cur]>a[2*cur+1]){
		val=update(2*cur,lev+1);
	}
	else{
		val=update(2*cur+1,lev+1);
	}
	if(val==0){
		a[cur]=boo;
	}
	return val;
}

ll query(int cur){
	ll ans=a[cur];
	if(a[cur]!=0){
		ans+=query(cur*2)+query(2*cur+1);
	}

	// cout<<cur<<" "<<a[cur]<<endl;
	return ans;
}

// int build(int cur, int lev){
// 	if(lev>=g){
// 		exp[cur]=0;
// 	}
// 	else{
// 		exp[cur]=(1<<(g-1-lev));
// 	}
// 	gg[cur]=(1<<(h-1-lev));
// 	if(lev==h-1){
// 		break;
// 	}
// 	build(2*cur,lev+1);
// 	build(2*cur+1,lev+1);
// }

vi vec;
int solve(int cur,int lev){
	if(a[cur]==0)
		return 0;
	while(1){
		if(update(cur,lev)==0)
			break;
		vec.pb(cur);
	}
	lev++;
	solve(2*cur,lev);
	solve(2*cur+1,lev);
	return 0;
}


main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	//int h,g;
    	vec.clear();
    	cin>>h>>g;
    	int i;
    	int n=(1<<h);
    	f(i,1,n){
    		cin>>a[i];
    	}
    	int req=(1<<g);
    	int cur=1;
    	int lev=0;
    	solve(1,0);
    	cout<<query(1)<<endl;
    	
    	rep(i,vec.size()){
    		cout<<vec[i]<<" ";
    	}
    	cout<<endl;

    	f(i,1,n+1){
    		a[i]=0;
    	}
    }
    return 0;
}