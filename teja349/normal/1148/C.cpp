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

vii vec;
int p[312345],pos[312345];

int doswap(int p1,int p2){
	vec.pb(mp(p1,p2));
	swap(p[p1],p[p2]);
	swap(pos[p[p1]],pos[p[p2]]);
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    f(i,1,n+1){
    	cin>>p[i];
    	pos[p[i]]=i;
    }
    f(i,2,n/2+1){
    	if(pos[i]>n/2){
    		doswap(1,pos[i]);
    	}
    	doswap(pos[i],n);
    	doswap(pos[i],i);
    }
    f(i,n/2+1,n+1){
    	if(pos[i]>n/2){
    		doswap(1,pos[i]);
    	}
    	doswap(pos[i],i);
    }
    cout<<vec.size()<<endl;
    rep(i,vec.size()){
    	cout<<vec[i].ff<<" "<<vec[i].ss<<endl;
    }

    return 0;   
}