//teja349
#include <bits/stdc++.h>
// #include <sys/resource.h>
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

int a[212345];
int b[212345];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
 //    rlimit R;
	// getrlimit(RLIMIT_STACK, &R);
	// R.rlim_cur = R.rlim_max;
	// setrlimit(RLIMIT_STACK, &R);
    int t=1;
    cin>>t;
    int t1=t;
    while(t--){
    	//cout<<"Case #"<<t1-t<<": ";
        vii vec;
        int n;
        cin>>n;

        int i;
        rep(i,n+5){
            a[i]=0;
        }
        int val=n;
        while(val>2){
            a[val]=1;
            val=ceil(sqrt(val));
        }
        f(i,3,n){
            if(a[i])
                continue;
            vec.pb(mp(i,n));
        }
        val=n;
        int haha;
        while(val>2){
            a[val]=1;
            haha=ceil(sqrt(val));
            vec.pb(mp(val,haha));
            vec.pb(mp(val,haha));
            val=haha;
        }
        cout<<vec.size()<<endl;
        rep(i,vec.size()){
            cout<<vec[i].ff<<" "<<vec[i].ss<<endl;
        }
        // f(i,1,n+1){
        //     b[i]=i;
        // }
        // rep(i,vec.size()){
        //     int gg = b[vec[i].ff]/b[vec[i].ss];
        //     if(b[vec[i].ff]%b[vec[i].ss]){
        //         gg++;
        //     }
        //     b[vec[i].ff]=gg;
        // }
        // f(i,3,n+1){
        //     assert(b[i]==1);
        // }
        // assert(b[1]==1);
        // assert(b[2]==2);
    }

    return 0;
}