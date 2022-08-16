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
#define tri pair<pii , int>
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

vector<vi> vec(512345);
vector< viii > pre(512345),suffi(512345);
int poss[512345],posp[512345];
int haha[512345];
    
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
        int n,m;
        cin>>n>>m;
        string wow="";
        int flag=0;
        int lol;

        int i,j,k;
        rep(i,n){
            wow+="R";
        }

        int val;
        rep(i,n){
            rep(j,m){
                cin>>val;
                vec[i].pb(val);
            }
        }
        // pre[0].pb(mp(mp(1,1),1));
        rep(i,n){
            int mini=inf;
            int maxi=0;
            rep(j,m){
                mini=min(mini,vec[i][j]);
                maxi=max(maxi,vec[i][j]);
                pre[j].pb(mp(mp(mini,maxi),i));
            }
            mini=inf;
            maxi=0;
            fd(j,m-1,0){
                mini=min(mini,vec[i][j]);
                maxi=max(maxi,vec[i][j]);
                suffi[j].pb(mp(mp(mini,maxi),i));
            }
        }

        rep(j,m-1){
            // if(j!=2)
            //     continue;
            sort(all(pre[j]));
            sort(all(suffi[j+1]));
            int maxi=0;    
            rep(i,n-1){
                posp[i]=0;
                maxi=max(maxi,pre[j][i].ff.ss);
                if(pre[j][i+1].ff.ff>maxi){
                    posp[i]=1;
                }
            }
            maxi=0;
            rep(i,n-1){
                poss[i]=0;
                maxi=max(maxi,suffi[j+1][i].ff.ss);
                if(suffi[j+1][i+1].ff.ff>maxi){
                    poss[i]=1;
                }
            }
            rep(i,n){
                haha[i]=0;
            }
            int cnt=0;
            rep(i,n-1){
                haha[pre[j][i].ss]^=1;
                // cout<<suffi[j+1][n-1-i].ss<<endl;
                if(haha[pre[j][i].ss]){
                    cnt++;
                }
                else{
                    cnt--;
                }
                haha[suffi[j+1][n-1-i].ss]^=1;
                if(haha[suffi[j+1][n-1-i].ss])
                    cnt++;
                else
                    cnt--;
                if(posp[i] && poss[n-2-i] && cnt==0){
                    // cout<<i<<endl;
                    flag=1;
                    rep(k,i+1){
                        wow[pre[j][k].ss]='B';
                        lol = j+1;
                    }
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            cout<<wow<<" "<<lol<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }


        rep(i,n){
            vec[i].clear();
        }
        rep(i,m){
            pre[i].clear();
            suffi[i].clear();
        }

    }

    return 0;
}