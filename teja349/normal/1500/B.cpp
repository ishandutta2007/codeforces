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

int ans[512345];
int a[512345],b[512345];
int pos1[1234567],pos2[1234567];

main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    int i;
    if(n<=m){
    	rep(i,n){
	    	cin>>a[i];
	    	pos1[a[i]]=i+1;
	    }
	    rep(i,m){
	    	cin>>b[i];
	    	pos2[b[i]]=i+1;
	    	ans[i]=n;
	    }
    }
    else{
    	swap(n,m);
    	rep(i,m){
	    	cin>>b[i];
	    	pos2[b[i]]=i+1;
	    	ans[i]=n;
	    }
    	rep(i,n){
	    	cin>>a[i];
	    	pos1[a[i]]=i+1;
	    }
	    
    }
    
    int val;
    rep(i,n){
    	if(pos2[a[i]]==0){
    		continue;
    	}
    	val=pos2[a[i]]-1;
    	val-=i;
    	val+=m;
    	val%=m;
    	ans[val]--;
    }
    vi vec;
    vec.pb(0);
    int gg;
    gg=ans[0];
    int cur=0;
    rep(i,2*m){
    	cur+=n;
    	cur%=m;
    	if(cur==0)
    		break;
    	vec.pb(cur);
    	gg+=ans[cur];
    }
    int round=vec.size();
    int lol=round*n;
    int low=1;
    int high=inf;
    high*=4;
    int mid,answ=-1;
    high*=inf;
    while(low<=high){
    	mid=(low+high)/2;
    	int haha=gg*(mid/lol);
    	int boo=mid%lol;
    	rep(i,vec.size()){
    		if((i+1)*n<=boo){
    			haha+=ans[ vec[i] ];
    		}
    		else{
    			break;
    		}
    	}
    	int lef = boo%n;
    	cur=vec[i];	
    	rep(i,lef){
    		if(a[i]!=b[(cur+i)%m]){
    			haha++;
    		}
    	}
    	if(haha<k){
    		low=mid+1;
    	}
    	else{
    		answ=mid;
    		high=mid-1;
    	}
    	//cout<<low<<" "<<high<<endl;
    }
    cout<<answ<<endl;
    return 0;
}