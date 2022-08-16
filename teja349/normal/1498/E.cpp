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


int a[1234];

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin>>n;
    int i,j;
    rep(i,n){
    	cin>>a[i];
    }
    viii vec;
    rep(i,n){
    	f(j,i+1,n){
    		vec.pb(mp(abs(a[i]-a[j]),mp(i,j)));
    	}
    }
    sort(all(vec));
    int sz=vec.size();
    string s;
    int x,y;
    int flag=0;
    fd(i,sz-1,0){
    	x=vec[i].ss.ss;
    	y=vec[i].ss.ff;
    	if(a[x]<a[y])
    		swap(x,y);
    	cout<<"? "<<x+1<<" "<<y+1<<endl;
    	fflush(stdout);
    	cin>>s;
    	if(s=="Yes"){
    		flag=1;
    		break;
    	}
    }

    if(flag){
    	cout<<"! "<<x+1<<" "<<y+1<<endl;
    	fflush(stdout);
    }
    else{
    	cout<<"! "<<0<<" "<<0<<endl;
    	fflush(stdout);
    }


    return 0;
}