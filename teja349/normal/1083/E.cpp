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


// max convex hull
vector <long long int> mvals, bvals;
int cur = 0;

// Suppose the last 3 lines added are : (l1, l2, l3)
// Line l2 becomes irrelevant, if l1/l3 x-intersection is to the left of l1/l2 x-intersection
bool bad(long long int m1, long long int b1, long long int m2, long long int b2, long long int m3, long long int b3) {
    // Cast to double to avoid long long int overflow
    return 1.0 * (b1 - b3)/(m3 - m1) < 1.0 * (b1 - b2)/(m2 - m1);
}

void add(long long int m, long long int b) {
    while ( (int) mvals.size() >= 2 && bad(mvals[mvals.size() - 2], bvals[bvals.size() - 2], mvals[mvals.size() - 1], bvals[bvals.size() - 1], m, b)) {
        mvals.pop_back(); bvals.pop_back();
    }
    mvals.push_back(m); bvals.push_back(b);
}

void setCur(long long int x) {
    if (cur > (int) mvals.size() - 1)
        cur = (int) mvals.size() - 1;
    // Best-line pointer goes to the right only when queries are non-decreasing (x argument grows)
    while (cur < (int) mvals.size() - 1 && 1.0 * mvals[cur + 1] * x + bvals[cur + 1] >= 1.0 * mvals[cur] * x + bvals[cur])
        cur++;
}

// for answer at x, do setcur(x) and ans = mvals[cur]*x+bvals[cur];

struct total{
	ll x,y,a;
};
total gg[1234567];
ll dp[1234567];
int comp(total p,total q){
	return p.x<q.x;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n;
  	cin>>n;
  	int i;
  	
  	rep(i,n){
  		cin>>gg[i].x>>gg[i].y>>gg[i].a;
  	}
  	sort(gg,gg+n,comp);
  	//add(0,0);
  	i=0;
  	ll wow=0;
  	add(0,0);
  	f(i,0,n){
  		gg[i].y*=-1;
  		setCur(gg[i].y);
  		//cout<<gg[i].y<<endl;
  		dp[i]=mvals[cur]*gg[i].y+bvals[cur];
  		//cout<<dp[i]<<endl;
  		dp[i]-=gg[i].x*gg[i].y;
  		dp[i]-=gg[i].a;
  		wow=max(wow,gg[i].x*gg[i].y-gg[i].a);
  		wow=max(wow,dp[i]);
  		if(dp[i]>0)
  			add(gg[i].x,dp[i]);
  		//cout<<gg[i].x<<" "<<dp[i]<<endl;
  	}
  	cout<<wow<<endl;
    return 0;   
}