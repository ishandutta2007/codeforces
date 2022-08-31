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

const int N=1e7+100;
int p[N];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    ll i,j;
    for(i=2;i<1e7+3;i++){
    	if(p[i])
    		continue;
    	p[i]=i;
    	for(j=i*i;j<1e7+3;j+=i){
    		if(p[j]==0)
    			p[j]=i;
    	}
    }
    int val1,val;
    vi vec1,vec2;
    rep(i,n){
    	cin>>val1;
    	val=val1;
    	int cur=p[val];
    	int sec=-1;
    	while(val!=1){
    		if(cur!=p[val]){
    			sec=p[val];
    			break;
    		}
    		val/=p[val];
    	}
    	if(sec!=-1){
    		if(val1%2){
    			vec1.pb(cur);
    			vec2.pb(sec);
    		}
    		else{
    			vec1.pb(val);
    			vec2.pb(2);
    		}
    	}
    	else{
    		vec1.pb(-1);
    		vec2.pb(-1);
    	}
    }
    rep(i,n){
    	cout<<vec1[i]<<" ";
    }
    cout<<endl;
    rep(i,n){
    	cout<<vec2[i]<<" ";
    }
    return 0;   
}