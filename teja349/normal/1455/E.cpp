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

#define int ll
// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int x[12],y[12];
int a[12];

main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int i,j,k;
    	rep(i,4){
    		cin>>x[i]>>y[i];
    	}
    	rep(i,4){
    		a[i]=i;
    	}
    	int mini=inf;
    	mini*=inf;
    	int turns=0;
    	rep(i,4){
    		rep(j,4){
    			int valx,valy;
    			valx=x[i];
    			valy=y[j];
    			sort(a,a+4);
    			while(1){
    				int gg=abs(valx-x[a[0]])+abs(valy-y[a[0]]);
   					gg+=abs(valy-y[a[1]]);
   					gg+=abs(valx-x[a[3]]);
   					vi vec;
   					vec.pb(x[a[1]]-valx);
   					vec.pb(x[a[2]]-valx);
   					vec.pb(y[a[2]]-valy);
   					vec.pb(y[a[3]]-valy);
   					sort(all(vec));
   					int val=vec[1];
   					rep(k,4){
   						gg+=abs(vec[k]-val);
   					}
   					//cout<<gg<<endl;
   					mini=min(mini,gg);
    				// if(turns==12){
    				// 	cout<<valx<<" "<<valy<<" "<<val<<endl;
    				// 	rep(k,4){
    				// 		cout<<x[a[k]]<<" "<<y[a[k]]<<endl;
    				// 	}
    				// 	gg=abs(valx-x[a[0]])+abs(valy-y[a[0]]);
   					// gg+=abs(valy-y[a[1]]);
   					// gg+=abs(valx-x[a[3]]);
   					// cout<<gg<<endl;
    				// 	exit(0);
    				// }
    				turns++;
    				if(!next_permutation(a,a+4)){
    					break;
    				}
    			}
    			
    		}
    	}
    	cout<<mini<<endl;
    }
    return 0;
}