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

int a[1234567];

main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i,j;
    ll sumi=0;
    rep(i,n){
    	cin>>a[i];
    	sumi+=a[i];
    }
    if(sumi==1){
    	cout<<-1<<endl;
    	return 0;
    }
    ll dum=sumi;
    vi fact;
    for(i=2;i<1234567;i++){
    	if(dum%i==0){
    		fact.pb(i);
    	}
    	while(dum%i==0){
    		dum/=i;
    	}
    	if(dum==1)
    		break;
    }
    if(dum!=1){
    	fact.pb(dum);
    }
    int mini=inf;
    mini*=inf;
    rep(j,fact.size()){
    	int val=(fact[j]+1)/2;
    	int ans=0,sofar=0,gg=0,sum1=0;
    	sumi=0;
    	rep(i,n){
    		sum1=sumi;
    		gg=sofar;
    		sumi+=a[i];
    		sofar+=a[i]*i;
    		if(sum1<0 && sumi>=0){
    			ans+=gg-sum1*i;
    			sofar=sumi*i;
    			sum1=0;
    			gg=0;
    		}
    		while(sumi>=val){
    			ans+=sum1*i-gg;
    			sumi-=val;
    			if(sumi>=fact[j]-val){
    				sumi-=fact[j]-val;
    				sumi%=fact[j];
    				sofar=sumi*i;
    				sum1=0;
    				gg=0;
    			}
    			else{
    				ans-=(fact[j]-val-sumi)*i;
    				sumi-=(fact[j]-val);
    				sofar=0;
    			}
    		}
    	}	
    	mini=min(mini,ans);
    }
    cout<<mini<<endl;
    return 0;   
}