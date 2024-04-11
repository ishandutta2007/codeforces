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

int a[123456];

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    int i;
    set<int> seti;
    multiset<int> dset;
    set<int>::iterator it;
    rep(i,n){
    	cin>>a[i];
    	seti.insert(a[i]);	
    }
    sort(a,a+n);
    int maxi=0;
    rep(i,n-1){
    	maxi=max(a[i+1]-a[i],maxi);
    	dset.insert(a[i+1]-a[i]);
    }
    cout<<a[n-1]-a[0]-maxi<<endl;
    rep(i,q){
    	int typ;
    	int val;
    	cin>>typ>>val;
    	if(typ==0){
    		it=seti.find(val);
    		int haha=0;
    		if(it!=seti.begin()){
    			it--;
    			int gg=*it;
    			haha=gg;
    			dset.erase(dset.find(val- gg));
    		}
    		it=seti.find(val);
    		it++;
    		if(it!=seti.end()){
    			int gg=*it;
    			if(haha){
    				dset.insert(gg-haha);
    			}
    			dset.erase(dset.find(gg-val));
    		}
    		seti.erase(val);
    	}
    	else{
    		seti.insert(val);
    		it=seti.find(val);
    		int haha=0;
    		if(it!=seti.begin()){
    			it--;
    			int gg=*it;
    			haha=gg;
    			dset.insert(val-gg);
    		}
    		it=seti.find(val);
    		it++;
    		if(it!=seti.end()){
    			int gg=*it;
    			if(haha)
    				dset.erase(dset.find(gg-haha));
    			dset.insert(gg-val);
    		}    	
    	}
    	if(seti.size()<=2){
    		cout<<0<<endl;
    	}
    	else{
    		it=seti.end();
    		it--;
    		int gg=*it;
    		gg-=*seti.begin();
    		multiset<int>::iterator bow;
    		bow=dset.end();
    		bow--;
    		gg-=*bow;
    		cout<<gg<<endl;
    	}

    }
    return 0;   
}