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

int s[5123];
int tot[5123];
int f[5123],h[5123];
int lef[5123],rig[5123];
int rigm[5123],lefm[5123];
int meetl[5123],meetr[5123];
int cowcnt[5123];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int i,j;
    rep(i,n){
    	cin>>s[i];
    	tot[s[i]]++;
    }
    j=0;
    vi vec;
    rep(i,m){
    	cin>>f[j]>>h[j];
    	if(tot[f[j]]<h[j])
    		continue;
    	vec.pb(f[j]);
    	cowcnt[f[j]]++;
    	j++;	
    }
    sort(all(vec));
    vec.resize(unique(all(vec))-vec.begin());
    m=j;
    int cow,cur;
    rep(i,5123){
    	rig[i]=-1;
    	lef[i]=-1;
    }
    int gg=0;
    rep(i,m){
    	gg=0;
    	rep(j,n){
    		if(s[j]==f[i]){
    			gg++;
    		}
    		if(gg==h[i]){
    			break;
    		}
    	}
    	meetl[i]=j;
    	lef[j]=i;
    	gg=0;
    	fd(j,n-1,0){
    		if(s[j]==f[i]){
    			gg++;
    		}
    		if(gg==h[i]){
    			break;
    		}
    	}
    	meetr[i]=j;
    	rig[j]=i;
    }
    rep(i,n){
    	if(rig[i]!=-1)
    		rigm[s[i]]++;
    }
    int maxt=0;
    ll totways=0;
    int tot=0;
    ll ways=0;
    ll val1,val2;
    rep(i,n){
    	if(rig[i]!=-1)
    		rigm[s[i]]--;
    	if(lef[i]==-1){
    		continue;
    	}
    	lefm[s[i]]++;
    	cow=lef[i];
    	tot=1;
    	ways=1;
    	int hoho=0;
    	if(meetr[cow]>i)
    		hoho=1;
    	if(rigm[f[cow]]-hoho>0){
    		tot++;
    		ways*=(rigm[f[cow]]-hoho);
    		ways%=mod;
    	}
    	rep(j,vec.size()){
    		if(vec[j]==f[cow])
    			continue;
    		cur=vec[j];
    		val1=lefm[cur];
    		val2=rigm[cur];
    		if(val1<val2){
    			swap(val1,val2);	
    		}
    		if(val2==0){
    			if(val1==0){
    				continue;
    			}
    			tot++;
    			ways*=val1;
    			ways%=mod;
    			continue;
    		}
    		else if(val1>=2){
    			//assert(val2!=0);
    			tot+=2;
    			ways*=(val2*(val1-1));
    			ways%=mod;
    		}
    		else{
    			// assert(val1==val2);
    			// assert(val1==1);
    			tot++;
    			ways*=2;
    			ways%=mod;
    		}
    		
    	}
    	if(maxt==tot){
    		totways+=ways;
    		totways%=mod;
    	}
    	else if(maxt<tot){
    		maxt=tot;
    		totways=ways;
    	}
    }
    if(maxt==vec.size()){
    	ll foo=1;
    	rep(i,vec.size()){
    		foo*=cowcnt[vec[i]];
    		foo%=mod;
    	}
    	totways+=foo;
    	totways%=mod;
    }
    totways%=mod;
    cout<<maxt<<" "<<totways<<endl;

    return 0;   
}