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
//#define int ll
map<int,int> mapi;
int a[212345],b[212345];
int sumi[212345];
int val=90,n;
ll solve(){
	int i;
	sumi[0]=0;
	rep(i,n){
		sumi[i+1]=sumi[i]+b[i];
	}
	mapi.clear();
	mapi[0]++;
	ll ans=0;
	f(i,1,n+1){
		ans+=mapi[sumi[i]];
		mapi[sumi[i]]++;
	}
	return ans;
}
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin>>s;
    n=s.length();
    
    int i,j;
    rep(i,n){
    	a[i]=s[i]-'0';
    }
    ll ans=0;
    f(i,1,val+1){
    	rep(j,n){
    		if(a[j]==1){
    			b[j]=-1*(i-1);
    		}
    		else{
    			b[j]=1;
    		}
    	}
    	ans+=solve();
    }
    int nexti=0;
    vi vec;
    rep(i,n){
    	b[i]=nexti;
    	if(a[i]==1){
    		vec.pb(i);
    		nexti++;
    	}
    }
    int sz=vec.size();
    vec.pb(n);
    int left=n/val;
    int haha,gg;
    rep(i,n){
    	f(j,1,left+3){
    		if(b[i]+j-1>=sz){
    			break;
    		}
    		haha=vec[b[i]+j-1];
    		gg=vec[b[i]+j];
    		gg--;
    		haha-=(i-1);
    		gg-=(i-1);
    		haha=max(haha,val*j+1);
    		if(gg<haha)
    			continue;
    		ans+=gg/j-(haha-1)/j;
    	}
    }
    cout<<ans<<endl;
    return 0;   
}