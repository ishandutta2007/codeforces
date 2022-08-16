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

set<int> seti;
int a[312345],b[312345];
int visit[312345][2],par[312345][2];

int bfs(int cur,int typ){
    queue<pii> que;
    que.push(mp(cur,typ));
    visit[cur][typ]=1;
    par[cur][typ]=-1;
    while(!que.empty()){
        pii papa = que.front();
        que.pop();
        int cur=papa.ff;
        int typ=papa.ss;
        if(cur==0)
            break;
        if(typ==1){
            typ^=1;
            if(!visit[cur+b[cur]][typ]){
                visit[cur+b[cur]][typ]=visit[cur][typ^1]+1;
                par[cur+b[cur]][typ]=cur;
                que.push(mp(cur+b[cur],typ));
            }
            continue;
        }
        typ^=1;
        set<int>::iterator it;
        while(1){
            it = seti.upper_bound(cur);
            if(it==seti.begin()){
                break;
            }
            it--;
            int val=*it;
            if(cur-val<=a[cur]){
                seti.erase(val);
                visit[val][typ]=visit[cur][typ^1]+1;
                par[val][typ] = cur;
                que.push(mp(val,typ));
            }
            else{
                break;
            }
        }
    }
    // cout<<visit[2][0]<<endl;
    if(visit[0][1]==0){
        cout<<-1<<endl;
        return 0;
    }
    cur=0;
    typ=1;
    vi vec;
    while(cur!=-1){
        vec.pb(cur);
        cur=par[cur][1];
        cur=par[cur][0];
    }
    cout<<vec.size()<<endl;
    int sz=vec.size();
    sz--;
    int i;
    fd(i,sz,0){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}

int main(){
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
        int n;
        cin>>n;
        int i;
        f(i,1,n+1){
            cin>>a[i];
        }
        f(i,1,n+1){
            cin>>b[i];
        }   
        rep(i,n){
            seti.insert(i);
        }
        bfs(n,0);
    }

    return 0;
}