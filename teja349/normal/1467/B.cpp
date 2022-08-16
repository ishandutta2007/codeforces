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

int n,mini;

int a[312345];
int ans=0;
int check(int a,int b,int c){
    if(b<min(a,c))
        return 1;
    if(b>max(a,c))
        return 1;
    return 0;
}

int checker(int pos,int val){
    int gg = a[pos];
    if(pos!=0 && pos!=n-1){
        ans-=check(a[pos-1],a[pos],a[pos+1]);
    }
    if(pos>=2){
        ans-=check(a[pos-2],a[pos-1],a[pos]);
    }
    if(pos<=n-3){
        ans-=check(a[pos],a[pos+1],a[pos+2]);
    }

    a[pos]=val;

    if(pos!=0 && pos!=n-1){
        ans+=check(a[pos-1],a[pos],a[pos+1]);
    }
    if(pos>=2){
        ans+=check(a[pos-2],a[pos-1],a[pos]);
    }
    if(pos<=n-3){
        ans+=check(a[pos],a[pos+1],a[pos+2]);
    }

    mini=min(mini,ans);

    if(pos!=0 && pos!=n-1){
        ans-=check(a[pos-1],a[pos],a[pos+1]);
    }
    if(pos>=2){
        ans-=check(a[pos-2],a[pos-1],a[pos]);
    }
    if(pos<=n-3){
        ans-=check(a[pos],a[pos+1],a[pos+2]);
    }

    a[pos]=gg;

    if(pos!=0 && pos!=n-1){
        ans+=check(a[pos-1],a[pos],a[pos+1]);
    }
    if(pos>=2){
        ans+=check(a[pos-2],a[pos-1],a[pos]);
    }
    if(pos<=n-3){
        ans+=check(a[pos],a[pos+1],a[pos+2]);
    }

}

int trial(int pos){
    checker(pos,inf);
    checker(pos,0);
    if(pos!=0)
        checker(pos,a[pos-1]);
    if(pos!=n-1)
        checker(pos,a[pos+1]);
    if(pos!=0 && pos!=n-1 && a[pos-1]!=a[pos+1]){
        checker(pos,min(a[pos-1],a[pos+1])+1);
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
        cin>>n;
        int i;
        rep(i,n){
            cin>>a[i];
        }
        ans=0;
        f(i,1,n-1){
            ans+=check(a[i-1],a[i],a[i+1]);
        }
        mini=ans;
        rep(i,n){
            trial(i);
        }
        cout<<mini<<endl;
    }

    return 0;
}