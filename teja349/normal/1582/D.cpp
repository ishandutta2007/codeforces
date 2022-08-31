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

int VAL=12345;

int a[123456],b[123456];
vector<vi> vec(123456);
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
 //    rlimit R;
	// getrlimit(RLIMIT_STACK, &R);
	// R.rlim_cur = R.rlim_max;
	// setrlimit(RLIMIT_STACK, &R);
    int t=1;
    cin>>t;
    int t1=t;
    while(t--){
    	// cout<<"Case #"<<t1-t<<": ";
        int n;
        cin>>n;
        int i;
        rep(i,2*VAL+10){
            vec[i].clear();
        }
        rep(i,n){
            cin>>a[i];
            if(i>=2){
                vec[a[i]+VAL].pb(i);
            }
        }
        int j;
        vi lol;
        
        lol.pb(0);
        lol.pb(1);
        f(i,-1*VAL,0){
            int sz1=vec[i+VAL].size();
            int sz2=vec[VAL-i].size();
            int gg=min(sz1,sz2);
            rep(j,gg){
                b[vec[i+VAL][j]]=1;
                b[vec[VAL-i][j]]=1;
            }
            f(j,gg,sz1){
                lol.pb(vec[i+VAL][j]);
            }
            f(j,gg,sz2){
                lol.pb(vec[VAL-i][j]);
            }
        }
        int sz=lol.size();
        // rep(i,lol.size()){
        //     cout<<lol[i]<<endl;
        // }
        if(sz%2==1){
            i=3;
            if(a[lol[0]]+a[lol[1]]==0){
                if(a[lol[0]]+a[lol[2]]==0){
                    swap(lol[0],lol[2]);
                }
                else{
                    swap(lol[1],lol[2]);
                }
            }
            // cout<<lol[0]<<" "<<lol[1]<<" "<<lol[2]<<endl;
            b[lol[0]]=a[lol[2]];
            b[lol[1]]=a[lol[2]];
            b[lol[2]]=-1*(a[lol[0]]+a[lol[1]]);
        }
        else{
            i=0;
        }
        while(i<sz){
            b[lol[i]]=a[lol[i+1]];
            b[lol[i+1]]=-1*a[lol[i]];
            i+=2;
        }
        int sumi=0;
        rep(i,n){
            // assert(b[i]!=0);
            // sumi+=a[i]*b[i];
            cout<<b[i]<<" ";
        }
        // assert(sumi==0);
        cout<<endl;


    }

    return 0;
}