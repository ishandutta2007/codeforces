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

set<int> seti;
vi vec;
int a[123456];

int solve(int s,int e){
	if(a[s]==a[e]){
		seti.insert(a[s]*(e-s+1));
		return a[s]*(e-s+1);
	}
	int mid=(a[s]+a[e])/2;
	int posi=upper_bound(all(vec),mid)-vec.begin();
	int val1=solve(s,posi-1);
	int val2= solve(posi,e);
	
	seti.insert(val1+val2);
	return val1+val2;
}

main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n,m;
    	cin>>n>>m;
    	int i;
    	seti.clear();
    	vec.clear();
    	rep(i,n){
    		cin>>a[i];
    		vec.pb(a[i]);
    	}
    	sort(a,a+n);
    	sort(all(vec));
    	solve(0,n-1);
    	int val;
    	rep(i,m){
    		cin>>val;
    		if(seti.find(val)!=seti.end()){
    			cout<<"Yes"<<endl;
    		}
    		else{
    			cout<<"No"<<endl;
    		}
    	}
    }

    return 0;
}