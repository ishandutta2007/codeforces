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
string s;
int rotate(int l,int r){
	int i;
	if(l==r)
		return 0;
	vec.pb(mp(l+1,r+1));
	rep(i,r-l+1){
		if(l+i<r-i){
			swap(s[l+i],s[r-i]);
		}
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n,k;
    	cin>>n>>k;
    	//string s;
    	vec.clear();
    	cin>>s;
    	int i,j=0;
    	rep(i,k-1){
    		f(j,2*i,n){
    			if(s[j]=='(')
    				break;
    		}
    		rotate(2*i,j);
    		f(j,2*i+1,n){
    			if(s[j]==')')
    				break;
    		}
    		rotate(2*i+1,j);
    	} 
    	f(i,(k-1),n/2){
    		f(j,(k-1)+i,n){
    			if(s[j]=='(')
    				break;
    		}
    		rotate((k-1)+i,j);
    	}
    	cout<<vec.size()<<endl;
    	rep(i,vec.size()){
    		cout<<vec[i].ff<<" "<<vec[i].ss<<endl;
    	}
    }
    return 0;   
}