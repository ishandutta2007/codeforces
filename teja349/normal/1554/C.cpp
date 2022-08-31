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
#define int ll



int a[123],b[123];
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n,m;
    	cin>>n>>m;
    	int i;
    	if(n==0){
    		cout<<m+1<<endl;
    		continue;
    	}
    	if(m<n){
    		cout<<0<<endl;
    		continue;
    	}
    	int bitn=0;
    	int gg=n;
    	while(gg){
    		a[bitn++]=gg%2;
    		gg/=2;
    	}
    	int bitm=0;
    	gg=m;
    	while(gg){
    		b[bitm++]=gg%2;
    		gg/=2;
    	}
    	int flag=0;
    	rep(i,bitn){
    		if(b[i]==0){
    			flag=1;

    		}
    	}    	
    	if(flag==0){
    		cout<<m+1<<endl;
    		continue;	
    	}
    	int ans=0;
    	f(i,bitn,bitm){
    		ans+=(1LL<<i)*b[i];
    	}
    	rep(i,bitn){
    		if(b[i]==0){
    			break;
    		}
    	}
    	int fzero=i;
    	flag=0;
    	fd(i,bitn-1,fzero+1){
    		if(a[i]==b[i]){
    			continue;
    		}
    		if(a[i]==1){
    			flag=1;
    			break;
    		}
    		else 
    			ans+=(1LL<<i);
    	}
    	if(flag==0){
    		if(a[fzero]==0){
    			ans+=(1LL<<i);
    		}
    	}
    	cout<<ans<<endl;

    }

    return 0;
}