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
#define mod (998244353)
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

int powe[512][512];
int dp[512][512];
int comb[512][512];
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
        int n,x;
        cin>>n>>x;
        int i,j;
        rep(i,512){
            powe[i][0]=1;
            f(j,1,512){
                powe[i][j]=powe[i][j-1]*i;
                powe[i][j]%=mod;
            }
        }
        rep(i,512){
            comb[i][0]=1;
            f(j,1,i+1){
                comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
                comb[i][j]%=mod;
            }
        }
        rep(j,n+1){
            dp[1][j]=1;
        }
        dp[1][1]=0;
        int k;
        f(i,2,x+1){
            dp[i][0]=1;
            dp[i][1]=0;
            f(j,2,n+1){
                int las = i-(j-1);
                if(las<=0){
                    dp[i][j]=powe[i][j];
                    continue;
                }
                rep(k,j+1){
                    int val=dp[las][k]*powe[j-1][j-k];
                    val%=mod;
                    val*=comb[j][k];
                    dp[i][j]+=val;
                    dp[i][j]%=mod;
                }
            }
        }
        cout<<dp[x][n]<<endl;
    }

    return 0;
}