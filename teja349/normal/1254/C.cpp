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

int query(int typ,int i,int j,int k){
	cout<<typ<<" "<<i<<" "<<j<<" "<<k<<endl;
	fflush(stdout);
	int x;
	cin>>x;
	return x;
}
int area[1234];
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int mini=2;
    int i,val;
    f(i,3,n+1){
    	val=query(2,1,mini,i);
    	if(val<0)
    		mini=i;
    }
    int curmax=-1,posi;
    f(i,2,n+1){
    	if(i==mini){
    		continue;
    	}
    	area[i]=query(1,1,mini,i);
    	if(area[i]>curmax){
    		curmax=area[i];
    		posi=i;
    	}
    }
    int top=posi;
    deque<int> ans;
    ans.push_back(top);
    vii vec;
    f(i,2,n+1){
    	if(i==mini || i==top)
    		continue;
    	vec.pb(mp(area[i],i));
    }
    sort(all(vec));
    int sz=vec.size();
    fd(i,sz-1,0){
    	val=query(2,1,vec[i].ss,top);
    	if(val>0)
    		ans.push_back(vec[i].ss);
    	else
    		ans.push_front(vec[i].ss);
    }
    ans.push_back(mini);
    ans.push_back(1);
    cout<<0<<" ";
    fd(i,n-1,0){
    	cout<<ans.at(i)<<" ";
    }
    cout<<endl;
    fflush(stdout);
    return 0;   
}