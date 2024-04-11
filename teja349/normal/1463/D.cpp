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

int b[512345],gg[512345],haha[512345],mini[512345],maxi[512345];

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
 //    rlimit R;
	// getrlimit(RLIMIT_STACK, &R);
	// R.rlim_cur = R.rlim_max;
	// setrlimit(RLIMIT_STACK, &R);
    int t;
    cin>>t;
    int t1=t;
    while(t--){
    	//cout<<"Case #"<<t1-t<<": ";
        int n;
        cin>>n;
        int i;
        rep(i,2*n+10){
            gg[i]=0;
        }
        rep(i,n){
            cin>>b[i];
            gg[b[i]]=1;
        }
        int counter=0;
        vi vec;
        f(i,1,2*n+1){
            if(gg[i])
                continue;
            haha[counter++]=i;
            vec.pb(i);
        }
        int cnt=0;
        rep(i,n){
            mini[i]=0;
            maxi[i]=0;
            int ind = lower_bound(all(vec),b[i])-vec.begin();
            mini[i]=n-ind;
            maxi[i]=ind;
           // cout<<mini[i]<<" "<<maxi[i]<<endl;
        }

        f(i,1,n){
            mini[i]=min(mini[i],mini[i-1]-1);
        }
        fd(i,n-2,0){
            maxi[i]=min(maxi[i],maxi[i+1]-1);
        }
        if(maxi[0]>0)
            cnt++;
        if(mini[n-1]>0)
            cnt++;
        rep(i,n-1){
            if(mini[i]>0 && maxi[i+1]>0)
                cnt++;
        }
        cout<<cnt<<endl;

    }

    return 0;
}