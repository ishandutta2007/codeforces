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
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 candy.cpp


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

int lol[1234567],c[312345],d[312345],h[312345],D[312345],H[312345];
int ans[312345];
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
 //    rlimit R;
	// getrlimit(RLIMIT_STACK, &R);
	// R.rlim_cur = R.rlim_max;
	// setrlimit(RLIMIT_STACK, &R);
    int t=1;
    // cin>>t;
    int t1=t;
    while(t--){
    	// cout<<"Case #"<<t1-t<<": ";
        int n,C;
        cin>>n>>C;
        int i;
        rep(i,C+1){
            lol[i]=-1;
        }
        rep(i,n){
            cin>>c[i]>>d[i]>>h[i];
            if(lol[c[i]]==-1)
                lol[c[i]]=d[i]*h[i];
            else
                lol[c[i]]=max(lol[c[i]],d[i]*h[i]);
        }
        int m;
        cin>>m;
        vii vec;
        rep(i,m){
            cin>>D[i]>>H[i];
            vec.pb(mp(D[i]*H[i],i));
            ans[i]=-1;
        }
        int j;
        sort(all(vec));
        f(i,1,C){
            for(j=1;j*i<=C;j++){
                lol[j*i]=max(lol[j*i],j*lol[i]);
            }
        }
        j=1;
        rep(i,m){
            while(j<=C && lol[j]<=vec[i].ff){
                j++;
            }
            if(j>C)
                break;
            ans[vec[i].ss]=j;
        }
        rep(i,m){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }

    return 0;
}