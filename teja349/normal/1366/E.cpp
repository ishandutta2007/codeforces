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
int sumi[212345],dp[212345],a[212345],b[212345],pre[212345];

main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int i;
    rep(i,n){
    	cin>>a[i];
    }
    map<int,int> mapi;
    rep(i,m){
    	cin>>b[i];
    	mapi[b[i]]=i;
    }
    pre[n]=inf;
    fd(i,n-1,0){
    	pre[i]=min(pre[i+1],a[i]);
    }
    sumi[m]=1;
    fd(i,n-1,0){
    	if(mapi.find(pre[i])==mapi.end()){
    		dp[i]=0;
    		continue;
    	}
    	int gg=mapi[pre[i]];
    	dp[i]=sumi[gg+1];
    	sumi[gg]+=dp[i];
    	sumi[gg]%=mod;
    }
    if(pre[0]!=b[0])
        dp[0]=0;
    cout<<dp[0]<<endl;
    return 0;   
}