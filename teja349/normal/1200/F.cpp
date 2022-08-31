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

int states = 2520;
int visit[2522000];
int nex[2522000];
vector<vi> adj(2522000);
vi vec;
int bush[1234];
int n;
int findcycle(int u){
    int len=0;
    if(visit[u]){
        int i;
        fd(i,vec.size()-1,0){
            if(bush[vec[i]/states]==0){
                len++;
                bush[vec[i]/states]=1;
            }
            if(vec[i]==u)
                break;
        }
        fd(i,vec.size()-1,0){
            bush[vec[i]/states]=0;
            if(vec[i]==u)
                break;
        }
        return len;
    }
    vec.pb(u);
    visit[u]=1;
    int val=findcycle(nex[u]);
    visit[u]=0;
    return val;
}
int k[1234],m[1234],e[1234][12];
int dfs(int u,int len){
    if(len==0){
        exit(0);
    }
    visit[u]=len;
    int i;
    rep(i,adj[u].size()){
        if(!visit[adj[u][i]]){
            dfs(adj[u][i],len);
        }
    }
    return 0;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin>>n;
    int i,j;
    rep(i,n){
        cin>>k[i];
        k[i]%=states;
        if(k[i]<0)
            k[i]+=states;
    }
    rep(i,n){
        cin>>m[i];
        rep(j,m[i]){
            cin>>e[i][j];
            e[i][j]--;
        }
    }
    int val,haha;
    rep(i,n){
        val=i*states;
        rep(j,states){
            haha=j+k[i];
            haha%=states;
            if(haha<0){
                assert(0);
                haha+=states;
            }
            nex[val+j] = e[i][haha%m[i]]*states+haha;
            adj[val+j].pb(e[i][haha%m[i]]*states+haha);
            adj[e[i][haha%m[i]]*states+haha].pb(val+j);
        }
    }
    int len;
    rep(i,states*n){
        if(!visit[i]){
            vec.clear();
            len = findcycle(i);
            //cout<<len<<endl;
            //return 0;
            dfs(i,len);
        }
    }
    //return 0;
    int q;
    cin>>q;
    int x,y;
    while(q--){
        int x,y;
        cin>>x>>y;
        x--;
        y%=states;
        if(y<0)
            y+=states;
        //cout<<x*states+y<<" "<<nex[x*states+y]<<endl;
        cout<<visit[x*states+y]<<endl;
    }
    return 0;   
}