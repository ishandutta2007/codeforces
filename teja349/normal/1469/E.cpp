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

int printans(int val,int k){
    int gg=0;
    vi vec;
    int i;
    while(val){
        vec.pb(val%2);
        gg++;
        val/=2;
    }
    rep(i,k-gg){
        cout<<"0";
    }
    fd(i,gg-1,0){
        cout<<vec[i];
    }
    cout<<endl;
    return 0;
}

int wow[(1<<20)+10];

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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int bits=1;
        int val=2;
        while(n>=val){
            val*=2;
            bits++;
        }
        int i;
        int boo = min(k,bits);
        rep(i,(1<<boo)+3){
            wow[i]=0;
        }
        int sum;
        if(k<=bits){
            int lol=(1<<k);
            lol--;
            sum=0;
            rep(i,n){
                if(i>=k){
                    sum%=(1<<(k-1));
                }
                sum*=2;
                sum+=s[i]-'0';
                if(i>=k-1){
                    wow[sum^lol]=1;
                }
            }
            int flag=0;
            rep(i,(1<<k)){
                if(wow[i]==0){
                    flag=1;
                    break;
                }
            }
            if(flag){
                cout<<"YES"<<endl;
                printans(i,k);
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            int lol=(1<<bits);
            lol--;
            sum=0;
            int cnt=0;
            int lefover=k-bits;
            rep(i,n){
                if(i>=k){
                    if(s[i-k]=='0')
                        cnt--;
                }
                if(i>=bits){
                    if(s[i-bits]=='0')
                        cnt++;
                }
                if(i>=bits){
                    sum%=(1<<(bits-1));
                }
                sum*=2;
                sum+=s[i]-'0';
                if(i>=k-1 && cnt==0){
                    wow[sum^lol]=1;
                }
            }
            int flag=0;
            rep(i,(1<<bits)){
                if(wow[i]==0){
                    flag=1;
                    break;
                }
            }
            if(flag){
                cout<<"YES"<<endl;
                printans(i,k);
            }
            else{
                cout<<"NO"<<endl;
            }
        }

    }

    return 0;
}