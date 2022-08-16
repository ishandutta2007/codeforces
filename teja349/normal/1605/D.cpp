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

int dep[212345];
vector<vi> adj(212345);
int used[212345];
int dfs(int cur,int par){
    int i;
    if(par!=-1)
        dep[cur]=dep[par]+1;
    else
        dep[cur]=0;
    // cout<<cur<<" "<<dep[cur]<<endl;
    rep(i,adj[cur].size()){
        if(adj[cur][i]==par)
        continue;
        dfs(adj[cur][i],cur);
    }
    return 0;
}
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
    	// cout<<"Case #"<<t1-t<<": ";
        int n;
        cin>>n;
        int i;
        int u,v;
        int j;
        rep(i,n+3){
            adj[i].clear();
            used[i]=0;
        }
        rep(i,n-1){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1,-1);
        int ev=0;
        f(i,1,n+1){
            if(dep[i]%2==0)
                ev++;
        }
        int od=n-ev;
        int haha=min(od,ev);
        int val=1;
        int wow=n;
        vi vec;
        while(val<=wow){
            vec.pb(val);
            wow-=val;
            val*=2;
        }
        int sz=vec.size();
        vi lol;
        // cout<<ev<<endl;
        fd(i,sz-1,0){
            if(vec[i]<=haha){
                rep(j,vec[i]){
                    used[vec[i]+j]=1;
                    lol.pb(vec[i]+j);
                }
                haha-=vec[i];
            }
        }
        vi foo;
        f(i,1,n+1){
            if(!used[i])
                foo.pb(i);
        }
        int p=0,q=0;
        assert(haha==0);
        f(i,1,n+1){
            if(ev<=od){
                if(dep[i]%2==0){
                    cout<<lol[p++]<<" ";
                }
                else{
                    cout<<foo[q++]<<" ";
                }
            }
            else{
                if(dep[i]%2==1){
                    cout<<lol[p++]<<" ";
                }
                else{
                    cout<<foo[q++]<<" ";
                }
            }
        }
        cout<<endl;

    }

    return 0;
}