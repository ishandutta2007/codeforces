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
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000

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
#define mod (998244353)
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

int pre[212345];
int a[212345],b[212345];
int powi(int p,int q){
	int ans=1;
	while(q){
		if(q%2){
			ans*=p;
			ans%=mod;
		}
		q/=2;
		p*=p;
		p%=mod;
	}
	return ans;
}
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int i;
    vi d;
    int val;
    rep(i,n){
    	cin>>val;
    	d.pb(val);
    }
    rep(i,m){
    	cin>>a[i]>>b[i];
    }
    sort(all(d));
    int sumi=0;
    rep(i,n){
    	sumi+=d[i];
    	pre[i]=sumi;
    }
    rep(i,m){
    	int posi=lower_bound(all(d),b[i])-d.begin();
    	int lef = n-posi;
    	if(lef<a[i]){
    		cout<<0<<endl;
    		continue;
    	}
    	ll ans;
    	ans=(lef+1-a[i])*powi(lef+1,mod-2);
    	ans%=mod;
    	ll haha=0;
    	if(posi!=0){
    		haha=pre[posi-1];
    	}
    	haha%=mod;
    	ans*=haha;
    	ans%=mod;
    	ll gg=ans;
    	ans=(lef-a[i])*powi(lef,mod-2);
    	ans%=mod;
    	haha=sumi-haha;
    	haha%=mod;
    	ans*=haha;
    	ans%=mod;
    	gg+=ans;
    	gg%=mod;
    	cout<<gg<<endl;
    }
    return 0;   
}