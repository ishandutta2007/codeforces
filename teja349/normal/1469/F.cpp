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
#define pdqueue priority_queue< pii,vii ,greater< pii > >
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

int l[212345];
int n,k;
int solve(int x){
    pdqueue pq;
    pq.push(mp(0,0));
    int sofar=1;
    int i;
    rep(i,n){
        pii val = pq.top();
        if(val.ff==x-1){
            break;
        }
        sofar--;
        pq.pop();
        val.ff++;
        if(val.ff<=val.ss){
            pq.push(val);
        }
        int l1=(l[i]-1)/2;
        int l2=l[i]-1-l1;
        int curpos=val.ff;
        curpos++;
        int endpos=min(curpos+l1-1,x);
        if(curpos<=endpos){
            sofar+=endpos-curpos+1;
            pq.push(mp(curpos,endpos));
        }
        endpos=min(curpos+l2-1,x);
        if(curpos<=endpos){
            sofar+=endpos-curpos+1;
            pq.push(mp(curpos,endpos));
        }
        if(sofar>=k){
            return 1;
        }
    }
    return 0;

}

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
    	//cout<<"Case #"<<t1-t<<": ";
        
        cin>>n>>k;
        int i,sumi=0;
        rep(i,n){
            cin>>l[i];
            sumi+=l[i];
            l[i]*=-1;
        }
        sort(l,l+n);
        rep(i,n){
            l[i]*=-1;
        }
        if(sumi+1-2*n<k){
            cout<<-1<<endl;
            return 0;
        }
        int low=1;
        int high=inf;
        int ans=0;
        high*=10000;
        while(low<=high){
            int mid=(low+high)/2;
            int val=solve(mid);
            if(val){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}