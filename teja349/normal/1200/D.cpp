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

int rmax[2123],rmin[2123],cmin[2123],cmax[2123];
int r[2123][2123],c[2123][2123],ar[2123][2123],ac[2123][2123];
string str[12323];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int i,j;
    rep(i,n){
    	cin>>str[i];
    }
    rep(i,n){
    	rmin[i]=inf;
    	rmax[i]=-1;
    	cmin[i]=inf;
    	cmax[i]=-1;

    }
    rep(i,n){
    	rep(j,n){
    		if(str[i][j]=='W')
    			continue;
    		rmin[i]=min(rmin[i],j);
    		rmax[i]=max(rmax[i],j);
    		cmin[j]=min(cmin[j],i);
    		cmax[j]=max(cmax[j],i);
    		
    	}
    }
    rep(i,n){
    	rep(j,n){
    		if(rmin[i]>=j && rmax[i]<j+k){
    			r[i+1][j+1]=1;
    		}
    		if(cmin[j]>=i && cmax[j]<i+k){
    			c[i+1][j+1]=1;
    		}
    		if(rmax[i]==-1)
    			ar[i+1][j+1]=1;
    		if(cmax[j]==-1)
    			ac[i+1][j+1]=1;
    		//cout<<c[i+1][j+1]<<" ";
    		//cout<<ac[i+1][j+1]<<endl;
    	}
    	//cout<<endl;

    }
    f(i,1,n+1){
    	f(j,1,n+1){
    		r[i][j]+=r[i-1][j];
    		c[i][j]+=c[i][j-1];
    		ar[i][j]+=ar[i-1][j];
    		ac[i][j]+=ac[i][j-1];
    	}
    }
    int ans=0;
    rep(i,n-k+1){
    	rep(j,n-k+1){
    		
    		ans=max(ans,r[i+k][j+1]-r[i][j+1]-(ar[i+k][j+1]-ar[i][j+1])+c[i+1][j+k]-c[i+1][j]-(ac[i+1][j+k]-ac[i+1][j]));
    		
    	}
    }
    rep(i,n){
    	if(rmax[i]==-1)
    		ans++;
    	if(cmax[i]==-1)
    		ans++;
    }
    cout<<ans<<endl;
    return 0;   
}